//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, m, i, j, k, l;
    int **arr;
    int **perc;
    int **rand_arr;

    n = 10;
    m = 10;
    arr = (int *)malloc(n * m * sizeof(int));
    perc = (int *)malloc(n * m * sizeof(int));
    rand_arr = (int *)malloc(n * m * sizeof(int));

    srand(time(NULL));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            arr[i][j] = rand() % 2;
            perc[i][j] = -1;
            rand_arr[i][j] = rand() % 2;
        }
    }

    k = 0;
    l = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (arr[i][j] == 1 && perc[i][j] == -1)
            {
                perc[i][j] = k;
                k++;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (perc[i][j] != -1)
            {
                printf("%d ", rand_arr[i][j]);
            }
            else
            {
                printf("X ");
            }
        }
        printf("\n");
    }

    free(arr);
    free(perc);
    free(rand_arr);

    return 0;
}