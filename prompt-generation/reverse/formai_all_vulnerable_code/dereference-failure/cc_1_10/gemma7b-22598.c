//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main()
{
    int **arr = NULL;
    int i, j, k, seed, n, m;

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    printf("Enter the number of trials: ");
    scanf("%d", &m);

    arr = (int *)malloc(MAX_SIZE * MAX_SIZE * sizeof(int));
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            arr[i][j] = 0;
        }
    }

    seed = time(NULL);
    for (k = 0; k < m; k++)
    {
        for (i = 0; i < n; i++)
        {
            n = rand() % MAX_SIZE;
            m = rand() % MAX_SIZE;
            arr[n][m] = 1;
        }
    }

    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}