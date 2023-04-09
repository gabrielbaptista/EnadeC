// Enade2017.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define LIN 4
#define COL 4


/*
    i-1,j-1 | i-1,j   | i-1,j+1
    i,j-1   | i,j     | i, j+1
    i+1,j-1 | i+1,j   | i+1, j+1
*/
void atualizaAutonomo(unsigned char** M, int i, int j) {
    unsigned char estadoAtualCelula = 0;
    int qtdVizinhosVivos = 0;
    int qtdVizinhosMortos = 0;
    for (int l = i - 1; l <= i + 1; l++)
    {
        for (int c = j - 1; c <= j + 1; c++)
        {
            if ((l >= 0) && (c >= 0) && (l < LIN) && c < COL)
            {
                if ((l == i) && (c == j))
                {
                    estadoAtualCelula = M[l][c];
                }
                else
                {
                    if (M[l][c] == 1)
                        qtdVizinhosVivos++;
                    else
                        qtdVizinhosMortos++;
                }
            }
        }
    }
    if (estadoAtualCelula == 1) // célula viva
    {
        if (qtdVizinhosVivos <  2)
            M[i][j] = 0; // solidão
        if (qtdVizinhosVivos > 3)
            M[i][j] = 0; // superpopulação
    }
    else
    {
        if (qtdVizinhosVivos == 3)
            M[i][j] = 1; // reativando a célula
    }
}


int main()
{
    unsigned char** matriz = (unsigned char**)malloc(LIN * sizeof(unsigned char*));
    for (int i = 0; i < LIN; i++) {
        matriz[i] = (unsigned char*)malloc(COL * sizeof(unsigned char));
    }

    srand(time(NULL));

    for (int i = 0; i < LIN; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            int random_number = rand() % 100;
            if ( (random_number % 2) == 0)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }

    for (int i = 0; i < LIN; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            atualizaAutonomo(matriz, i, j);
        }
    }
    
    free(matriz);

    std::cout << "Hello World!\n";
}