#ifndef FILA_CIRCULAR_H
#define FILA_CIRCULAR_H

#include <iostream>

class FilaSequencial {
    private:
        int* array;
        int capacidade;
        int frente;
        int traseira;
        int tamanho;

    public:
        FilaSequencial(int capacidade);
        ~FilaSequencial();

        void enfileirar(int valor);
        int desenfileirar();
        int frenteFila() const;
        bool estaVazia() const;
        bool estaCheia() const;
};

#endif // FILA_CIRCULAR_H
