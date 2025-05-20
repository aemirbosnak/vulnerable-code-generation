//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 3

void print_matrix(int **matrix)
{
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            printf("%d ", matrix[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    int **matrix = (int **)malloc(ROWS * sizeof(int *));

    for (int r = 0; r < ROWS; r++)
    {
        matrix[r] = (int *)malloc(COLS * sizeof(int));
    }

    // Initializing the matrix with random numbers
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            matrix[r][c] = rand() % 10;
        }
    }

    print_matrix(matrix);

    // Transpose the matrix
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            int tmp = matrix[r][c];
            matrix[r][c] = matrix[c][r];
            matrix[c][r] = tmp;
        }
    }

    print_matrix(matrix);

    // Free the memory
    for (int r = 0; r < ROWS; r++)
    {
        free(matrix[r]);
    }
    free(matrix);

    return 0;
}