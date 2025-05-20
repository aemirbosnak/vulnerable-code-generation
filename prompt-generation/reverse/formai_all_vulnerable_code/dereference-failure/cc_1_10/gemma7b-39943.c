//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

void greedy_algorithm(int **arr, int n)
{
    int i, j, total = 0, selected = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] > total)
            {
                total = arr[i][j];
                selected = i + 1;
            }
        }
    }
    printf("Total: %d, Selected: %d\n", total, selected);
}

int main()
{
    int n = 5;
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    arr[0][0] = 10;
    arr[0][1] = 20;
    arr[0][2] = 30;
    arr[0][3] = 40;
    arr[0][4] = 50;

    arr[1][0] = 60;
    arr[1][1] = 70;
    arr[1][2] = 80;
    arr[1][3] = 90;
    arr[1][4] = 100;

    arr[2][0] = 110;
    arr[2][1] = 120;
    arr[2][2] = 130;
    arr[2][3] = 140;
    arr[2][4] = 150;

    arr[3][0] = 160;
    arr[3][1] = 170;
    arr[3][2] = 180;
    arr[3][3] = 190;
    arr[3][4] = 200;

    arr[4][0] = 210;
    arr[4][1] = 220;
    arr[4][2] = 230;
    arr[4][3] = 240;
    arr[4][4] = 250;

    greedy_algorithm(arr, n);

    return 0;
}