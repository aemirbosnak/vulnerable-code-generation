//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: genius
#include <stdlib.h>
#include <stdio.h>

void traffic_flow(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
            {
                int direction = rand() % 2;
                switch (direction)
                {
                    case 0:
                        arr[i][j] = 0;
                        arr[i - 1][j] = 1;
                        break;
                    case 1:
                        arr[i][j] = 0;
                        arr[i + 1][j] = 1;
                        break;
                }
            }
        }
    }
}

int main()
{
    int n = 5;
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    arr[2][2] = 1;
    arr[1][2] = 1;
    arr[0][2] = 1;

    traffic_flow(arr, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}