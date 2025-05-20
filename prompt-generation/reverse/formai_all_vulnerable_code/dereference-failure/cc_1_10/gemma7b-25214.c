//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

typedef struct Matrix
{
    int **arr;
    int rows;
    int cols;
} Matrix;

Matrix *createMatrix(int r, int c)
{
    Matrix *mat = (Matrix *)malloc(sizeof(Matrix));
    mat->rows = r;
    mat->cols = c;
    mat->arr = (int **)malloc(r * sizeof(int *) + c * sizeof(int));
    for (int i = 0; i < r; i++)
    {
        mat->arr[i] = (int *)malloc(c * sizeof(int));
    }
    return mat;
}

void destroyMatrix(Matrix *mat)
{
    for (int i = 0; i < mat->rows; i++)
    {
        free(mat->arr[i]);
    }
    free(mat->arr);
    free(mat);
}

Matrix *transpose(Matrix *mat)
{
    Matrix *res = createMatrix(mat->cols, mat->rows);
    for (int i = 0; i < mat->rows; i++)
    {
        for (int j = 0; j < mat->cols; j++)
        {
            res->arr[j][i] = mat->arr[i][j];
        }
    }
    return res;
}

int main()
{
    Matrix *mat = createMatrix(3, 4);
    mat->arr[0][0] = 1;
    mat->arr[0][1] = 2;
    mat->arr[0][2] = 3;
    mat->arr[0][3] = 4;
    mat->arr[1][0] = 5;
    mat->arr[1][1] = 6;
    mat->arr[1][2] = 7;
    mat->arr[1][3] = 8;
    mat->arr[2][0] = 9;
    mat->arr[2][1] = 10;
    mat->arr[2][2] = 11;
    mat->arr[2][3] = 12;

    Matrix *res = transpose(mat);

    for (int i = 0; i < res->rows; i++)
    {
        for (int j = 0; j < res->cols; j++)
        {
            printf("%d ", res->arr[i][j]);
        }
        printf("\n");
    }

    destroyMatrix(mat);
    destroyMatrix(res);

    return 0;
}