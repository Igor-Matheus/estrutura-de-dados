#include <iostream>
#include "GrafoMatriz.h"
#include "GrafoLista.h"

using namespace std;

int main() {
    int vertices = 6;
    
    // Teste com matriz de adjacência
    GrafoMatriz grafoMatriz(vertices);
    grafoMatriz.carregarDeArquivo("grafo.txt");
    
    cout << "Busca em Largura (Matriz) de 0 a 5:" << endl;
    grafoMatriz.BFS(0, 5);

    cout << "Busca em Profundidade Iterativa (Matriz) a partir de 0:" << endl;
    grafoMatriz.DFSIterativo(0);

    // Teste com lista de adjacência
    GrafoLista grafoLista(vertices);
    grafoLista.carregarDeArquivo("grafo.txt");

    cout << "Busca em Largura (Lista) de 0 a 5:" << endl;
    grafoLista.BFS(0, 5);

    cout << "Busca em Profundidade Iterativa (Lista) a partir de 0:" << endl;
    grafoLista.DFSIterativo(0);

    return 0;
}
