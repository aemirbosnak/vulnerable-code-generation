//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: enthusiastic
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

    // Create two Matrix objects
    struct Matrix *matrixA = malloc(sizeof(struct Matrix));
    matrixA->rows = 3;
    matrixA->cols = 4;
    matrixA->data = (double **)malloc(matrixA->rows * sizeof(double *));
    for (int r = 0; r < matrixA->rows; r++)
    {
        matrixA->data[r] = (double *)malloc(matrixA->cols * sizeof(double));
    }

    struct Matrix *matrixB = malloc(sizeof(struct Matrix));
    matrixB->rows = 2;
    matrixB->cols = 3;
    matrixB->data = (double **)malloc(matrixB->rows * sizeof(double *));
    for (int r = 0; r < matrixB->rows; r++)
    {
        matrixB->data[r] = (double *)malloc(matrixB->cols * sizeof(double));
    }

    // Initialize the Matrix elements
    matrixA->data[0][0] = 1.2;
    matrixA->data[0][1] = 2.3;
    matrixA->data[0][2] = 3.4;
    matrixA->data[0][3] = 4.5;
    matrixA->data[1][0] = 5.6;
    matrixA->data[1][1] = 6.7;
    matrixA->data[1][2] = 7.8;
    matrixA->data[1][3] = 8.9;
    matrixA->data[2][0] = 9.1;
    matrixA->data[2][1] = 10.2;
    matrixA->data[2][2] = 11.3;
    matrixA->data[2][3] = 12.4;

    matrixB->data[0][0] = 13.5;
    matrixB->data[0][1] = 14.6;
    matrixB->data[0][2] = 15.7;
    matrixB->data[1][0] = 16.8;
    matrixB->data[1][1] = 17.9;
    matrixB->data[1][2] = 18.10;

    // Perform Matrix Multiplication
    struct Matrix *product = malloc(sizeof(struct Matrix));
    product->rows = matrixA->rows;
    product->cols = matrixB->cols;
    product->data = (double **)malloc(product->rows * sizeof(double *));
    for (int r = 0; r < product->rows; r++)
    {
        product->data[r] = (double *)malloc(product->cols * sizeof(double));
    }

    for (int r = 0; r < product->rows; r++)
    {
        for (int c = 0; c < product->cols; c++)
        {
            product->data[r][c] = 0.0;
            for (int i = 0; i < matrixA->cols; i++)
            {
                for (int j = 0; j < matrixB->rows; j++)
                {
                    product->data[r][c] += matrixA->data[r][i] * matrixB->data[i][j] / 2.0;
                }
            }
        }
    }

    // Print the product Matrix
    for (int r = 0; r < product->rows; r++)
    {
        for (int c = 0; c < product->cols; c++)
        {
            printf("%f ", product->data[r][c]);
        }
        printf("\n");
    }

    // Free the memory allocated for the Matrices and the product Matrix
    free(matrixA);
    free(matrixB);
    free(product);

    return 0;
}