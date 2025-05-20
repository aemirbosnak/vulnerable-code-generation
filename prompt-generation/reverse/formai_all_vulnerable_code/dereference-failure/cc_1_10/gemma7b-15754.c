//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main()
{
    int n, i, j, k, x, y;
    scanf("%d", &n);

    // Allocate memory for the array
    int **arr = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    // Read the input
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // Calculate the minimum distance
    k = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            x = abs(i - 0) + abs(j - 0);
            y = abs(i - n - 1) + abs(j - n - 1);
            k = fmin(k, x + y);
        }
    }

    // Print the minimum distance
    printf("%d", k);

    // Free the memory
    for(i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}