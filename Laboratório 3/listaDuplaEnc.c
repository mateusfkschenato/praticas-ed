#include <stdio.h>
#include <stdlib.h>
#include "listaDuplaEnc.h"

void inicializar(ListaDuplaEnc *l) {
    l->ini = NULL;
    l->fim = NULL;
}

void imprimir(ListaDuplaEnc *l) {
    NodoD *aux = l->ini;

    while (aux != NULL) {
        printf("%d - %s - %.2f\n", aux->dado.cod, aux->dado.nome, aux->dado.preco);
        aux = aux->prox;
    }
}

void imprimirInverso(ListaDuplaEnc *l) {
    NodoD *aux = l->fim;

    while (aux != NULL) {
        printf("%d - %s - %.2f\n", aux->dado.cod, aux->dado.nome, aux->dado.preco);
        aux = aux->ant;
    }
}

Produto acessar(ListaDuplaEnc *l, int cod) {
    NodoD *aux = l->ini;
    Produto prod = {-1, "", 0.0f};

    while (aux != NULL) {
        if (aux->dado.cod == cod)
            return aux->dado;
        aux = aux->prox;
    }

    return prod;
}

int inserirInicio(ListaDuplaEnc *l, Produto prod) {
    NodoD *novo = (NodoD*) malloc(sizeof(NodoD));
    if (novo == NULL)
        return 0;

    novo->dado = prod;
    novo->ant = NULL;
    novo->prox = l->ini;

    if (l->ini != NULL)
        l->ini->ant = novo; // o antigo início passa a ter um antecessor
    else
        l->fim = novo;      // lista estava vazia: novo nodo também é o fim

    l->ini = novo;
    return 1;
}

int inserirFim(ListaDuplaEnc *l, Produto prod) {
    NodoD *novo = (NodoD*) malloc(sizeof(NodoD));
    if (novo == NULL)
        return 0;

    novo->dado = prod;
    novo->prox = NULL;
    novo->ant = l->fim;

    if (l->fim != NULL)
        l->fim->prox = novo; // o antigo fim passa a apontar para o novo nodo
    else
        l->ini = novo;       // lista estava vazia: novo nodo também é o início

    l->fim = novo;
    return 1;
}

int removerPorCod(ListaDuplaEnc *l, int cod) {
    NodoD *aux = l->ini;

    while (aux != NULL && aux->dado.cod != cod)
        aux = aux->prox;

    if (aux == NULL) // não encontrado
        return 0;

    if (aux->ant != NULL) // existe antecessor: religa por ele
        aux->ant->prox = aux->prox;
    else                  // removendo o próprio início
        l->ini = aux->prox;

    if (aux->prox != NULL) // existe sucessor: religa por ele
        aux->prox->ant = aux->ant;
    else                   // removendo o próprio fim
        l->fim = aux->ant;

    free(aux);
    return 1;
}

void destruir(ListaDuplaEnc *l) {
    NodoD *ant;
    NodoD *aux = l->ini;

    while (aux != NULL) {
        ant = aux;
        aux = aux->prox;
        free(ant);
    }

    l->ini = NULL;
    l->fim = NULL;
}

int tamanho(ListaDuplaEnc *l) {
    NodoD *aux = l->ini;
    int contador = 0;

    while (aux != NULL) {
        contador++;
        aux = aux->prox;
    }

    return contador;
}

// Funções a implementar
void imprimirPelasPontas(ListaDuplaEnc *l) {
    NodoD *primeiro = l->ini;
    NodoD *ultimo = l->fim;

    if (primeiro == NULL){              // CASO LISTA VAZIA
        printf("A lista é vazia.\n\n");
        return;
    }

    else if (primeiro == ultimo){              // CASO LISTA DE UM ELEMENTO
        printf("A lista contem apenas um nodo.");
        printf("%d - %s - %.2f\n", primeiro->dado.cod, primeiro->dado.nome, primeiro->dado.preco);
        return;
    }

    else {                              // CASO DE LISTA DE MAIS DE UM ELEMENTO
        printf("A lista contem mais de um elemento. Sua impressao pelas pontas eh:\n");
        int tamanhoLista = tamanho(l);
        printf("Tamanho da lista eh: %d. \n", tamanhoLista);
        int i = 0;

        while (i < (tamanhoLista / 2)){
            printf("%d - %s - %.2f\n", primeiro->dado.cod, primeiro->dado.nome, primeiro->dado.preco);
            printf("%d - %s - %.2f\n", ultimo->dado.cod, ultimo->dado.nome, ultimo->dado.preco);

            i++;
            primeiro = primeiro->prox;
            ultimo = ultimo->ant;
        }
        
        if ((tamanhoLista % 2) != 0){ // CASO DE LISTA COM NUMERO IMPAR DE ELEMENTOS
            // como o nodo já foi avançado, ele está no nodo do meio da lista. Eu também poderia ter imprimido o nodo ultimo.
            printf("%d - %s - %.2f\n", primeiro->dado.cod, primeiro->dado.nome, primeiro->dado.preco);
        }

        printf("\n\n Fim do exercicio 1.\n");
        return;
    }
    return;

}

void inverter(ListaDuplaEnc *l) {
    NodoD *inicial;
    NodoD *final;
    NodoD *auxiliar;
    NodoD *temp;


    inicial = l->ini;
    final = l->fim;

    if (inicial == NULL){                       // CASO LISTA VAZIA
        printf("A lista eh vazia.\n");
        return;
    }

    if (inicial == final){                              //CASO LISTA COM UM ELEMENTO
        printf("A lista contem apenas um elemento.\n");
        auxiliar = inicial->ant;
        inicial->ant = inicial->prox;
        inicial->prox = auxiliar;

        return;
    }

                                                 
    printf("A lista contem mais de um elemento.\n"); // CASO LISTA COM MAIS DE UM ELEMENTO

    inicial = l->ini;
    final = l->fim;

    while (inicial !=  NULL){
        // Troca os ponteiros para os quais cada nodo está apontando.
        auxiliar = inicial->ant;                
        inicial->ant = inicial->prox;
        inicial->prox = auxiliar;

        // Avança
        inicial = inicial->ant;
    }

    // Inverte os atributos ini e fim da Lista l.
    temp = l->ini;
    l->ini = l->fim;
    l->fim = temp;


    printf("A Lista foi invertida.\n\n");
    return;


    }

