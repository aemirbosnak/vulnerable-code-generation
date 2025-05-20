//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

void print_matrix(int **arr)
{
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            printf("%d ", arr[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    int **arr = (int **)malloc(ROWS * sizeof(int *));
    for (int r = 0; r < ROWS; r++)
    {
        arr[r] = (int *)malloc(COLS * sizeof(int));
    }

    // Initializing the matrix
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            arr[r][c] = rand() % 10;
        }
    }

    print_matrix(arr);

    // Transpose the matrix
    int **arr_t = (int **)malloc(COLS * sizeof(int *));
    for (int r = 0; r < COLS; r++)
    {
        arr_t[r] = (int *)malloc(ROWS * sizeof(int));
    }

    for (int r = 0; r < COLS; r++)
    {
        for (int c = 0; c < ROWS; c++)
        {
            arr_t[r][c] = arr[c][r];
        }
    }

    print_matrix(arr_t);

    // Free the memory
    for (int r = 0; r < ROWS; r++)
    {
        free(arr[r]);
    }
    free(arr);

    for (int r = 0; r < COLS; r++)
    {
        free(arr_t[r]);
    }
    free(arr_t);

    return 0;
}