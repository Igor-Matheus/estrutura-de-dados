#include "GrafoLista.h"


GrafoLista::GrafoLista(int v) : V(v), adj(v) {}

GrafoLista::~GrafoLista() {}

void GrafoLista::adicionarAresta(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Busca em largura (BFS)
bool GrafoLista::caminhoBFS(int s, int t) {
    vector<bool> visitado(V, false);
    vector<int> anterior(V, -1);
    vector<int> fila;

    fila.push_back(s);
    visitado[s] = true;
    int index = 0;

    while (index < fila.size()) {
        int atual = fila[index++];
        if (atual == t) break;

        for (int vizinho : adj[atual]) {
            if (!visitado[vizinho]) {
                fila.push_back(vizinho);
                visitado[vizinho] = true;
                anterior[vizinho] = atual;
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

// DFS sem recursão
void GrafoLista::dfsIterativo(int inicio) {
    vector<bool> visitado(V, false);
    vector<int> pilha;
    pilha.push_back(inicio);

    cout << "DFS Iterativo a partir do vertice " << inicio << ": ";
    while (!pilha.empty()) {
        int atual = pilha.back(); pilha.pop_back();

        if (!visitado[atual]) {
            cout << atual << " ";
            visitado[atual] = true;
        }

        // visitar em ordem reversa para manter lógica de DFS
        for (auto it = adj[atual].rbegin(); it != adj[atual].rend(); ++it) {
            if (!visitado[*it]) {
                pilha.push_back(*it);
            }
        }
    }
    cout << endl;
}
