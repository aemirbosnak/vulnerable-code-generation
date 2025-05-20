//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 3

typedef struct Matrix
{
    int **arr;
    int r;
    int c;
} Matrix;

Matrix* matrix_init(int r, int c)
{
    Matrix* m = (Matrix*)malloc(sizeof(Matrix));
    m->r = r;
    m->c = c;
    m->arr = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++)
    {
        m->arr[i] = (int*)malloc(c * sizeof(int));
    }
    return m;
}

void matrix_set(Matrix* m, int r, int c, int val)
{
    m->arr[r][c] = val;
}

int matrix_get(Matrix* m, int r, int c)
{
    return m->arr[r][c];
}

int main()
{
    Matrix* love = matrix_init(ROW, COL);
    matrix_set(love, 0, 0, 10);
    matrix_set(love, 1, 1, 20);
    matrix_set(love, 2, 2, 30);

    int value = matrix_get(love, 1, 1);
    printf("The value at (1, 1) is: %d\n", value);

    free(love->arr);
    free(love);

    return 0;
}