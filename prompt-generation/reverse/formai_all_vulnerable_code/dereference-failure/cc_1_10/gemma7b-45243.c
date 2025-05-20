//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int i, j, k, l, x, y;
    int **arr = (int **)malloc(MAX * sizeof(int *));
    for (i = 0; i < MAX; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            arr[i][j] = 0;
        }
    }

    x = rand() % MAX;
    y = rand() % MAX;

    arr[x][y] = 1;

    k = 0;
    l = 0;
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (arr[i][j] == 1)
            {
                k++;
                arr[i][j] = 2;
            }
            else if (arr[i][j] == 0 && l == 0)
            {
                l++;
            }
        }
    }

    printf("Number of drops: %d\n", k);
    printf("Number of empty cells: %d\n", l);

    return 0;
}