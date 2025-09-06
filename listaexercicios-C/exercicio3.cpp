/*
Questão 3
Arestas, vértices e grau de um grafo. Crie um código em linguagem C um grafo com 3 vértices e 5 arestas, 
mostrando via saída/terminal a multiplicidade de cada vértice. 
*/

#include <stdio.h>

#define NUM_VERTICES 3
#define NUM_ARESTAS 5

int main() {
    int grafo[NUM_VERTICES][NUM_VERTICES] = {0};
    int multiplicidade[NUM_VERTICES] = {0};

    // Adicionar as arestas ao grafo
    grafo[0][1] = 1;
    grafo[1][0] = 1;
    grafo[1][2] = 1;
    grafo[2][0] = 1;
    grafo[0][2] = 1;

    // Calcular a multiplicidade de cada vértice
    for (int i = 0; i < NUM_VERTICES; i++) {
        for (int j = 0; j < NUM_VERTICES; j++) {
            if (grafo[i][j] == 1) {
                multiplicidade[i]++;
            }
        }
    }

    // Mostrar a multiplicidade de cada vértice
    printf("Multiplicidade de cada vértice:\n");
    for (int i = 0; i < NUM_VERTICES; i++) {
        printf("Vértice %d: %d\n", i, multiplicidade[i]);
    }

    return 0;
}

