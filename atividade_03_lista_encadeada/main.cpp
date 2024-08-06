#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList list;

    // Teste: Verificar se a lista está vazia
    std::cout << "A lista está vazia? " << (list.isEmpty() ? "Sim" : "Não") << std::endl;

    // Teste: Inserir elementos na lista
    list.insertAt(0, 10);
    list.insertAt(1, 20);
    list.insertAt(2, 30);
    list.insertAt(1, 15);
    list.printList();

    // Teste: Obter tamanho da lista
    std::cout << "Tamanho da lista: " << list.getSize() << std::endl;

    // Teste: Obter e modificar valor de uma posição
    std::cout << "Valor na posição 2: " << list.getValueAt(2) << std::endl;
    list.setValueAt(2, 25);
    list.printList();

    // Teste: Remover elemento de uma posição
    list.removeAt(1);
    list.printList();

    return 0;
}