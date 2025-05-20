//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 5
#define COLS 6

typedef struct Matrix
{
    int **data;
    int rows;
    int cols;
} Matrix;

Matrix *createMatrix(int r, int c)
{
    Matrix *m = malloc(sizeof(Matrix));
    m->rows = r;
    m->cols = c;
    m->data = malloc(r * c * sizeof(int));
    return m;
}

void printMatrix(Matrix *m)
{
    for (int r = 0; r < m->rows; r++)
    {
        for (int c = 0; c < m->cols; c++)
        {
            printf("%d ", m->data[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    Matrix *a = createMatrix(ROWS, COLS);

    a->data[0][0] = 1;
    a->data[0][1] = 2;
    a->data[0][2] = 3;
    a->data[0][3] = 4;
    a->data[0][4] = 5;
    a->data[0][5] = 6;

    a->data[1][0] = 7;
    a->data[1][1] = 8;
    a->data[1][2] = 9;
    a->data[1][3] = 10;
    a->data[1][4] = 11;
    a->data[1][5] = 12;

    printMatrix(a);

    return 0;
}