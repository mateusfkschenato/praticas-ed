#include <stdio.h>
#include <stdlib.h>
#include "listaEnc.h"

void inicializar(ListaEnc *lista) {
    lista->ini = NULL;
}

int tamanho(const ListaEnc *lista) {
    Nodo *aux = lista->ini;
    int contador = 0;

    while (aux != NULL) {
        contador++;
        aux = aux->prox;
    }

    return contador;
}

void imprimir(const ListaEnc *lista) {
    Nodo *aux;
    aux = lista->ini;

    while (aux != NULL) {
        printf("Codigo: %d\n", aux->dado.cod);
        printf("Nome: %s\n", aux->dado.nome);
        printf("Preco: %.2f\n", aux->dado.preco);
        printf("-------\n");
        aux = aux->prox;
    }
}

Produto buscar(const ListaEnc *lista, int cod) {
    Nodo *aux;
    Produto prod = {0, "", 0.0f};
    aux = lista->ini;

    while (aux != NULL) {
        if (aux->dado.cod == cod)
            return aux->dado;
        aux = aux->prox;
    }

    return prod; // não encontrado: produto "vazio"
}

int inserirInicio(ListaEnc *lista, Produto prod) {
    Nodo *novo = (Nodo*) malloc(sizeof(Nodo));
    if (novo == NULL)
        return 0; // falha na alocação

    novo->dado = prod;
    novo->prox = lista->ini; // o novo nodo aponta para o antigo início
    lista->ini = novo;        // o novo nodo passa a ser o início

    return 1;
}

int inserirFim(ListaEnc *lista, Produto prod) {
    Nodo *novo;
    Nodo *aux;

    novo = (Nodo*) malloc(sizeof(Nodo));
    if (novo == NULL)
        return 0;

    novo->dado = prod;
    novo->prox = NULL;

    if (lista->ini == NULL) { // lista vazia: o novo nodo é o único (e o início)
        lista->ini = novo;
    } else {
        aux = lista->ini;
        while (aux->prox != NULL) // percorre até o último nodo
            aux = aux->prox;
        aux->prox = novo;
    }

    return 1;
}

int removerPorCod(ListaEnc *lista, int cod) {
    Nodo *ant;
    Nodo *aux;

    ant = NULL;
    aux = lista->ini;

    while (aux != NULL && aux->dado.cod != cod) {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL) // não encontrado
        return 0;

    if (ant == NULL) // removendo o primeiro nodo
        lista->ini = aux->prox;
    else             // removendo do meio ou do final
        ant->prox = aux->prox;

    free(aux);
    return 1;
}

void destruir(ListaEnc *lista) {
    Nodo *ant;
    Nodo *aux;
    aux = lista->ini;

    while (aux != NULL) {
        ant = aux;
        aux = aux->prox;
        free(ant);
    }

    lista->ini = NULL;
}

// Funções a implementar
int removerFim(ListaEnc *l, Produto *prodRemovido) {
    // Esta função recebe o um ponteiro para uma lista, l, e um ponteiro para uma variável do tipo Produto, prodRemovido. 
    // Ela deve remover o último nodo de l e colocar o seu conteúdo em prodRemovido. Lembre-se de evitar vazamentos de memória; o nodo removido deve ser liberado.
    // A função deve retornar 1 caso a remoção seja bem sucedida, ou 0 caso a lista seja inicialmente vazia.

    Nodo *aux;
    Nodo *ant = NULL;

    if (l->ini == NULL){
        return 0;           // Se a lista é vazia, então ela não tem nodos. Portanto, devemos cobrir esse caso de erro e retornar zero.
    }

    aux = l->ini;

    while (aux -> prox != NULL){
        ant = aux;
        aux = aux-> prox;
    }

    *prodRemovido = aux->dado;
    free(aux);

    // Ajusta o penúltimo nodo - que, após a remoção do último nodo, deve passar a ser o último nodo e, portanto, apontar para NULL.
    if (ant == NULL)
        l->ini == NULL;
    
    else
        ant->prox = NULL;


    return 1;           // Tudo certo
}

int trocarComProximo(ListaEnc *l, int pos) {
    Nodo *atual;
    Nodo *anterior = NULL;
    Produto auxiliar;
    int i = 0;

    if (l->ini == NULL){
        return 0;           // Se a lista é vazia, então ela não tem nodos. Portanto, devemos cobrir esse caso de erro e retornar zero.
    }


    atual = l->ini;

    while(atual != NULL){

        if (i == pos){

            if ((atual->prox) == NULL){       // Se é o último elemento da lista, ele não tem próximo, então deve ser trocado com o primeiro.
                auxiliar = atual->dado;
                atual->dado = l->ini->dado;
                l->ini->dado = auxiliar;

            }
            
            else {                              // Senão, deve ser trocado com o seu sucessor.

                anterior = atual;
                atual = atual -> prox;              // Só avança a lista caso o próximo nodo exista.

                auxiliar = atual->dado;
                atual->dado = anterior->dado;
                anterior->dado = auxiliar;


            }

            return 1;

        }

        else {
            i++;
            anterior = atual;
            atual = atual->prox;
        }


    }


    return 0;
}
