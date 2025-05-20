//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Matrix
{
    int **data;
    int rows;
    int cols;
} Matrix;

Matrix* createMatrix(int r, int c)
{
    Matrix* m = malloc(sizeof(Matrix));
    m->rows = r;
    m->cols = c;
    m->data = malloc(r * c * sizeof(int));

    return m;
}

void printMatrix(Matrix* m)
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

Matrix* addMatrix(Matrix* a, Matrix* b)
{
    int r = a->rows + b->rows;
    int c = a->cols + b->cols;

    Matrix* m = createMatrix(r, c);

    for (int r = 0; r < a->rows; r++)
    {
        for (int c = 0; c < a->cols; c++)
        {
            m->data[r][c] = a->data[r][c] + b->data[r][c];
        }
    }

    return m;
}

int main()
{
    Matrix* a = createMatrix(2, 3);
    a->data[0][0] = 1;
    a->data[0][1] = 2;
    a->data[0][2] = 3;
    a->data[1][0] = 4;
    a->data[1][1] = 5;
    a->data[1][2] = 6;

    Matrix* b = createMatrix(2, 3);
    b->data[0][0] = 7;
    b->data[0][1] = 8;
    b->data[0][2] = 9;
    b->data[1][0] = 10;
    b->data[1][1] = 11;
    b->data[1][2] = 12;

    Matrix* c = addMatrix(a, b);

    printMatrix(c);

    return 0;
}