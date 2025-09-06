//Questão 7

#include <stdio.h>

#define NUM_VERTICES_MAX 10

int main() {
    int n = 4; 
    double preco_inicial = 20.0;
    double taxas[] = {0.01, 0.01, 0.02, -0.0389254};
    double precos[NUM_VERTICES_MAX] = {0};

    precos[1] = preco_inicial;

    for (int i = 1; i <= n; i++) {
        precos[i + 1] = precos[i] * (1 + taxas[i - 1]);
    }

    printf("Vértices (Preços):\n");
    for (int i = 1; i <= n + 1; i++) {
        printf("Vértice %d: Preço = %.2f\n", i, precos[i]);
    }

    printf("\nArestas (Taxas):\n");
    for (int i = 1; i <= n; i++) {
        printf("Aresta do Vértice %d para Vértice %d: Taxa = %.5f%%\n",
               i, i + 1, taxas[i - 1] * 100);
    }

    return 0;
}

