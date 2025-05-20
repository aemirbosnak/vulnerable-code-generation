//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 5
#define COLS 5

int main()
{
    // Define a 2D array
    int **arr = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++)
    {
        arr[i] = (int *)malloc(COLS * sizeof(int));
    }

    // Initialize the array
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            arr[r][c] = rand() % 10;
        }
    }

    // Transpose the array
    int **trans = (int **)malloc(COLS * sizeof(int *));
    for (int i = 0; i < COLS; i++)
    {
        trans[i] = (int *)malloc(ROWS * sizeof(int));
    }

    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            trans[c][r] = arr[r][c];
        }
    }

    // Print the transposed array
    for (int r = 0; r < COLS; r++)
    {
        for (int c = 0; c < ROWS; c++)
        {
            printf("%d ", trans[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < ROWS; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}