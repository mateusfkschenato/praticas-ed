#include "abp.h"

int main() {
    NodoArv *raiz = NULL;
    int pares = 0, impares = 0;

    // Testes coma a árvore vazia
    abpContarParesImpares(raiz, &pares, &impares);

    printf("Arvore com %d produtos pares e %d impares\n", pares, impares);
    abpPodar(raiz, 1);
    printf("-----------------------\n");

    // Inicializa a árvore
    Produto p1 = {7, "a", 1};
    Produto p2 = {3, "b", 2};
    Produto p3 = {10, "c", 3};
    Produto p4 = {5, "d", 4};
    Produto p5 = {1, "e", 5};
    Produto p6 = {8, "f", 6};
    Produto p7 = {6, "g", 7};
    Produto p8 = {9, "h", 8};
    Produto p9 = {4, "i", 9};

    raiz = abpInserir(raiz, p1);
    raiz = abpInserir(raiz, p2);
    raiz = abpInserir(raiz, p3);
    raiz = abpInserir(raiz, p4);
    raiz = abpInserir(raiz, p5);
    raiz = abpInserir(raiz, p6);
    raiz = abpInserir(raiz, p7);
    raiz = abpInserir(raiz, p8);
    raiz = abpInserir(raiz, p9);

    // Testa as funções
    abpContarParesImpares(raiz, &pares, &impares);
    printf("Arvore com %d produtos pares e %d impares\n", pares, impares);
    printf("A altura da arvore eh %d.\n", alturaABP(raiz));

    //printf("Altura da arvore com folhas removidas eh %d.\n", alturaABP(removeFolha(raiz)));

    abpPodar(raiz, 2);
    abpEmOrdem(raiz);

    // Teste de função bônus
    // Deve imprimir 1 -> 5 -> 8
    // NodoArv *folhas = NULL;
    // abpExtrairFolhas(raiz, folhas);
    // abpEmOrdem(folhas);
    
}