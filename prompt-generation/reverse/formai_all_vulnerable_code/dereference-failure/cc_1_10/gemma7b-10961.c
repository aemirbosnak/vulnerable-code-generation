//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a = NULL, **b = NULL, **c = NULL, n = 0;

    scanf("Enter the number of rows: ", &n);
    a = malloc(n * sizeof(int *));
    b = malloc(n * sizeof(int *));
    c = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        a[i] = malloc(n * sizeof(int));
        b[i] = malloc(n * sizeof(int));
        c[i] = malloc(n * sizeof(int));
    }

    // Matrix Operations
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Print the Result
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Free Memory
    for (int i = 0; i < n; i++)
    {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);

    return 0;
}