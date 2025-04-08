#ifndef GRAFOLISTA_H
#define GRAFOLISTA_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>

#pragma once

using namespace std;

// Estrutura de grafo com lista de adjacência
class GrafoLista {
    public:
        GrafoLista(int v);
        ~GrafoLista();
        void adicionarAresta(int u, int v);
        bool caminhoBFS(int s, int t);
        void dfsIterativo(int inicio);

    private:
        int V;
        vector<vector<int>> adj; // lista de adjacência
};

#endif