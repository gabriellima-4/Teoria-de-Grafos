#include <stdio.h>

//Função para calcular a rentabilidade ao longo do período
double taxaacumulada (double taxas[], int mes){
	double acumulada = 1.0;
	
	for (int i = 0; i <= mes; i++) {
	acumulada *= (1 + taxas[i]);
	}
	
	return acumulada - 1;
}

int main(){
	//Vetor contendo as taxas mensais de rentabilidade do CDI
	double taxas [12] = { 0.0112, 0.0092, 0.0117, 0.0092, 0.0112, 0.0107, 0.0107, 0.0114, 0.0097, 0.01, 0.0092, 0.0089};
	
	// Array para armazenar o grafo (conexões entre os meses com as taxas de rentabilidade)
	double grafo[13][13]; // Grafo com 13 vértices e 13 arestas (meses)
	
 	// Inicializando o grafo com 0
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			grafo[i][j] = 0; // Sem arestas ainda
		}
	}
	
	// Preenchendo as arestas com as taxas de rentabilidade
	for (int i = 0; i < 12; i++) {
		// Aresta entre os meses consecutivos com a taxa mensal correspondente
		grafo[i][i + 1] = taxas[i];
	}
	
	// Calculando a rentabilidade acumulada e conectando o mês de dezembro anterior até o mês de dezembro seguinte
	for (int i = 0; i < 12; i++) {
		grafo[0][i + 1] = taxaacumulada(taxas, i); // Arestas para as taxas acumuladas
	}
	
	// Exibindo as arestas do grafo (taxas de rentabilidade)
	printf("\nArestas (taxas de rentabilidade entre os meses):\n");
	for (int i = 0; i < 12; i++) {
		printf("Taxa de %d para %d: %.4f%%\n", i + 1, i + 2, taxas[i] * 100);
	}
	
	
	// Exibindo as arestas acumuladas
	printf("\nRentabilidade acumulada (de dezembro a cada mês):\n");
	for (int i = 0; i < 12; i++) {
		printf("Acumulada de dezembro para %d: %.4f%%\n", i + 2, grafo[0][i + 1] *100);
	}
	
	return 0;
}



