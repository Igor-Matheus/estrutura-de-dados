#include <iostream> 

// Definição do nó da lista
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Definição da lista encadeada
class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    bool isEmpty() {
        return head == nullptr;
    }

    int getSize() {
        return size;
    }

    int getValueAt(int position) {
        if (position < 0 || position >= size) {
            throw std::out_of_range("Posição inválida.");
        }
        Node* current = head;
        for (int i = 0; i < position; ++i) {
            current = current->next;
        }
        return current->data;
    }

    void setValueAt(int position, int value) {
        if (position < 0 || position >= size) {
            throw std::out_of_range("Posição inválida.");
        }
        Node* current = head;
        for (int i = 0; i < position; ++i) {
            current = current->next;
        }
        current->data = value;
    }

    void insertAt(int position, int value) {
        if (position < 0 || position > size) {
            throw std::out_of_range("Posição inválida.");
        }
        Node* newNode = new Node(value);
        if (position == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 0; i < position - 1; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        ++size;
    }

    void removeAt(int position) {
        if (position < 0 || position >= size) {
            throw std::out_of_range("Posição inválida.");
        }
        Node* toDelete;
        if (position == 0) {
            toDelete = head;
            head = head->next;
        } else {
            Node* current = head;
            for (int i = 0; i < position - 1; ++i) {
                current = current->next;
            }
            toDelete = current->next;
            current->next = toDelete->next;
        }
        delete toDelete;
        --size;
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};