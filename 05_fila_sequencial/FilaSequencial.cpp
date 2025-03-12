#include "FilaSequencial.h"
#include <iostream>
#include <stdexcept>

FilaSequencial::FilaSequencial(int capacidade) : capacidade(capacidade), frente(0), traseira(-1), tamanho(0) {
    array = new int[capacidade];
}

FilaSequencial::~FilaSequencial() {
    delete[] array;
}

void FilaSequencial::enfileirar(int valor) {
    if (estaCheia()) {
        throw std::overflow_error("Fila cheia. Não é possível enfileirar.");
    }
    traseira = (traseira + 1) % capacidade;
    array[traseira] = valor;
    tamanho++;
}

int FilaSequencial::desenfileirar() {
    if (estaVazia()) {
        throw std::underflow_error("Fila vazia. Não é possível desenfileirar.");
    }
    int valor = array[frente];
    frente = (frente + 1) % capacidade;
    tamanho--;
    return valor;
}

int FilaSequencial::frenteFila() const {
    if (estaVazia()) {
        throw std::underflow_error("Fila vazia. Não é possível consultar o início.");
    }
    return array[frente];
}

bool FilaSequencial::estaVazia() const {
    return tamanho == 0;
}

bool FilaSequencial::estaCheia() const {
    return tamanho == capacidade;
}
