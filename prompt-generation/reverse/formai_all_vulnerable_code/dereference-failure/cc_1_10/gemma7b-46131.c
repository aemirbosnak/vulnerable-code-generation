//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_table(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n = 17;
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    arr[0][0] = 1;
    arr[1][0] = 2;
    arr[2][0] = 3;
    arr[3][0] = 4;
    arr[4][0] = 5;
    arr[5][0] = 6;
    arr[6][0] = 7;
    arr[7][0] = 8;
    arr[8][0] = 9;
    arr[9][0] = 10;

    arr[1][1] = 11;
    arr[2][1] = 12;
    arr[3][1] = 13;
    arr[4][1] = 14;
    arr[5][1] = 15;
    arr[6][1] = 16;
    arr[7][1] = 17;

    print_table(arr, n);

    free(arr);

    return 0;
}