//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

    printf("The Matrix Reloaded!\n");

    // Create a 3x3 matrix
    int **a = (int **)malloc(3 * sizeof(int *));
    for (i = 0; i < 3; i++)
    {
        a[i] = (int *)malloc(3 * sizeof(int));
    }

    // Initialize the matrix
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            a[i][j] = 0;
        }
    }

    // Fill the matrix with numbers
    a[1][1] = 1;
    a[2][2] = 2;
    a[0][0] = 3;

    // Transpose the matrix
    int **b = (int **)malloc(3 * sizeof(int *));
    for (i = 0; i < 3; i++)
    {
        b[i] = (int *)malloc(3 * sizeof(int));
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            b[i][j] = a[j][i];
        }
    }

    // Print the transposed matrix
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < 3; i++)
    {
        free(a[i]);
    }
    free(a);

    return 0;
}