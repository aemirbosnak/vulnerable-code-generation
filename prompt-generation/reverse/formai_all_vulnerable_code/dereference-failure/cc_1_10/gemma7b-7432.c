//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: complex
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 100

void percolate(int **arr, int n, int m)
{
    int i, j, k, r, c, p;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            r = rand() % MAX_SIZE;
            c = rand() % MAX_SIZE;
            p = rand() % MAX_SIZE;

            if (arr[r][c] == 0 && arr[p][c] == 1)
            {
                arr[r][c] = 1;
            }
        }
    }
}

int main()
{
    int n, m, i, j;
    int **arr;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    percolate(arr, n, m);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}