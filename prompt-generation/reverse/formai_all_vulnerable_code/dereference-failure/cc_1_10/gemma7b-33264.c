//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 5, b = 3, c = 2;

    // Create a 3x2 matrix
    int **arr = (int **)malloc(c * sizeof(int *));
    for (int i = 0; i < c; i++)
    {
        arr[i] = (int *)malloc(b * sizeof(int));
    }

    // Initialize the matrix with sample values
    arr[0][0] = 10;
    arr[0][1] = 20;
    arr[1][0] = 30;
    arr[1][1] = 40;
    arr[2][0] = 50;
    arr[2][1] = 60;

    // Transpose the matrix
    int **arr_t = (int **)malloc(b * sizeof(int *));
    for (int i = 0; i < b; i++)
    {
        arr_t[i] = (int *)malloc(c * sizeof(int));
    }

    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < c; j++)
        {
            arr_t[i][j] = arr[j][i];
        }
    }

    // Print the transposed matrix
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", arr_t[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < c; i++)
    {
        free(arr[i]);
    }
    free(arr);

    for (int i = 0; i < b; i++)
    {
        free(arr_t[i]);
    }
    free(arr_t);

    return 0;
}