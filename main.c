#include <stdio.h>
#include "listaDuplaEnc.h"

Produto criarProduto(int cod, const char* nome, float preco) {
    Produto produto;
    produto.cod = cod;
    produto.preco = preco;
    strcpy(produto.nome, nome);

    return produto;
}

void preencherLista(ListaDuplaEnc *l) {
    inserirInicio(l, criarProduto(6, "borracha", 5.50));
    inserirInicio(l, criarProduto(5, "lapis", 3.50));
    inserirInicio(l, criarProduto(4, "cacetinho", 1.02));
    inserirInicio(l, criarProduto(3, "refrigerante", 8.60));
    inserirInicio(l, criarProduto(2, "mochila", 89.99));
    inserirInicio(l, criarProduto(1, "camiseta", 30.10));
    inserirInicio(l, criarProduto(0, "caderno", 11.20));
}

int main() {
    // Cria a lista e testa caso vazio das funções
    ListaDuplaEnc l;
    inicializar(&l);
    inverter(&l);
    imprimirPelasPontas(&l);

    preencherLista(&l);

    imprimirPelasPontas(&l);
    printf("--------\n");

    inverter(&l);
    imprimir(&l);
    return 0;
}