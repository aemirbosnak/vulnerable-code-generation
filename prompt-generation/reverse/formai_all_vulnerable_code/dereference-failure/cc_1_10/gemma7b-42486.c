//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define the Matrix structure
    struct Matrix
    {
        int rows;
        int cols;
        double **data;
    };

    // Create a Matrix object
    struct Matrix *matrix = malloc(sizeof(struct Matrix));
    matrix->rows = 3;
    matrix->cols = 4;
    matrix->data = malloc(sizeof(double *) * matrix->rows);
    for (int i = 0; i < matrix->rows; i++)
    {
        matrix->data[i] = malloc(sizeof(double) * matrix->cols);
    }

    // Initialize the matrix with some values
    matrix->data[0][0] = 1;
    matrix->data[0][1] = 2;
    matrix->data[0][2] = 3;
    matrix->data[0][3] = 4;
    matrix->data[1][0] = 5;
    matrix->data[1][1] = 6;
    matrix->data[1][2] = 7;
    matrix->data[1][3] = 8;
    matrix->data[2][0] = 9;
    matrix->data[2][1] = 10;
    matrix->data[2][2] = 11;
    matrix->data[2][3] = 12;

    // Print the matrix
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->cols; j++)
        {
            printf("%f ", matrix->data[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the matrix
    for (int i = 0; i < matrix->rows; i++)
    {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);

    return 0;
}