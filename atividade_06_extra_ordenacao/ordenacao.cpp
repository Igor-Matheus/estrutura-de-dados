#include <iostream>
#include <fstream>
#include <vector>
#include <chrono> // Para medir o tempo de execução
using namespace std;
using namespace std::chrono; // Para facilitar o uso de "high_resolution_clock"

// Função auxiliar para trocar dois elementos
void swap(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

// Implementação do Quick Sort
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];  // Escolhe o pivô como o último elemento
    int i = low - 1;        // Índice do menor elemento

    for (int j = low; j < high; j++) {
        // Se o elemento atual for menor que o pivô
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); // Troca o elemento com o menor encontrado
        }
    }
    swap(arr[i + 1], arr[high]); // Coloca o pivô na posição correta
    return (i + 1);
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        // Obtém o índice de partição (pivô)
        int pi = partition(arr, low, high);

        // Ordena recursivamente os subarrays antes e depois do pivô
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Implementação do Merge Sort
void merge(vector<int> &arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Cria arrays temporários
    vector<int> L(n1), R(n2);

    // Copia os dados para os arrays temporários
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Mescla os arrays temporários de volta no array original
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Ordena as duas metades
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Mescla as duas metades ordenadas
        merge(arr, l, m, r);
    }
}

// Função para ler os dados de um arquivo e carregar no array
vector<int> readFile(const string &filename) {
    ifstream file(filename);
    vector<int> data;
    int value;

    if (file.is_open()) {
        while (file >> value) {
            data.push_back(value);
        }
        file.close();
    } else {
        cerr << "Erro ao abrir o arquivo!" << endl;
    }
    return data;
}

// Função para gravar os dados ordenados em um arquivo
void writeFile(const string &filename, const vector<int> &data) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const int &val : data) {
            file << val << " ";
        }
        file.close();
    } else {
        cerr << "Erro ao abrir o arquivo para escrita!" << endl;
    }
}

// Função principal para comparar os tempos de execução
int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Uso: " << argv[0] << " <arquivo_entrada> <arquivo_saida>" << endl;
        return 1;
    }

    string inputFile = argv[1];
    string outputFile = argv[2];

    // Lê os dados do arquivo
    vector<int> data = readFile(inputFile);

    // Clona o array para ser usado em ambos os algoritmos
    vector<int> dataQuickSort = data;
    vector<int> dataMergeSort = data;

    // Medir o tempo de execução do Quick Sort
    auto startQuick = high_resolution_clock::now();
    quickSort(dataQuickSort, 0, dataQuickSort.size() - 1);
    auto endQuick = high_resolution_clock::now();
    auto durationQuick = duration_cast<microseconds>(endQuick - startQuick).count();

    // Medir o tempo de execução do Merge Sort
    auto startMerge = high_resolution_clock::now();
    mergeSort(dataMergeSort, 0, dataMergeSort.size() - 1);
    auto endMerge = high_resolution_clock::now();
    auto durationMerge = duration_cast<microseconds>(endMerge - startMerge).count();

    // Escreve os resultados ordenados no arquivo de saída
    writeFile(outputFile + "_quick.txt", dataQuickSort);
    writeFile(outputFile + "_merge.txt", dataMergeSort);

    // Exibe os tempos de execução
    cout << "Tempo de execução do Quick Sort: " << durationQuick << " microsegundos." << endl;
    cout << "Tempo de execução do Merge Sort: " << durationMerge << " microsegundos." << endl;

    return 0;
}
