#include "FilaCircular.h"
#include <iostream>
#include <stdexcept>

FilaCircular::FilaCircular(int capacidade) : capacidade(capacidade), frente(0), traseira(-1), tamanho(0) {
    array = new int[capacidade];
}

FilaCircular::~FilaCircular() {
    delete[] array;
}

void FilaCircular::enfileirar(int valor) {
    if (estaCheia()) {
        throw std::overflow_error("Fila cheia. Não é possível enfileirar.");
    }
    traseira = (traseira + 1) % capacidade;
    array[traseira] = valor;
    tamanho++;
}

int FilaCircular::desenfileirar() {
    if (estaVazia()) {
        throw std::underflow_error("Fila vazia. Não é possível desenfileirar.");
    }
    int valor = array[frente];
    frente = (frente + 1) % capacidade;
    tamanho--;
    return valor;
}

int FilaCircular::frenteFila() const {
    if (estaVazia()) {
        throw std::underflow_error("Fila vazia. Não é possível consultar o início.");
    }
    return array[frente];
}

bool FilaCircular::estaVazia() const {
    return tamanho == 0;
}

bool FilaCircular::estaCheia() const {
    return tamanho == capacidade;
}
