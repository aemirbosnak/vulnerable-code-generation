//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: irregular
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX 100

int main()
{
    int **arr;
    int i, j, k, l, m, n, p, q, r, s;
    int x, y, z;
    int a, b, c, d;
    int water_amount = 0;
    int water_level = 0;
    int flag = 0;

    arr = (int *)malloc(MAX * MAX * sizeof(int));
    for(i = 0; i < MAX; i++)
    {
        for(j = 0; j < MAX; j++)
        {
            arr[i][j] = 0;
        }
    }

    for(k = 0; k < MAX; k++)
    {
        for(l = 0; l < MAX; l++)
        {
            if(arr[k][l] == 0)
            {
                water_amount++;
            }
        }
    }

    water_level = water_amount / MAX;

    printf("Water Amount: %d\n", water_amount);
    printf("Water Level: %d\n", water_level);

    if(water_level > 0)
    {
        flag = 1;
    }

    if(flag)
    {
        printf("Water is flowing.\n");
    }
    else
    {
        printf("No water is flowing.\n");
    }

    return 0;
}