#include <stdio.h>
#include "filaEnc.h"
#include <stdlib.h>

void imprimePilhaInverso(PilhaEnc *p) {
// ideia: criar uma pilha auxiliar

    PilhaEnc *pilhaAuxiliar = (PilhaEnc*) malloc(sizeof(PilhaEnc));
    Produto auxiliar;

    inicializaPilha(pilhaAuxiliar);

    if (estaVaziaPilha(p)){
        printf("A pilha original é vazia.\n");
        return;
    }

    while(!(estaVaziaPilha(p))){
        desempilha(p, &auxiliar);
        empilha(pilhaAuxiliar, auxiliar);
    }

    while(!(estaVaziaPilha(pilhaAuxiliar))){
        desempilha(pilhaAuxiliar, &auxiliar);
        printf("%d -- %s -- %.2f\n", auxiliar.cod, auxiliar.nome, auxiliar.preco);
    }


    while(!(estaVaziaPilha(pilhaAuxiliar))){
        desempilha(pilhaAuxiliar, &auxiliar);
        empilha(p, auxiliar);
    }
    

}

void transfereOrdenado(FilaEnc *f, PilhaEnc *p) {
    // acha o menor codigo dentre os produtos da fila,
    // transfere ele para a pilha

    Produto prod;
    int tamanho = tamanhoFila(f);

    if(estaVaziaFila(f)){
        return;
    }

    while (tamanho != 0) {
        int maior = 0;
        int cont = 0;

        while (cont < tamanho){         // Acha o maior codigo da lista atual.

            desenfileira(f, &prod);

            if (prod.cod > maior) {
                maior = prod.cod;

            }

            enfileira(f, prod);             // faz isso 5 vezes ate que se passe pela lista completa.
            cont++;
        }

        cont = 0;

        while (cont < tamanho){               // Procura o produto com esse codigo que acabou de achar.

            desenfileira(f, &prod);             
            if (prod.cod == maior){
                empilha(p, prod);               // Se eh ele, entao poe na pilha
            }

            else {
                enfileira(f, prod);                 // Se nao eh ele, entao so taca ele de volta na fila e deixa ele em stand-by
            }

            cont++;
        }

        maior = 0;
        tamanho--;              // Ate que acabe toda a fila
    }
    
    
    
}

void enchePilha(PilhaEnc *p) {
    Produto p1 = {12, "a", 0.0};
    Produto p2 = {3, "b", 0.0};
    Produto p3 = {7, "c", 0.0};
    Produto p4 = {19, "d", 0.0};
    Produto p5 = {5, "e", 0.0};

    empilha(p, p1);
    empilha(p, p2);
    empilha(p, p3);
    empilha(p, p4);
    empilha(p, p5);
}

void encheFila(FilaEnc *f) {
    Produto p1 = {15, "g", 0.0};
    Produto p2 = {4, "i", 0.0};
    Produto p3 = {20, "f", 0.0};
    Produto p4 = {1, "j", 0.0};
    Produto p5 = {10, "h", 0.0};    

    enfileira(f, p1);
    enfileira(f, p2);
    enfileira(f, p3);
    enfileira(f, p4);
    enfileira(f, p5);
}

int main() {
    PilhaEnc p, dest;
    FilaEnc f;

    inicializaPilha(&p);
    inicializaPilha(&dest);
    inicializaFila(&f);

    // Testes com estruturas vazias
    imprimePilhaInverso(&p);
    transfereOrdenado(&f, &p);

    // Preenche as estruturas
    enchePilha(&p);
    encheFila(&f);

    // // Testa as funções
    imprimePilhaInverso(&p);

    printf("-----------------\n");

    transfereOrdenado(&f, &dest);
    imprimePilhaInverso(&dest);

}