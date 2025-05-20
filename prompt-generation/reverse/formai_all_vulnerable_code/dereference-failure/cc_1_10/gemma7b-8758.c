//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

void matrix_operations(int **a, int **b, int **c)
{
    int i, j, k;
    int row1 = *a, col1 = *b, row2 = *c;

    if (row1 != row2)
    {
        printf("Error: Matrices must have the same number of rows.\n");
        return;
    }

    *c = (int *)malloc(row1 * col1 * sizeof(int));

    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < row2; k++)
            {
                if (a[i][k] && b[k][j])
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }

    return;
}

int main()
{
    int **a = NULL, **b = NULL, **c = NULL;

    a = (int **)malloc(ROW * COL * sizeof(int));
    b = (int **)malloc(ROW * COL * sizeof(int));
    c = (int **)malloc(ROW * COL * sizeof(int));

    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[0][3] = 4;
    a[0][4] = 5;

    b[0][0] = 2;
    b[0][1] = 3;
    b[0][2] = 4;
    b[0][3] = 5;
    b[0][4] = 6;

    matrix_operations(&a, &b, &c);

    printf("The product of the two matrices is:\n");

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    free(a);
    free(b);
    free(c);

    return 0;
}