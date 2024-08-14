#include <iostream>
#include "FilaCircular.h"

int main() {
    FilaCircular fila(5);  // Capacidade de 5 elementos

    // Teste de inserção
    std::cout << "Enfileirando elementos..." << std::endl;
    fila.enfileirar(10);
    fila.enfileirar(20);
    fila.enfileirar(30);
    fila.enfileirar(40);
    fila.enfileirar(50);

    try {
        fila.enfileirar(60); // Deve lançar exceção, fila cheia
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    // Consultando o início da fila
    std::cout << "Início da fila: " << fila.frenteFila() << std::endl;

    // Teste de remoção
    std::cout << "Desenfileirando elementos..." << std::endl;
    std::cout << "Desenfileirado: " << fila.desenfileirar() << std::endl;
    std::cout << "Desenfileirado: " << fila.desenfileirar() << std::endl;

    // Consultando o início da fila após remoção
    std::cout << "Início da fila: " << fila.frenteFila() << std::endl;

    // Inserindo novamente para testar o comportamento circular
    std::cout << "Enfileirando elementos..." << std::endl;
    fila.enfileirar(60);
    fila.enfileirar(70);

    std::cout << "Início da fila: " << fila.frenteFila() << std::endl;

    // Verificando se a fila está cheia
    std::cout << "Fila cheia? " << (fila.estaCheia() ? "Sim" : "Não") << std::endl;

    // Desenfileirando todos os elementos
    while (!fila.estaVazia()) {
        std::cout << "Desenfileirado: " << fila.desenfileirar() << std::endl;
    }

    // Verificando se a fila está vazia
    std::cout << "Fila vazia? " << (fila.estaVazia() ? "Sim" : "Não") << std::endl;

    return 0;
}
