//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int **arr = (int **)malloc(MAX * MAX * sizeof(int));
    for(int i = 0; i < MAX; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
        for(int j = 0; j < MAX; j++)
        {
            arr[i][j] = 0;
        }
    }

    int x, y, n;
    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    for(int it = 0; it < n; it++)
    {
        printf("Enter the coordinates of the drop: ");
        scanf("%d %d", &x, &y);

        if(arr[x][y] == 0)
        {
            arr[x][y] = 1;
            // Percolation algorithm to spread water
            for(int i = x - 1; i <= x + 1; i++)
            {
                for(int j = y - 1; j <= y + 1; j++)
                {
                    if(arr[i][j] == 0)
                    {
                        arr[i][j] = 1;
                    }
                }
            }
        }
    }

    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}