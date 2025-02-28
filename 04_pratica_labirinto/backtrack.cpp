#include <iostream>

#define N 5 // Tamanho do labirinto

using namespace std;

// Estrutura para representar uma posição no labirinto
struct Posicao {
    int linha, coluna;
};

// Estrutura para simular uma pilha
struct Pilha {
    Posicao elementos[N * N];
    int topo;
    
    Pilha() { topo = -1; }
    
    void push(Posicao p) {
        if (topo < N * N - 1) {
            elementos[++topo] = p;
        }
    }
    
    Posicao pop() {
        if (topo >= 0) {
            return elementos[topo--];
        }
        return {-1, -1};
    }
    
    bool empty() {
        return topo == -1;
    }
};

// Função para verificar se uma posição é válida
bool ehValida(int labirinto[N][N], bool visitado[N][N], int linha, int coluna) {
    return (linha >= 0 && linha < N && coluna >= 0 && coluna < N && labirinto[linha][coluna] != 1 && !visitado[linha][coluna]);
}

// Função que resolve o labirinto com backtracking usando pilha
bool resolverLabirinto(int labirinto[N][N], int inicioLinha, int inicioColuna) {
    Pilha pilha;
    bool visitado[N][N] = {false};
    
    // Insere a posição inicial na pilha
    pilha.push({inicioLinha, inicioColuna});
    visitado[inicioLinha][inicioColuna] = true;
    
    // Movimentos possíveis (baixo, cima, direita, esquerda)
    int movimentosLinha[] = {1, -1, 0, 0};
    int movimentosColuna[] = {0, 0, 1, -1};
    
    while (!pilha.empty()) {
        Posicao atual = pilha.pop();
        
        int linha = atual.linha;
        int coluna = atual.coluna;
        
        // Se encontrou o prêmio (representado pelo número 2)
        if (labirinto[linha][coluna] == 2) {
            cout << "Tesouro encontrado na posição (" << linha << ", " << coluna << ")\n";
            return true;
        }
        
        // Explorar os vizinhos
        for (int i = 0; i < 4; i++) {
            int novaLinha = linha + movimentosLinha[i];
            int novaColuna = coluna + movimentosColuna[i];
            
            if (ehValida(labirinto, visitado, novaLinha, novaColuna)) {
                pilha.push({novaLinha, novaColuna});
                visitado[novaLinha][novaColuna] = true;
            }
        }
    }
    
    cout << "Caminho para o tesouro não encontrado!\n";
    return false;
}

int main() {
    // Labirinto (0 = caminho livre, 1 = parede, 2 = prêmio)
    int labirinto[N][N] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 2, 0}
    };
    
    int inicioLinha = 0, inicioColuna = 0; // Posição inicial do jogador
    
    resolverLabirinto(labirinto, inicioLinha, inicioColuna);
    
    return 0;
}
