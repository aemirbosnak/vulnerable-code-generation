//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Matrix
{
    int **arr;
    int rows;
    int cols;
} Matrix;

Matrix *createMatrix(int r, int c)
{
    Matrix *m = (Matrix *)malloc(sizeof(Matrix));
    m->rows = r;
    m->cols = c;
    m->arr = (int **)malloc(r * sizeof(int *) + c * sizeof(int));
    for (int i = 0; i < r; i++)
    {
        m->arr[i] = (int *)malloc(c * sizeof(int));
    }
    return m;
}

void destroyMatrix(Matrix *m)
{
    for (int i = 0; i < m->rows; i++)
    {
        free(m->arr[i]);
    }
    free(m->arr);
    free(m);
}

Matrix *transpose(Matrix *m)
{
    Matrix *n = createMatrix(m->cols, m->rows);
    for (int i = 0; i < m->rows; i++)
    {
        for (int j = 0; j < m->cols; j++)
        {
            n->arr[j][i] = m->arr[i][j];
        }
    }
    destroyMatrix(m);
    return n;
}

int main()
{
    Matrix *m = createMatrix(2, 3);
    m->arr[0][0] = 1;
    m->arr[0][1] = 2;
    m->arr[0][2] = 3;
    m->arr[1][0] = 4;
    m->arr[1][1] = 5;
    m->arr[1][2] = 6;

    Matrix *n = transpose(m);

    for (int i = 0; i < n->rows; i++)
    {
        for (int j = 0; j < n->cols; j++)
        {
            printf("%d ", n->arr[i][j]);
        }
        printf("\n");
    }

    destroyMatrix(n);
    destroyMatrix(m);

    return 0;
}