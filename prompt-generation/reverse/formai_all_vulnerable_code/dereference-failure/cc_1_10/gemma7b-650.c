//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int **a = (int **)malloc(MAX * sizeof(int *));
    for (int i = 0; i < MAX; i++)
    {
        a[i] = (int *)malloc(MAX * sizeof(int));
    }

    int r = 0, c = 0, i = 0;

    // Generate a random 2D array
    for (r = 0; r < MAX; r++)
    {
        for (c = 0; c < MAX; c++)
        {
            a[r][c] = rand() % 10;
        }
    }

    // Transpose the array
    for (r = 0; r < MAX; r++)
    {
        for (c = 0; c < MAX; c++)
        {
            int temp = a[r][c];
            a[r][c] = a[c][r];
            a[c][r] = temp;
        }
    }

    // Print the transposed array
    for (r = 0; r < MAX; r++)
    {
        for (c = 0; c < MAX; c++)
        {
            printf("%d ", a[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for (r = 0; r < MAX; r++)
    {
        free(a[r]);
    }
    free(a);

    return 0;
}