#include <stdio.h>
#include "listaEnc.h"

Produto criarProduto(int cod, const char* nome, float preco);
void preencherLista(ListaEnc *l);
void sucessoDaTroca(int troca, int sucesso);

int main() {
    // Cria lista
    ListaEnc lista;
    inicializar(&lista);

    int sucesso;
    Produto prod;
    sucesso = removerFim(&lista, &prod);
    if(sucesso) {
        printf("Removeu o que nao deveria.");
        return 0;
    }

    // Preenche lista
    int tam;
    preencherLista(&lista);
    tam = tamanho(&lista);
    printf("Lista criada com %d produtos.\n\n", tam);

    // Remove último produto
    removerFim(&lista, &prod);
    tam = tamanho(&lista);

    printf("Removido o produto %s. Agora a lista tem %d produtos.\n\n", prod.nome, tam);
    
    // Troca nodos
    sucesso = trocarComProximo(&lista, 0);
    sucessoDaTroca(1, sucesso);

    sucesso = trocarComProximo(&lista, 10);
    sucessoDaTroca(2, sucesso);

    sucesso = trocarComProximo(&lista, 4);
    sucessoDaTroca(3, sucesso);

    sucesso = trocarComProximo(&lista, 3);
    sucessoDaTroca(4, sucesso);

    printf("\nLista apos as trocas:\n\n");
    imprimir(&lista);

    return 0;
}

void preencherLista(ListaEnc *l) {
    inserirInicio(l, criarProduto(5, "lapis", 3.50));
    inserirInicio(l, criarProduto(4, "cacetinho", 1.02));
    inserirInicio(l, criarProduto(3, "refrigerante", 8.60));
    inserirInicio(l, criarProduto(2, "mochila", 89.99));
    inserirInicio(l, criarProduto(1, "camiseta", 30.10));
    inserirInicio(l, criarProduto(0, "caderno", 11.20));
}

void sucessoDaTroca(int troca, int sucesso) {
    if(sucesso) {
        printf("A troca %d funcionou.\n", troca);
    }

    else {
        printf("A troca %d deu erro.\n", troca);
    }
}

Produto criarProduto(int cod, const char* nome, float preco) {
    Produto produto;
    produto.cod = cod;
    produto.preco = preco;
    strcpy(produto.nome, nome);

    return produto;
}
