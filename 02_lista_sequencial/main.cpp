#include "SequentialList.h"

int main() {
    SequentialList list(10); // Cria uma lista com capacidade para 10 elementos

    // Testando inserções
    list.insert(0, 5); // [5]
    list.insert(1, 10); // [5, 10]
    list.insert(1, 7); // [5, 7, 10]

    list.display();

    // Testando remoção
    list.remove(1); // [5, 10]
    list.display();

    // Testando get e set
    list.set(1, 15); // [5, 15]
    std::cout << "Elemento na posição 1: " << list.get(1) << std::endl;

    // Testando se está vazia e tamanho
    std::cout << "Lista está vazia? " << (list.isEmpty() ? "Sim" : "Não") << std::endl;
    std::cout << "Tamanho da lista: " << list.getSize() << std::endl;

    return 0;
}
