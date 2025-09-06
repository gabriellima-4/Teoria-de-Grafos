/*
Quest�o 4
Aplica��o simples de grafos. Com o intuito de realizar obras com planejamento de infraestrutura 
rodovi�ria, o governo de um p�is pretende construir n estradas (todas de m�o dupla), sendo que cada estrada liga 
exatamente 2 das cidades. H� um total de �N� cidades. Considere condi��o que uma das cidades s� pode ter uma 
estrada constru�da interligando a qualquer outra cidade. Crie um c�digo em linguagem C onde � solicitado o total 
de cidades �N�, onde � determinado o menor valor de n para que, independente de como as estradas sejam 
constru�das, seja poss�vel viajar entre quaisquer 2 cidades (neste caso, as estradas s�o constru�das tal que 20 das 
mesmas se conectam entre si atrav�s uma �nicada estrada. Dessa forma, uma viagem pode ser feita passando, 
possivelmente, por cidades intermedi�rias, se o condutor/viajante deseja realizar tal op��o). 
*/

#include <stdio.h>

double fatorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * fatorial(n - 1);
}

int main() {
    int numeroCidades, totaldeEstradas;

    printf("Digite o n�mero de cidades: ");
    scanf("%d", &numeroCidades);

    if (numeroCidades < 1) {
        printf("N�mero de cidades inv�lido.\n");
        return 1;
    }

    if (numeroCidades == 1) {
        totaldeEstradas = 0;
    } else {
        totaldeEstradas = fatorial(numeroCidades - 1) / (2 * fatorial(numeroCidades - 3));
    }

    totaldeEstradas += 1;
    printf("O n�mero total de estradas a serem constru�das �: %d\n", totaldeEstradas);

    return 0;
}

