//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: safe
#include <stdlib.h>
#include <time.h>

#define N 25

int main()
{
    int **arr = (int **)malloc(N * sizeof(int *));
    for(int i = 0; i < N; i++)
    {
        arr[i] = (int *)malloc(N * sizeof(int));
    }

    srand(time(NULL));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(arr[i][j] == 1)
            {
                arr[i][j] = 2;
                arr[i][j-1] = 2;
                arr[i][j+1] = 2;
                arr[i-1][j] = 2;
                arr[i+1][j] = 2;
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}