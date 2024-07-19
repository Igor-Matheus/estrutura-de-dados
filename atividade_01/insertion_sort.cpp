/*
* Algoritmo de ordenaçao Insertion Sort
*
* Discente/autor: Igor Matheus Medeiros Brito
*/

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// Função para implementar o algoritmo Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Move os elementos do vetor arr[0..i-1], que são maiores que a chave,
        // para uma posição à frente da sua posição atual
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Função para imprimir o vetor
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};
    
    cout << "Vetor antes da ordenação: \n";
    printArray(arr);

    insertionSort(arr);

    cout << "Vetor depois da ordenação: \n";
    printArray(arr);

    return 0;
}
