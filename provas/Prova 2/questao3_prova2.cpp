#include <stdio.h>
int main(){
	float vertices_precos[4] = {5.00, 10.00, 13.00, 18.00};
	float arestas[3];
	float taxatotal_acumulada = 0;
	for (int i = 0; i < 3; i++){
		arestas[i] = ((vertices_precos[i+1] - vertices_precos[i]) / vertices_precos[i] * 100);
	}
	taxatotal_acumulada = ((vertices_precos[3] - vertices_precos[0]) / vertices_precos[0] * 100);
	printf("Precos nos vertices:\n");
	printf("Vertice 1 - Produtor (custo producao): R$ %.2f\n", vertices_precos[0]);
	printf("Vertice 2 - Distribuidor/Atacadista: R$ %.2f\n", vertices_precos[1]);
	printf("Vertice 3 - Varejista: R$ %.2f\n", vertices_precos[2]);
	printf("Vertice 4 - Consumidor Final: R$ %.2f\n", vertices_precos[3]);
	printf("\n Percentuais de acrescimo nas arestas:\n");
	for (int i = 0; i < 3; i++){
		printf("Acrescimo do vertice %d para o vertice %d: %.2f%%\n", i+1, i+2, arestas[i]);
	}
	printf("\nTaxa total de acrescimo acumulada: %.2f%%\n", taxatotal_acumulada);
	return 0;
}
