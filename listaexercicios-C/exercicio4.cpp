/*
Questão 4
Aplicação simples de grafos. Com o intuito de realizar obras com planejamento de infraestrutura 
rodoviária, o governo de um páis pretende construir n estradas (todas de mão dupla), sendo que cada estrada liga 
exatamente 2 das cidades. Há um total de “N” cidades. Considere condição que uma das cidades só pode ter uma 
estrada construída interligando a qualquer outra cidade. Crie um código em linguagem C onde é solicitado o total 
de cidades “N”, onde é determinado o menor valor de n para que, independente de como as estradas sejam 
construídas, seja possível viajar entre quaisquer 2 cidades (neste caso, as estradas são construídas tal que 20 das 
mesmas se conectam entre si através uma únicada estrada. Dessa forma, uma viagem pode ser feita passando, 
possivelmente, por cidades intermediárias, se o condutor/viajante deseja realizar tal opção). 
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

    printf("Digite o número de cidades: ");
    scanf("%d", &numeroCidades);

    if (numeroCidades < 1) {
        printf("Número de cidades inválido.\n");
        return 1;
    }

    if (numeroCidades == 1) {
        totaldeEstradas = 0;
    } else {
        totaldeEstradas = fatorial(numeroCidades - 1) / (2 * fatorial(numeroCidades - 3));
    }

    totaldeEstradas += 1;
    printf("O número total de estradas a serem construídas é: %d\n", totaldeEstradas);

    return 0;
}

