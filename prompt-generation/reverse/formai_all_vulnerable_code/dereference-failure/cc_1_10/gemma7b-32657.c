//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 20

void Matrix_Op(int **arr, int row, int col, char **op, int opr)
{
    switch (opr)
    {
        case 1:
            printf("Performing Matrix Addition...\n");
            for (int r = 0; r < row; r++)
            {
                for (int c = 0; c < col; c++)
                {
                    arr[r][c] = arr[r][c] + opr;
                }
            }
            break;
        case 2:
            printf("Performing Matrix Subtraction...\n");
            for (int r = 0; r < row; r++)
            {
                for (int c = 0; c < col; c++)
                {
                    arr[r][c] = arr[r][c] - opr;
                }
            }
            break;
        case 3:
            printf("Performing Matrix Multiplication...\n");
            int **res = (int **)malloc(MAX_ROWS * MAX_COLS * sizeof(int *));
            for (int r = 0; r < MAX_ROWS; r++)
            {
                res[r] = (int *)malloc(MAX_COLS * sizeof(int));
            }

            for (int r = 0; r < row; r++)
            {
                for (int c = 0; c < col; c++)
                {
                    for (int k = 0; k < MAX_COLS; k++)
                    {
                        res[r][k] = 0;
                        for (int l = 0; l < MAX_ROWS; l++)
                        {
                            res[r][k] += arr[l][c] * arr[r][l];
                        }
                    }
                }
            }

            printf("The Result Matrix is:\n");
            for (int r = 0; r < row; r++)
            {
                for (int c = 0; c < col; c++)
                {
                    printf("%d ", res[r][c]);
                }
                printf("\n");
            }

            free(res);
            break;
    }
}

int main()
{
    int **arr = (int **)malloc(MAX_ROWS * MAX_COLS * sizeof(int *));
    for (int r = 0; r < MAX_ROWS; r++)
    {
        arr[r] = (int *)malloc(MAX_COLS * sizeof(int));
    }

    // Sample Matrix Data
    arr[0][0] = 10;
    arr[0][1] = 20;
    arr[1][0] = 30;
    arr[1][1] = 40;

    char **op = malloc(20 * sizeof(char));
    op[0] = 'A';
    op[1] = 'D';
    op[2] = 'M';

    int opr = 10;

    Matrix_Op(arr, 2, 2, op, opr);

    free(arr);
    free(op);

    return 0;
}