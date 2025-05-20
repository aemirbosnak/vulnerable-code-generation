//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void greedy_algo(int **arr, int n)
{
    int i, j, k, max_sum = 0, current_sum = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (arr[i][j] > current_sum)
            {
                current_sum = arr[i][j];
                k = j;
            }
        }
        max_sum += current_sum;
        current_sum = 0;
    }
    printf("Total sum: %d", max_sum);
}

int main()
{
    int n = 5;
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    // Populate the array
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

    greedy_algo(arr, n);

    return 0;
}