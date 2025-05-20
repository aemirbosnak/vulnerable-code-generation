//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: active
#include <stdlib.h>
#include <stdio.h>

#define MAX 10

int main()
{
    int **arr = (int **)malloc(MAX * MAX * sizeof(int));
    for (int i = 0; i < MAX; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
        for (int j = 0; j < MAX; j++)
        {
            arr[i][j] = 0;
        }
    }

    int x, y, z;
    printf("Enter the number of iterations: ");
    scanf("%d", &z);

    for (int k = 0; k < z; k++)
    {
        printf("Enter the x and y coordinates of the drop: ");
        scanf("%d %d", &x, &y);

        if (arr[x][y] == 0)
        {
            arr[x][y] = 1;
            printf("The drop has been placed.\n");
        }
        else
        {
            printf("The drop has already been placed.\n");
        }
    }

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (arr[i][j] == 1)
            {
                printf("The cell at (%d, %d) is wet.\n", i, j);
            }
        }
    }

    free(arr);

    return 0;
}