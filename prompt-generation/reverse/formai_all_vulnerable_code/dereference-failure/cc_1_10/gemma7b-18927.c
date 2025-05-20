//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix
{
    int **data;
    int rows;
    int cols;
} Matrix;

Matrix *createMatrix(int r, int c)
{
    Matrix *m = (Matrix *)malloc(sizeof(Matrix));
    m->rows = r;
    m->cols = c;
    m->data = (int **)malloc(r * sizeof(int *) + c * sizeof(int));
    for (int i = 0; i < r; i++)
        m->data[i] = (int *)malloc(c * sizeof(int));
    return m;
}

void printMatrix(Matrix *m)
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

int main()
{
    Matrix *m = createMatrix(3, 4);
    m->data[0][0] = 1;
    m->data[0][1] = 2;
    m->data[0][2] = 3;
    m->data[0][3] = 4;
    m->data[1][0] = 5;
    m->data[1][1] = 6;
    m->data[1][2] = 7;
    m->data[1][3] = 8;
    m->data[2][0] = 9;
    m->data[2][1] = 10;
    m->data[2][2] = 11;
    m->data[2][3] = 12;

    printMatrix(m);

    free(m->data[0]);
    free(m->data);
    free(m);

    return 0;
}