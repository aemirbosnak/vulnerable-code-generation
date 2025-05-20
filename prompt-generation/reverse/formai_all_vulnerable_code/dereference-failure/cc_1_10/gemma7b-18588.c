//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

int main()
{
    int **arr = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++)
    {
        arr[i] = (int *)malloc(COLS * sizeof(int));
    }

    // Initializing the matrix with some values
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

    // Performing the Matrix Operations
    int **res = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++)
    {
        res[i] = (int *)malloc(COLS * sizeof(int));
    }

    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            res[r][c] = 0;
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS; j++)
                {
                    if (arr[i][j] != 0)
                    {
                        res[r][c] += arr[i][j] * 2;
                    }
                }
            }
        }
    }

    // Printing the result
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            printf("%d ", res[r][c]);
        }
        printf("\n");
    }

    free(arr);
    free(res);

    return 0;
}