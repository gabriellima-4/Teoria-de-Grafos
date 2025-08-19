/*
QUESTÃO 01 
Arestas, vértices e grau de um grafo. Crie um código em linguagem C que implemente um grafo simples 
contendo 3 vértices e 3 arestas, onde será mostrado como resultado via saída o grau de cada vértice, a ordem do 
grafo, o grau médio, bem como o tamanho do grafo. 
*/

#include <stdio.h>

#define numVertices 3
#define numArestas 3

void descreverGrafo (int grafo[numVertices][numArestas]){
	int ordem = numVertices;
	int tamanho = numArestas;
	printf("Ordem do grafo: %d vertices\n", ordem);
	printf("Tamanho do grafo: %d arestas\n", tamanho);
	printf("Grau de cada vertice: \n");
	
	int somaGrau = 0;
	for (int i = 0; i < numVertices; i++){
		int grau = 0;
		
		for (int j = 0; i < numVertices; j++){
			if (grafo[i][j] == 1 || grafo[j][i] == 1){
				grau++;
			}
		}
		
		somaGrau = somaGrau + grau;
		printf("Vertice número %d: %d\n", i, grau);
	}
	
	float grauMedio = 0.0;
	int contador = 0;
	int totalArestas = 0;
	
	grauMedio = somaGrau / (float)numVertices;
	contador = 0;
	
	
	for(int i = 0; i < numVertices; i++){
		for (int j = 0; j < numVertices; j++){
			if (grafo[i][j] == 1){
				contador++;
			}
		}
		if (contador > totalArestas){
			totalArestas = contador;
		}
	}
	
	printf("Tamanho do grafo: %d\n", totalArestas);
	printf("Grau medio do grafo: %f\n", grauMedio);	
	
}

int main(){
	int grafo[numVertices][numArestas] = {0};
	
	grafo[0][1] = 1;
	grafo[1][2] = 1;
	grafo[2][0] = 1;
	
	descreverGrafo(grafo);
	return 0;
}
