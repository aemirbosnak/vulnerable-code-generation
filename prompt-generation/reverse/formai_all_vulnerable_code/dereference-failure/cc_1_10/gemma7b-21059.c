//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void search(int **arr, int n, int target)
{
    int i, j, found = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (arr[i][j] == target)
            {
                found = 1;
                break;
            }
        }
    }

    if (found)
    {
        printf("Target found.\n");
    }
    else
    {
        printf("Target not found.\n");
    }
}

int main()
{
    int **arr = (int **)malloc(10 * sizeof(int *));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
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

    int target = 50;
    search(arr, 3, target);

    return 0;
}