//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void search(int **arr, int n, int key)
{
    int i, j, found = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (arr[i][j] == key)
            {
                found = 1;
                break;
            }
        }
    }
    if (found)
    {
        printf("Key found\n");
    }
    else
    {
        printf("Key not found\n");
    }
}

int main()
{
    int **arr = (int **)malloc(MAX * sizeof(int *));
    for (int i = 0; i < MAX; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    int n = 5;
    int key = 20;

    // Populate the array
    arr[0][0] = 10;
    arr[0][1] = 20;
    arr[1][0] = 30;
    arr[1][1] = 40;
    arr[2][0] = 50;
    arr[2][1] = 60;
    arr[3][0] = 70;
    arr[3][1] = 80;
    arr[4][0] = 90;
    arr[4][1] = 100;

    search(arr, n, key);

    return 0;
}