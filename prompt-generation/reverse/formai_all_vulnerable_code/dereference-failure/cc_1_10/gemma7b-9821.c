//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void percolatesim(int **arr, int n, int m)
{
    int i, j, k, p, q;
    srand(time(NULL));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }

    for (k = 0; k < MAX_SIZE; k++)
    {
        p = rand() % n;
        q = rand() % m;

        if (arr[p][q] == 0)
        {
            arr[p][q] = 1;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n, m;
    int **arr;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    percolatesim(arr, n, m);

    return 0;
}