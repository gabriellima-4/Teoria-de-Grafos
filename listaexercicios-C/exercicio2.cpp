/*
Questão 2
Arestas, vértices e grau de um grafo. Escreva um código em linguagem C que cria um grafo tal que é 
solicitado ao usuário via entrada o número de vértices e arestas para a construção do grafo. Como resultado, 
devem ser mostrados via terminal o grau de cada vértice, a ordem do grafo e o tamanho do grafo.
*/

#include <stdio.h>

void descreverGrafo(int grafo[][100], int ordem, int tamanho) {
    printf("Ordem do grafo: %d vértices\n", ordem);
    printf("Tamanho do grafo: %d arestas\n", tamanho);
    printf("Grau de cada vértice:\n");

    for (int i = 1; i <= ordem; i++) {
        int grau = 0;
        for (int j = 1; j <= ordem; j++) {
            if (grafo[i][j] == 1 || grafo[j][i] == 1) {
                grau++;
            }
        }
        printf("Vértice %d: %d\n", i, grau);
    }

    int tamGrafo = 0, tam = 0;
    for (int i = 1; i <= ordem; i++) {
        for (int j = 1; j <= ordem; j++) {
            if (grafo[i][j] == 1) {
                tam++;
            }
        }
        if (tam > tamGrafo) {
            tamGrafo = tam;
        }
    }
    printf("Tamanho do grafo: %d\n", tamGrafo);
}

int main() {
    int ordem, tamanho;
    printf("Digite o número de vértices: ");
    scanf("%d", &ordem);
    printf("Digite o número de arestas: ");
    scanf("%d", &tamanho);

    int grafo[100][100] = {0};
    printf("Digite as arestas (pares de vértices):\n");
    for (int i = 1; i <= tamanho; i++) {
        int u, v;
        printf("Digite o vértice de origem/partida: ");
        scanf("%d", &u);
        printf("Digite o vértice de destino/chegada: ");
        scanf("%d", &v);
        grafo[u][v] = 1;
    }

    descreverGrafo(grafo, ordem, tamanho);

    return 0;
}

