/*
Questão 5
Arestas, vértices e grau de um grafo. Crie um código em linguagem C  que verifica se um grafo de entrada 
é to tipo estrela, mostrando via saída/terminal uma das seguintes mensagens: 
1) O grafo é do tipo estrela; 
2) O grafo NÃO é do tipo estrela.
*/

#include <stdio.h>

#define MAX_VERTICES 100  // Número máximo de vértices suportado

int main() {
    int numVertices, numArestas;
    int i, j, v1, v2;

    printf("Digite o número total de vértices do grafo: ");
    scanf("%d", &numVertices);

    int grafo[MAX_VERTICES][MAX_VERTICES];
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            grafo[i][j] = 0;
        }
    }

    printf("Digite os pares de vértices conectados (digite -1 para encerrar):\n");
    numArestas = 0;

    while (1) {
        printf("Vértice de partida: ");
        scanf("%d", &v1);
        if (v1 == -1) break;

        printf("Vértice de chegada: ");
        scanf("%d", &v2);
        if (v2 == -1) break;

        if (v1 < 1 || v1 > numVertices || v2 < 1 || v2 > numVertices) {
            printf("Vértices inválidos! Digite valores entre 1 e %d.\n", numVertices);
            continue;
        }

        grafo[v1 - 1][v2 - 1] = 1;
        grafo[v2 - 1][v1 - 1] = 1;

        numArestas++;
    }

    int grau[MAX_VERTICES];
    for (i = 0; i < numVertices; i++) {
        grau[i] = 0;
        for (j = 0; j < numVertices; j++) {
            grau[i] += grafo[i][j];
        }
    }

    int numCentrais = 0, verticeCentral = -1, numExternos = 0;
    for (i = 0; i < numVertices; i++) {
        if (grau[i] == numVertices - 1) {
            numCentrais++;
            verticeCentral = i;
        } else if (grau[i] == 1) {
            numExternos++;
        }
    }

    if (numCentrais == 1 && numExternos == numVertices - 1)
        printf("O grafo é uma ESTRELA. Vértice central: %d\n", verticeCentral + 1);
    else
        printf("O grafo NÃO é uma ESTRELA.\n");

    return 0;
}

