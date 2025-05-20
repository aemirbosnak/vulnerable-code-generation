//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 5, b = 3, c = 2;
    int **matrix = NULL;

    // Dynamic memory allocation
    matrix = (int**)malloc(a * sizeof(int*));
    for (int i = 0; i < a; i++)
    {
        matrix[i] = (int*)malloc(b * sizeof(int));
    }

    // Matrix initialization
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            matrix[i][j] = 0;
        }
    }

    // Matrix operations
    for (int i = 0; i < c; i++)
    {
        int row1 = rand() % a;
        int col1 = rand() % b;
        int row2 = rand() % a;
        int col2 = rand() % b;

        matrix[row1][col1] = 1;
        matrix[row2][col2] = 1;
    }

    // Matrix display
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < a; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}