//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

void matrix_operations(int **arr)
{
    int i, j, k;

    // Transpose the matrix
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            for (k = 0; k < COL; k++)
            {
                arr[k][j] = arr[j][k];
            }
        }
    }

    // Multiply the matrix by a scalar
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            arr[i][j] *= 2;
        }
    }

    // Print the matrix
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int **arr = NULL;

    // Allocate memory for the matrix
    arr = (int **)malloc(ROW * sizeof(int *));
    for (int i = 0; i < ROW; i++)
    {
        arr[i] = (int *)malloc(COL * sizeof(int));
    }

    // Initialize the matrix
    arr[0][0] = 1;
    arr[0][1] = 2;
    arr[0][2] = 3;
    arr[0][3] = 4;
    arr[0][4] = 5;

    arr[1][0] = 6;
    arr[1][1] = 7;
    arr[1][2] = 8;
    arr[1][3] = 9;
    arr[1][4] = 10;

    arr[2][0] = 11;
    arr[2][1] = 12;
    arr[2][2] = 13;
    arr[2][3] = 14;
    arr[2][4] = 15;

    arr[3][0] = 16;
    arr[3][1] = 17;
    arr[3][2] = 18;
    arr[3][3] = 19;
    arr[3][4] = 20;

    arr[4][0] = 21;
    arr[4][1] = 22;
    arr[4][2] = 23;
    arr[4][3] = 24;
    arr[4][4] = 25;

    matrix_operations(arr);

    // Free the memory allocated for the matrix
    for (int i = 0; i < ROW; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}