#include "abp.h"

NodoArv* abpBuscar(NodoArv *raiz, int cod) {
    if (raiz == NULL)              return NULL;    // não encontrado
    if (cod == raiz->dado.cod)     return raiz;    // encontrado
    if (cod < raiz->dado.cod)
        return abpBuscar(raiz->esq, cod);           // só olha a esquerda
    return abpBuscar(raiz->dir, cod);               // só olha a direita
}

NodoArv* abpInserir(NodoArv *raiz, Produto valor) {
    if (raiz == NULL) {
        NodoArv *novo = (NodoArv*) malloc(sizeof(NodoArv));
        novo->dado = valor;
        novo->esq  = NULL;
        novo->dir  = NULL;
        return novo;                         // pai vai "pendurar" este nó
    }
    if (valor.cod < raiz->dado.cod)
        raiz->esq = abpInserir(raiz->esq, valor);
    else if (valor.cod > raiz->dado.cod)
        raiz->dir = abpInserir(raiz->dir, valor);
    // se igual: código já existe, não insere duplicado
    return raiz;                             // devolve raiz (inalterada) ao pai
}

// encontra o nó de menor valor (mais à esquerda) de uma subárvore
NodoArv* abpMinimo(NodoArv *raiz) {
    while (raiz->esq != NULL)
        raiz = raiz->esq;
    return raiz;
}

NodoArv* abpRemover(NodoArv *raiz, int cod) {
    if (raiz == NULL) return NULL;               // não encontrado

    if (cod < raiz->dado.cod)
        raiz->esq = abpRemover(raiz->esq, cod);   // procura/remove na esquerda
    else if (cod > raiz->dado.cod)
        raiz->dir = abpRemover(raiz->dir, cod);   // procura/remove na direita
    else {
        // achou o nó a remover
        if (raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);   // caso 1: folha
            return NULL;
        }
        if (raiz->esq == NULL) {
            NodoArv *filho = raiz->dir;   // caso 2: só filho direito
            free(raiz);
            return filho;
        }
        if (raiz->dir == NULL) {
            NodoArv *filho = raiz->esq;   // caso 2: só filho esquerdo
            free(raiz);
            return filho;
        }
        // caso 3: dois filhos
        NodoArv *sucessor = abpMinimo(raiz->dir);
        raiz->dado = sucessor->dado;                              // copia valor do sucessor
        raiz->dir  = abpRemover(raiz->dir, sucessor->dado.cod);  // remove o sucessor
    }
    return raiz;
}

void abpDestruir(NodoArv *raiz) {
    if (raiz == NULL) return;
    abpDestruir(raiz->esq);
    abpDestruir(raiz->dir);
    free(raiz);
}

void abpEmOrdem(const NodoArv *raiz) {
    if (raiz == NULL) return;
    abpEmOrdem(raiz->esq);
    Produto prod = raiz->dado;
    printf("[%d] -- %s -- %.2f\n", prod.cod, prod.nome, prod.preco);
    abpEmOrdem(raiz->dir);
}

// Funções a implementar

void abpContarParesImpares(const NodoArv *raiz, int *pares, int *impares) {
    if (raiz == NULL) return;

    abpContarParesImpares(raiz->esq, pares, impares);
    Produto prod = raiz->dado;

    if (prod.cod % 2 == 0)      // se eh par
        (*pares)++;
    else                        // se eh impar
        (*impares)++;

    abpContarParesImpares(raiz->dir, pares, impares);
}

// funcao auxiliar

int alturaABP(const NodoArv *raiz){
    int alturaABPesq, alturaABPdir;

    if(raiz == NULL){
        return -1;                          // a altura de uma abp vazia é -1
    }

    alturaABPesq = alturaABP(raiz->esq);
    alturaABPdir = alturaABP(raiz->dir);

    if (alturaABPesq > alturaABPdir){
        return 1 + alturaABPesq;             // a altura de uma abp folha, isto eh, abp de um elemento
    }

    else {
        return 1 + alturaABPdir;
    }


}

/*void removeFolha(NodoArv *raiz){
    if(raiz == NULL){
        return;
    }

    removeFolha(raiz->esq);
    
    if(raiz->esq == NULL){
        free(raiz->esq);
    }

    if (raiz->dir == NULL){
        free(raiz->dir);
    }

    removeFolha(raiz->dir);
}
*/




void abpPodar(NodoArv *raiz, int altura) {

    if (altura < 0){
        printf("A altura inserida é inválida.\n");
        return;
    }
/*
    int alturaABPoriginal = alturaABP(raiz);
    printf("%d", alturaABPoriginal);                    // verificacao: sucesso

    if (alturaABPoriginal <= altura){
        //printf("Visto que a altura informada é maior que a altura da ABP raiz, não há o que alterar nela. A altura informada deve ser estritamente menor que a altura da ABP raiz para poder poda-la");
        return;
    }

    else{        
        // Tentativa #1
        // Procura as FOLHAS da árvore       
        // Corta TODAS as FOLHAS da árvore

        // Verifica a altura da nova ABP raiz com as folhas podadas;
        // Faz isso até que a altura da ABP podada seja <= a altura informada pelo usuario.


        // Tentativa #2 
        // Se chegou a altura abaixo do limite, corta tudo abaixo

*/
/*
    if(raiz == NULL)
        return;

    else{

        if (altura < alturaABP(raiz->esq))
            abpDestruir(raiz->esq);

        if (altura < alturaABP(raiz->dir))
            abpDestruir(raiz->dir);


    }

*/
    if (raiz == NULL)
        return;
    
    if (altura == 0){
        abpDestruir(raiz->esq);
        abpDestruir(raiz->dir);
        raiz->esq = NULL;
        raiz->dir = NULL;
    }

    else {
        abpPodar(raiz->esq, altura-1);
        abpPodar(raiz->dir, altura-1);
    }

    // else if(altura == 1){
    //     abpDestruir(raiz->esq->esq);
    //     abpDestruir(raiz->esq->dir);
    //     abpDestruir(raiz->dir->esq);
    //     abpDestruir(raiz->dir->dir);
    //     return;
    // }

    // else if(altura == 2){
    //     //abpDestruir(raiz->esq->esq->esq);
    //     //abpDestruir(raiz->esq->esq->dir);
    //     abpDestruir(raiz->esq->dir->esq);
    //     abpDestruir(raiz->esq->dir->dir);
    //     // abpDestruir(raiz->dir->dir->dir);
    //     // abpDestruir(raiz->dir->dir->esq);
    //     // abpDestruir(raiz->dir->esq->esq);
    //     abpDestruir(raiz->dir->esq->dir);
    //     return;
   
}



// Questão bônus
//NodoArv* abpExtrairFolhas(const NodoArv *raiz) {
  //  return raiz;
//}