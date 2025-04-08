#include "GrafoMatriz.h"

// lista de inicialização
GrafoMatriz::GrafoMatriz(int v) : V(v), matriz(v, vector<int>(v, 0)) {}

GrafoMatriz::~GrafoMatriz() {}

void GrafoMatriz::adicionarAresta(int u, int v) {
    matriz[u][v] = 1;
    matriz[v][u] = 1; // grafo não direcionado
}

// Busca em largura (BFS) para encontrar caminho de s até t
bool GrafoMatriz::caminhoBFS(int s, int t) {
    vector<bool> visitado(V, false);
    vector<int> anterior(V, -1);
    vector<int> fila; // substituindo queue

    fila.push_back(s);
    visitado[s] = true;
    int index = 0;

    while (index < fila.size()) {
        int atual = fila[index++];
        if (atual == t) break;

        for (int i = 0; i < V; ++i) {
            if (matriz[atual][i] && !visitado[i]) {
                fila.push_back(i);
                visitado[i] = true;
                anterior[i] = atual;
            }
        }
    }

    if (!visitado[t]) {
        cout << "Nao ha caminho entre os vertices." << endl;
        return false;
    }

    vector<int> caminho;
    for (int at = t; at != -1; at = anterior[at]) {
        caminho.push_back(at);
    }
    reverse(caminho.begin(), caminho.end());

    cout << "Caminho (BFS): ";
    for (int v : caminho) cout << v << " ";
    cout << endl;
    return true;
}

// Busca em profundidade (DFS) utilizando vetor como pilha
void GrafoMatriz::dfsIterativo(int inicio) {
    vector<bool> visitado(V, false);
    vector<int> pilha; // substituindo stack
    pilha.push_back(inicio);

    cout << "DFS Iterativo a partir do vertice " << inicio << ": ";
    while (!pilha.empty()) {
        int atual = pilha.back(); pilha.pop_back();

        if (!visitado[atual]) {
            cout << atual << " ";
            visitado[atual] = true;
        }

        for (int i = V - 1; i >= 0; --i) {
            if (matriz[atual][i] && !visitado[i]) {
                pilha.push_back(i);
            }
        }
    }
    cout << endl;
}
