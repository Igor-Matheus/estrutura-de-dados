#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>
#include <sstream>
#include <limits>
#include <algorithm>

using namespace std;

class GrafoMatriz {
private:
    vector<vector<int>> matrizAdj;
    int numVertices;

public:
    GrafoMatriz(int vertices) : numVertices(vertices) {
        matrizAdj.resize(vertices, vector<int>(vertices, 0));
    }

    void adicionarAresta(int u, int v) {
        matrizAdj[u][v] = 1;
        matrizAdj[v][u] = 1;  // Grafo não direcionado
    }

    void BFS(int inicio, int fim) {
        vector<bool> visitado(numVertices, false);
        vector<int> anterior(numVertices, -1);
        queue<int> fila;
        
        visitado[inicio] = true;
        fila.push(inicio);

        while (!fila.empty()) {
            int atual = fila.front();
            fila.pop();

            if (atual == fim) {
                break;
            }

            for (int i = 0; i < numVertices; i++) {
                if (matrizAdj[atual][i] == 1 && !visitado[i]) {
                    visitado[i] = true;
                    anterior[i] = atual;
                    fila.push(i);
                }
            }
        }

        if (anterior[fim] == -1) {
            cout << "Não há caminho entre os vértices." << endl;
        } else {
            vector<int> caminho;
            for (int i = fim; i != -1; i = anterior[i]) {
                caminho.push_back(i);
            }
            reverse(caminho.begin(), caminho.end());
            cout << "Caminho: ";
            for (int vertice : caminho) {
                cout << vertice << " ";
            }
            cout << endl;
        }
    }

    void DFSIterativo(int inicio) {
        vector<bool> visitado(numVertices, false);
        stack<int> pilha;
        pilha.push(inicio);

        while (!pilha.empty()) {
            int atual = pilha.top();
            pilha.pop();

            if (!visitado[atual]) {
                cout << atual << " ";
                visitado[atual] = true;
            }

            for (int i = numVertices - 1; i >= 0; i--) {
                if (matrizAdj[atual][i] == 1 && !visitado[i]) {
                    pilha.push(i);
                }
            }
        }
        cout << endl;
    }

    void carregarDeArquivo(const string &nomeArquivo) {
        ifstream arquivo(nomeArquivo);
        string linha;
        while (getline(arquivo, linha)) {
            stringstream ss(linha);
            int u, v;
            ss >> u >> v;
            adicionarAresta(u, v);
        }
    }
};
