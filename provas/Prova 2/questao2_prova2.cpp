#include <stdio.h>
#define NUM_VERTICES_MAX 10
int main(){
	int n = 4;
	double preco_inicial = 22.00;
	double taxas[] = {0.01, 0.04, 0.01, -0.057408}; // Não entendi o porque dessa última taxa negativa do gabarito.
													// O Preço inicial de 22.00 somada ao produto dele com essa taxa
													// na forma positiva não equivale o valor final de 23.34.
													// 22.00 + (22.00 * 0.057408 = 23.262976 /= 23.34)
	double precos[NUM_VERTICES_MAX] = {0};
	precos[1] = preco_inicial;
	for (int i = 1; i <= n; i++){
		precos[i + 1] = precos[i] * (1 + taxas[i - 1]);
	}
	printf("Vertices (Precos):\n");
	for (int i = 1; i<= n; i++){
		if (i < n + 1){
			printf("Vertice %d: Preco = %.2f\n", i, precos[i]);
		} else {
			printf("Vertice %d: Preco = %.2f\n", i-n, precos[i]);
		}
	}
	printf("\nArestas (Taxas): \n");
	for (int i = 1; i <= n+1; i++){    // Não entendi o porque do n+1.
										// Com ele, é criada uma ligação desnecessária do vértice 5 ao 2, com uma taxa zerada.
		if (i < n){
			printf("Aresta do vertice %d para o vertice %d: Taxa = %.5f%%\n", i, i+1, taxas[i-1] * 100);
		} else {
			printf("Aresta do vertice %d para o vertice %d: Taxa = %.5f%%\n", i, i-n+1, taxas[i-1] * 100);
		}
	}
}
