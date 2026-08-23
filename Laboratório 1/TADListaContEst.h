#ifndef TADLISTACONTEST_H
#define TADLISTACONTEST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct Produto
typedef struct {
    int cod;
    char nome[50];
    float preco;
} Produto;

// Struct de lista linear de produtos por contiguidade
#define CAPACIDADE 50
typedef struct {
    int tamanho;
    Produto dados[CAPACIDADE];
} ListaContEst;

// Interface do TAD lista
Produto criarProduto(int cod, const char* nome, float preco);  // Cria o produto com os dados informados
void inicializar(ListaContEst *l);                          // Cria uma lista vazia
int tamanho(const ListaContEst *l);                         // Devolve o número de elementos da lista
Produto acessar(const ListaContEst *l, int pos);            // Retorna o produto na posição informada da lista, sem removê-lo
int inserir(ListaContEst *l, Produto novo, int pos);        // Insere o produto na posição informada da lista, deslocando os demais para a direita
int remover(ListaContEst *l, int pos);                      // Remove o produto da posição informada da lista, deslocando os demais para a esquerda
int buscar(const ListaContEst *l, int cod);                 // Retorna a posição na lista do produto com o código informado (-1 se não estiver na lista)
void destruir(ListaContEst *l);                             // Destrói a lista

// Funções a implementar:                                              
void filtrarProdutosPorPreco(const ListaContEst *l1, ListaContEst *l2, float preco);    // Documente sua função
void imprimirEEsvaziarLista(ListaContEst *l);                                           // Documente sua função COMPLEXIDADE: O(n^2)

#endif