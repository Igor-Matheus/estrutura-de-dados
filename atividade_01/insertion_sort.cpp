/*
* Algoritmo de ordenaçao Insertion Sort
*
* Discente/autor: Igor Matheus Medeiros Brito
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

// Função para realizar o Insertion Sort
void insertionSort(std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Função para ler um arquivo e retornar um vetor de inteiros
std::vector<int> readFile(const std::string& filename) {
    std::vector<int> data;
    std::ifstream file(filename);
    if (file.is_open()) {
        int value;
        while (file >> value) {
            data.push_back(value);
        }
        file.close();
    } else {
        std::cerr << "Não foi possível abrir o arquivo " << filename << std::endl;
    }
    return data;
}

// Função para escrever um vetor de inteiros em um arquivo
void writeFile(const std::string& filename, const std::vector<int>& data) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const int& value : data) {
            file << value << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Não foi possível abrir o arquivo " << filename << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Uso: " << argv[0] << " <arquivo_entrada> <arquivo_saida>" << std::endl;
        return 1;
    }

    std::vector<int> data = readFile(argv[1]);

    auto start = std::chrono::high_resolution_clock::now();
    insertionSort(data);
    auto end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double> duration = end - start;
    std::cout << "Insertion Sort executado em: " << duration.count() << " segundos" << std::endl;

    writeFile(argv[2], data);

    return 0;
}
