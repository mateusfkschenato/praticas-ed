#ifndef ABP_H
#define ABP_H
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int  cod;
    char nome[50];
    float preco;
} Produto;

typedef struct str_NodoArv NodoArv;

struct str_NodoArv {
    Produto  dado;
    NodoArv *esq;
    NodoArv *dir;
};

NodoArv* abpBuscar   (NodoArv *raiz, int cod);      /* ponteiro p/ nó com dado.cod==cod, ou NULL */
NodoArv* abpInserir  (NodoArv *raiz, Produto p);    /* insere p preservando propriedade          */
NodoArv* abpRemover  (NodoArv *raiz, int cod);      /* remove cod preservando propriedade        */
void     abpDestruir (NodoArv *raiz);               /* libera toda a memória                     */
void     abpEmOrdem  (const NodoArv *raiz);         /* imprime em ordem crescente de cod         */

void     abpContarParesImpares (const NodoArv *raiz, int *pares, int *impares);  /* retorna o número de elementos da árvore             */
void     abpPodar (NodoArv *raiz, int altura);                                   /* reduz a árvore à altura máxima especificada         */
NodoArv* abpExtrairFolhas (const NodoArv *raiz);                                 /* retorna uma nova árvore só com as folhas da original*/

#endif