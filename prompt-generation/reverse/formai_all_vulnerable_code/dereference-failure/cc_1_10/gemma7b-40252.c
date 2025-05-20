//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

typedef struct Matrix
{
    int **arr;
    int r, c;
} Matrix;

Matrix *createMatrix(int r, int c)
{
    Matrix *m = (Matrix *)malloc(sizeof(Matrix));
    m->r = r;
    m->c = c;
    m->arr = (int **)malloc(r * sizeof(int *) + c * sizeof(int));
    for (int i = 0; i < r; i++)
        m->arr[i] = (int *)malloc(c * sizeof(int));
    return m;
}

void printMatrix(Matrix *m)
{
    for (int i = 0; i < m->r; i++)
    {
        for (int j = 0; j < m->c; j++)
        {
            printf("%d ", m->arr[i][j]);
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
    Matrix *a = createMatrix(2, 3);
    a->arr[0][0] = 1;
    a->arr[0][1] = 2;
    a->arr[0][2] = 3;
    a->arr[1][0] = 4;
    a->arr[1][1] = 5;
    a->arr[1][2] = 6;

    Matrix *b = createMatrix(2, 3);
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