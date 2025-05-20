//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: curious
#include <stdio.h>
#include <stdlib.h>

void Search(int **arr, int n, int target)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] == target)
            {
                printf("Target found at (%d, %d)\n", i, j);
                return;
            }
        }
    }

    printf("Target not found\n");
}

int main()
{
    int n = 5;
    int target = 12;
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    arr[0][0] = 10;
    arr[0][1] = 20;
    arr[0][2] = 30;
    arr[1][0] = 40;
    arr[1][1] = 50;
    arr[1][2] = 60;
    arr[2][0] = 70;
    arr[2][1] = 80;
    arr[2][2] = 90;
    arr[3][0] = 100;
    arr[3][1] = 110;
    arr[3][2] = 120;
    arr[4][0] = 130;
    arr[4][1] = 140;
    arr[4][2] = 150;

    Search(arr, n, target);

    return 0;
}