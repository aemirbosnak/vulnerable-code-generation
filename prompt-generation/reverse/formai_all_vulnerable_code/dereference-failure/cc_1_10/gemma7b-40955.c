//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the Matrix structure
typedef struct Matrix
{
    int rows;
    int cols;
    double **data;
} Matrix;

// Function to create a Matrix
Matrix* createMatrix(int r, int c)
{
    Matrix* m = (Matrix*)malloc(sizeof(Matrix));
    m->rows = r;
    m->cols = c;
    m->data = (double**)malloc(r * sizeof(double*));
    for (int i = 0; i < r; i++)
    {
        m->data[i] = (double*)malloc(c * sizeof(double));
    }
    return m;
}

// Function to add two Matrices
Matrix* addMatrices(Matrix* a, Matrix* b)
{
    int r = a->rows;
    int c = a->cols;
    Matrix* cMatrix = createMatrix(r, c);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            double sum = 0.0;
            for (int k = 0; k < a->rows; k++)
            {
                for (int l = 0; l < a->cols; l++)
                {
                    sum += a->data[k][l] * b->data[k][l];
                }
            }
            cMatrix->data[i][j] = sum;
        }
    }

    return cMatrix;
}

int main()
{
    // Create two matrices
    Matrix* a = createMatrix(2, 3);
    a->data[0][0] = 1.0;
    a->data[0][1] = 2.0;
    a->data[0][2] = 3.0;
    a->data[1][0] = 4.0;
    a->data[1][1] = 5.0;
    a->data[1][2] = 6.0;

    Matrix* b = createMatrix(2, 3);
    b->data[0][0] = 2.0;
    b->data[0][1] = 3.0;
    b->data[0][2] = 4.0;
    b->data[1][0] = 5.0;
    b->data[1][1] = 6.0;
    b->data[1][2] = 7.0;

    // Add the two matrices
    Matrix* c = addMatrices(a, b);

    // Print the resulting matrix
    for (int i = 0; i < c->rows; i++)
    {
        for (int j = 0; j < c->cols; j++)
        {
            printf("%f ", c->data[i][j]);
        }
        printf("\n");
    }

    return 0;
}