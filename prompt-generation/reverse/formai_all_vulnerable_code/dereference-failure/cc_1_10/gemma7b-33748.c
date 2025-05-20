//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 5
#define COLS 5

void initialize_matrix(int **matrix, int r, int c)
{
    matrix = (int **)malloc(r * sizeof(int *) + c * sizeof(int));
    for(int i = 0; i < r; i++)
    {
        matrix[i] = (int *)malloc(c * sizeof(int));
    }
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void print_matrix(int **matrix, int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int **matrix;
    initialize_matrix(&matrix, ROWS, COLS);

    // Simulate some operations
    matrix[1][2] = 10;
    matrix[2][3] = 20;
    matrix[3][1] = 30;

    print_matrix(matrix, ROWS, COLS);

    free(matrix);

    return 0;
}