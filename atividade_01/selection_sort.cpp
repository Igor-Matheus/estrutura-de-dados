/*
* Algoritmo de ordenaçao Selection Sort
*
* Discente/autor: Igor Matheus Medeiros Brito
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

// Função para realizar o Selection Sort
void selectionSort(std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
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
    selectionSort(data);
    auto end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double> duration = end - start;
    std::cout << "Selection Sort executado em: " << duration.count() << " segundos" << std::endl;

    writeFile(argv[2], data);

    return 0;
}
