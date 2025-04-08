#include <iostream>
#include "GrafoMatriz.h"
#include "GrafoLista.h"

using namespace std;

// Função para carregar grafo de arquivo (para matriz de adjacência)
void carregarGrafo(const string& nomeArquivo, GrafoMatriz& grafoM) {
    ifstream arquivo(nomeArquivo);
    int u, v;
    while (arquivo >> u >> v) {
        grafoM.adicionarAresta(u, v);
    }
}

// Função para carregar grafo de arquivo (para lista de adjacência)
void carregarGrafo(const string& nomeArquivo, GrafoLista& grafoL) {
    ifstream arquivo(nomeArquivo);
    int u, v;
    while (arquivo >> u >> v) {
        grafoL.adicionarAresta(u, v);
    }
}

// Função principal - uso por linha de comando
int main(int argc, char* argv[]) {
    if (argc < 5) {
        cout << "Uso: ./grafo <tipo> <arquivo> <origem> <destino>" << endl;
        cout << "tipo: matriz ou lista" << endl;
        return 1;
    }

    string tipo = argv[1];
    string arquivo = argv[2];
    int origem = stoi(argv[3]);
    int destino = stoi(argv[4]);
    int numVertices = 100; // ajustar conforme o esperado do arquivo

    if (tipo == "matriz") {
        GrafoMatriz g(numVertices);
        carregarGrafo(arquivo, g);
        g.caminhoBFS(origem, destino);
        g.dfsIterativo(origem);
    } else if (tipo == "lista") {
        GrafoLista g(numVertices);
        carregarGrafo(arquivo, g);
        g.caminhoBFS(origem, destino);
        g.dfsIterativo(origem);
    } else {
        cout << "Tipo de grafo desconhecido." << endl;
        return 1;
    }

    return 0;
}
