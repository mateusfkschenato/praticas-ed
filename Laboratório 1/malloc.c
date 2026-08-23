#include <stdio.h>
#include <stdlib.h>

// Define um tipo Ponto, com coordenadas x e y
typedef struct {
    float x;
    float y;
} Ponto;

// Função que recebe um vetor de pontos e seu tamanho e calcula a média dos pontos
Ponto* pontoMedio(Ponto* pontos, int n) {
    float x = 0, y = 0;

    for(int i=0; i<n; i++) {
        Ponto p = pontos[i];
        x += p.x;
        y += p.y;
    }

    Ponto *medio = (Ponto*) malloc(sizeof(Ponto));

    medio->x = x/n;
    medio->y = y/n;

    return medio;
}

// Função main
int main() {
    int n; // Tamanho do vetor

    // Usuário informa o tamanho do vetor
    printf("Quantidade de pontos: ");
    scanf("%d", &n);

    // Declara vetor de pontos
    Ponto* pontos;
    pontos = (Ponto*)malloc(n * sizeof(Ponto));

    printf("Digite os pontos no formato x, y:\n");

    // Laço de entrada dos pontos do vetor
    for (int i = 0; i < n; i++) {
        printf("Ponto %d: ", i + 1);
        scanf("%f, %f", &pontos[i].x, &pontos[i].y);
    }

    // Encontra e imprime o ponto médio
    Ponto* medio = pontoMedio(pontos, n);
    printf("\nPonto medio:\n");
    printf("(%.2f, %.2f)\n", medio->x, medio->y);

    return 0;
}