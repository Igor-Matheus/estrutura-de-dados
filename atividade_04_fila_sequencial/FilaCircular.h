#ifndef FILA_CIRCULAR_H
#define FILA_CIRCULAR_H

#include <iostream>

class FilaCircular {
    private:
        int* array;
        int capacidade;
        int frente;
        int traseira;
        int tamanho;

    public:
        FilaCircular(int capacidade);
        ~FilaCircular();

        void enfileirar(int valor);
        int desenfileirar();
        int frenteFila() const;
        bool estaVazia() const;
        bool estaCheia() const;
};

#endif // FILA_CIRCULAR_H
