#include <iostream>     // Entrada e saída padrão
#include <vector>       // Vetores dinâmicos
#include <list>         // Listas encadeadas
#include <string>       // Manipulação de strings
#include <fstream>      // Leitura de arquivos
#include <sstream>      // Conversão de strings

using namespace std;

// Tamanho fixo do primeiro nível da tabela hash
const int TAM_NIVEL1 = 10;

// Estrutura de objeto com chave e valor
struct Objeto {
    int chave;
    string valor;

    Objeto(int c, string v) : chave(c), valor(v) {}
};

// Classe da Tabela Hash com encadeamento separado duplo
class TabelaHashDupla {
private:
    int n; // Número total de objetos
    vector<vector<list<Objeto>>> tabela;

    // Função hash do primeiro nível
    int hash1(int chave) {
        return chave % TAM_NIVEL1;
    }

    // Função hash do segundo nível
    int hash2(int chave) {
        return (chave / 10) % (n / 10);
    }

public:
    // Construtor
    TabelaHashDupla(int totalObjetos) : n(totalObjetos) {
        tabela.resize(TAM_NIVEL1);
        for (int i = 0; i < TAM_NIVEL1; i++) {
            tabela[i].resize(n / 10);
        }
    }

    // Método de inserção
    void inserir(int chave, string valor) {
        int idx1 = hash1(chave);
        int idx2 = hash2(chave);

        for (auto& obj : tabela[idx1][idx2]) {
            if (obj.chave == chave) {
                cout << "Chave " << chave << " já existe!\n";
                return;
            }
        }

        tabela[idx1][idx2].push_back(Objeto(chave, valor));
        cout << "Objeto " << valor << " inserido na tabela[" << idx1 << "][" << idx2 << "]\n";
    }

    // Método de busca
    Objeto* buscar(int chave) {
        int idx1 = hash1(chave);
        int idx2 = hash2(chave);

        for (auto& obj : tabela[idx1][idx2]) {
            if (obj.chave == chave) {
                return &obj;
            }
        }
        return nullptr;
    }
};

// Função principal que recebe o nome do arquivo como argumento
int main(int argc, char* argv[]) {
    // Verifica se o nome do arquivo foi passado como argumento
    if (argc < 2) {
        cout << "Uso: " << argv[0] << " arquivo.txt\n";
        return 1;
    }

    // Abre o arquivo informado
    ifstream arquivo(argv[1]);

    // Verifica se o arquivo foi aberto corretamente
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo.\n";
        return 1;
    }

    int totalObjetos;
    arquivo >> totalObjetos; // Lê a primeira linha: número total de objetos

    // Cria a tabela com base na quantidade lida
    TabelaHashDupla tabela(totalObjetos);

    int chave;
    int contador = 1;
    while (arquivo >> chave) {
        // Cria um nome genérico para o valor, como "Objeto1", "Objeto2", etc.
        string nome = "Objeto" + to_string(contador++);
        tabela.inserir(chave, nome);
    }

    arquivo.close(); // Fecha o arquivo

    // Exemplo de busca ao final (opcional)
    int chaveBusca = 33;
    Objeto* encontrado = tabela.buscar(chaveBusca);
    if (encontrado) {
        cout << "Busca: Objeto com chave " << chaveBusca << " = " << encontrado->valor << "\n";
    } else {
        cout << "Busca: Objeto com chave " << chaveBusca << " não encontrado.\n";
    }

    return 0;
}
