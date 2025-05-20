//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 5
#define COLS 5

typedef struct Matrix
{
    int **arr;
    int r;
    int c;
} Matrix;

Matrix *createMatrix(int r, int c)
{
    Matrix *mat = (Matrix *)malloc(sizeof(Matrix));
    mat->r = r;
    mat->c = c;
    mat->arr = (int **)malloc(r * sizeof(int *) + c * sizeof(int));
    for (int i = 0; i < mat->r; i++)
    {
        mat->arr[i] = (int *)malloc(c * sizeof(int));
    }
    return mat;
}

void printMatrix(Matrix *mat)
{
    for (int i = 0; i < mat->r; i++)
    {
        for (int j = 0; j < mat->c; j++)
        {
            printf("%d ", mat->arr[i][j]);
        }
        printf("\n");
    }
}

Matrix *addMatrix(Matrix *a, Matrix *b)
{
    Matrix *c = createMatrix(a->r, a->c);
    for (int i = 0; i < a->r; i++)
    {
        for (int j = 0; j < a->c; j++)
        {
            c->arr[i][j] = a->arr[i][j] + b->arr[i][j];
        }
    }
    return c;
}

int main()
{
    Matrix *a = createMatrix(ROWS, COLS);
    a->arr[0][0] = 1;
    a->arr[0][1] = 2;
    a->arr[0][2] = 3;
    a->arr[1][0] = 4;
    a->arr[1][1] = 5;
    a->arr[1][2] = 6;

    Matrix *b = createMatrix(ROWS, COLS);
    b->arr[0][0] = 2;
    b->arr[0][1] = 3;
    b->arr[0][2] = 4;
    b->arr[1][0] = 5;
    b->arr[1][1] = 6;
    b->arr[1][2] = 7;

    Matrix *c = addMatrix(a, b);

    printMatrix(c);

    return 0;
}