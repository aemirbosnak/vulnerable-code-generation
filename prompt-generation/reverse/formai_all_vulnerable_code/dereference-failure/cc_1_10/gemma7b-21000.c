//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix
{
    int rows;
    int cols;
    double **data;
} Matrix;

Matrix *createMatrix(int r, int c)
{
    Matrix *m = (Matrix *)malloc(sizeof(Matrix));
    m->rows = r;
    m->cols = c;
    m->data = (double **)malloc(r * sizeof(double *) + c * sizeof(double));
    for (int i = 0; i < r; i++)
    {
        m->data[i] = (double *)malloc(c * sizeof(double));
    }
    return m;
}

void printMatrix(Matrix *m)
{
    for (int i = 0; i < m->rows; i++)
    {
        for (int j = 0; j < m->cols; j++)
        {
            printf("%f ", m->data[i][j]);
        }
        printf("\n");
    }
}

Matrix *addMatrix(Matrix *a, Matrix *b)
{
    Matrix *c = createMatrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++)
    {
        for (int j = 0; j < a->cols; j++)
        {
            c->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return c;
}

int main()
{
    Matrix *a = createMatrix(2, 3);
    a->data[0][0] = 1.2;
    a->data[0][1] = 2.3;
    a->data[0][2] = 3.4;
    a->data[1][0] = 4.5;
    a->data[1][1] = 5.6;
    a->data[1][2] = 6.7;

    Matrix *b = createMatrix(2, 3);
    b->data[0][0] = 2.4;
    b->data[0][1] = 3.5;
    b->data[0][2] = 4.6;
    b->data[1][0] = 5.7;
    b->data[1][1] = 6.8;
    b->data[1][2] = 7.9;

    Matrix *c = addMatrix(a, b);

    printMatrix(c);

    return 0;
}