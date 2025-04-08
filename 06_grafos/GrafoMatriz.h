#ifndef GRAFOMATRIZ_H
#define GRAFOMATRIZ_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>

#pragma once

using namespace std;

// Estrutura de grafo com matriz de adjacência
class GrafoMatriz {
    public:
        GrafoMatriz(int v);
        ~GrafoMatriz();
        void adicionarAresta(int u, int v);
        bool caminhoBFS(int s, int t);
        void dfsIterativo(int inicio);

    private:
        int V; // número de vértices
        vector<vector<int>> matriz; // matriz de adjacência
};

#endif