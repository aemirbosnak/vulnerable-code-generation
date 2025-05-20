//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

typedef struct Matrix
{
    int **arr;
    int r, c;
} Matrix;

Matrix *createMatrix(int r, int c)
{
    Matrix *mat = (Matrix *)malloc(sizeof(Matrix));
    mat->r = r;
    mat->c = c;
    mat->arr = (int **)malloc(r * sizeof(int *) + c * sizeof(int));
    for (int i = 0; i < r; i++)
    {
        mat->arr[i] = (int *)malloc(c * sizeof(int));
    }
    return mat;
}

void displayMatrix(Matrix *mat)
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

int main()
{
    Matrix *mat = createMatrix(ROWS, COLS);
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

    displayMatrix(mat);

    free(mat->arr);
    free(mat);

    return 0;
}