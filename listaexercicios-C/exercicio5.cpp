/*
Quest�o 5
Arestas, v�rtices e grau de um grafo. Crie um c�digo em linguagem C  que verifica se um grafo de entrada 
� to tipo estrela, mostrando via sa�da/terminal uma das seguintes mensagens: 
1) O grafo � do tipo estrela; 
2) O grafo N�O � do tipo estrela.
*/

#include <stdio.h>

#define MAX_VERTICES 100  // N�mero m�ximo de v�rtices suportado

int main() {
    int numVertices, numArestas;
    int i, j, v1, v2;

    printf("Digite o n�mero total de v�rtices do grafo: ");
    scanf("%d", &numVertices);

    int grafo[MAX_VERTICES][MAX_VERTICES];
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            grafo[i][j] = 0;
        }
    }

    printf("Digite os pares de v�rtices conectados (digite -1 para encerrar):\n");
    numArestas = 0;

    while (1) {
        printf("V�rtice de partida: ");
        scanf("%d", &v1);
        if (v1 == -1) break;

        printf("V�rtice de chegada: ");
        scanf("%d", &v2);
        if (v2 == -1) break;

        if (v1 < 1 || v1 > numVertices || v2 < 1 || v2 > numVertices) {
            printf("V�rtices inv�lidos! Digite valores entre 1 e %d.\n", numVertices);
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
        printf("O grafo � uma ESTRELA. V�rtice central: %d\n", verticeCentral + 1);
    else
        printf("O grafo N�O � uma ESTRELA.\n");

    return 0;
}

