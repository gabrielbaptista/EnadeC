// Enade2019.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int executaRecursividade(int m, int n) {
    if (m == n)
        return (n + (1 / n));
    else
        return (m + (1 / m)) * executaRecursividade(m + 1, n);
}

void recursiva() {
    int m;
    int n;
    printf("Entre com os valores m e n: ");
    scanf_s("%d %d", &m, &n);

    if ((m <= n) && (m > 0)) {
        int retorno = executaRecursividade(m, n);
        printf("Resultado eh %d\n", retorno);
    }
    else
        printf("Dados inválidos!\n");
        
}


int main()
{
    recursiva();
}
