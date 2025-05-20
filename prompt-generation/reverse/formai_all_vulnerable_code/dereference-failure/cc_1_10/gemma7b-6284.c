//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Matrix
{
    int **arr;
    int r;
    int c;
} Matrix;

Matrix *createMatrix(int r, int c)
{
    Matrix *mat = malloc(sizeof(Matrix));
    mat->r = r;
    mat->c = c;
    mat->arr = malloc(r * c * sizeof(int));
    return mat;
}

void destroyMatrix(Matrix *mat)
{
    free(mat->arr);
    free(mat);
}

void multiplyMatrix(Matrix *a, Matrix *b, Matrix *c)
{
    int i, j, k;
    c->r = a->r;
    c->c = b->c;
    c->arr = malloc(c->r * c->c * sizeof(int));

    for (i = 0; i < a->r; i++)
    {
        for (j = 0; j < b->c; j++)
        {
            for (k = 0; k < b->r; k++)
            {
                int product = 0;
                for (int l = 0; l < a->c; l++)
                {
                    product += a->arr[i][l] * b->arr[k][l] * c->arr[i][j];
                }
                c->arr[i][j] = product;
            }
        }
    }
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

    Matrix *b = createMatrix(3, 2);
    b->arr[0][0] = 1;
    b->arr[0][1] = 2;
    b->arr[1][0] = 3;
    b->arr[1][1] = 4;
    b->arr[2][0] = 5;
    b->arr[2][1] = 6;

    Matrix *c = createMatrix(2, 2);

    multiplyMatrix(a, b, c);

    for (int i = 0; i < c->r; i++)
    {
        for (int j = 0; j < c->c; j++)
        {
            printf("%d ", c->arr[i][j]);
        }
        printf("\n");
    }

    destroyMatrix(a);
    destroyMatrix(b);
    destroyMatrix(c);

    return 0;
}