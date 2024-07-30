#include <iostream>
#include <stdexcept>

class SequentialList {
private:
    int* data;
    int capacity;
    int size;

public:
    // Construtor que inicializa a lista vazia com uma capacidade definida
    SequentialList(int cap) : capacity(cap), size(0) {
        data = new int[capacity];
    }

    // Destrutor para liberar a memória alocada
    ~SequentialList() {
        delete[] data;
    }

    // Verifica se a lista está vazia
    bool isEmpty() const {
        return size == 0;
    }

    // Verifica se a lista está cheia
    bool isFull() const {
        return size == capacity;
    }

    // Retorna o tamanho atual da lista
    int getSize() const {
        return size;
    }

    // Obtém o valor de um elemento em uma posição específica
    int get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    // Modifica o valor de um elemento em uma posição específica
    void set(int index, int value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        data[index] = value;
    }

    // Insere um elemento em uma posição específica
    void insert(int index, int value) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of bounds");
        }
        if (isFull()) {
            throw std::overflow_error("List is full");
        }
        for (int i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++size;
    }

    // Remove um elemento de uma posição específica
    void remove(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }

    // Exibe a lista (para fins de teste e demonstração)
    void display() const {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};
