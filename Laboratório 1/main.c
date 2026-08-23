#include "TADListaContEst.h"

// Função main
int main() {
    // Inicializa as listas
    ListaContEst l1, l2;

    inicializar(&l1);
    inicializar(&l2);
    preencherLista(&l1);

    printf("Tamanho de l1: %d\n", l1.tamanho);
    printf("Tamanho de l2: %d\n\n", l2.tamanho);

    // Preenche l2 com os produtos filtrados de l1
    filtrarProdutosPorPreco(&l1, &l2, 30.00);
    printf("Tamanho de l2: %d\n\n", l2.tamanho);

    printf("Produtos de ate R$30.00:\n");
    imprimirEEsvaziarLista(&l2);

    printf("Tamanho de l1: %d\n", l1.tamanho);
    printf("Tamanho de l2: %d\n\n", l2.tamanho);

    return 0;
}