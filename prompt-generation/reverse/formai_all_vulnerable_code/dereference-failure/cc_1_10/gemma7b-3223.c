//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

typedef struct Matrix
{
    int **data;
    int rows;
    int cols;
} Matrix;

Matrix* createMatrix(int r, int c)
{
    Matrix* m = (Matrix*)malloc(sizeof(Matrix));
    m->rows = r;
    m->cols = c;
    m->data = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++)
    {
        m->data[i] = (int*)malloc(c * sizeof(int));
    }
    return m;
}

void printMatrix(Matrix* m)
{
    for (int i = 0; i < m->rows; i++)
    {
        for (int j = 0; j < m->cols; j++)
        {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

Matrix* transpose(Matrix* m)
{
    Matrix* t = createMatrix(m->cols, m->rows);
    for (int i = 0; i < m->rows; i++)
    {
        for (int j = 0; j < m->cols; j++)
        {
            t->data[j][i] = m->data[i][j];
        }
    }
    return t;
}

int main()
{
    Matrix* m = createMatrix(2, 3);
    m->data[0][0] = 1;
    m->data[0][1] = 2;
    m->data[0][2] = 3;
    m->data[1][0] = 4;
    m->data[1][1] = 5;
    m->data[1][2] = 6;

    printMatrix(m);

    Matrix* t = transpose(m);

    printMatrix(t);

    return 0;
}