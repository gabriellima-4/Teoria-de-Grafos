/*
Quest�o 3
Arestas, v�rtices e grau de um grafo. Crie um c�digo em linguagem C um grafo com 3 v�rtices e 5 arestas, 
mostrando via sa�da/terminal a multiplicidade de cada v�rtice. 
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

    // Calcular a multiplicidade de cada v�rtice
    for (int i = 0; i < NUM_VERTICES; i++) {
        for (int j = 0; j < NUM_VERTICES; j++) {
            if (grafo[i][j] == 1) {
                multiplicidade[i]++;
            }
        }
    }

    // Mostrar a multiplicidade de cada v�rtice
    printf("Multiplicidade de cada v�rtice:\n");
    for (int i = 0; i < NUM_VERTICES; i++) {
        printf("V�rtice %d: %d\n", i, multiplicidade[i]);
    }

    return 0;
}

