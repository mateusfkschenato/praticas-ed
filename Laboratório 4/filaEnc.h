#ifndef FILAENC_H
#define FILAENC_H

#include "pilhaEnc.h"

typedef struct {
    Nodo *frente;
    Nodo *final;
} FilaEnc;

void inicializaFila(FilaEnc *f);
int  estaVaziaFila(FilaEnc *f);
int  enfileira(FilaEnc *f, Produto valor);
int  desenfileira(FilaEnc *f, Produto *valorRemovido);
int  frente(FilaEnc *f, Produto *valor);
int  tamanhoFila(FilaEnc *f);

#endif
