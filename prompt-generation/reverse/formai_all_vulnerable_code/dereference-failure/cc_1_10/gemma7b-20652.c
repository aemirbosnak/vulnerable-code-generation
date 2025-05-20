//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int main()
{
    int **arr = NULL;
    int i, j, k, r, c, num, per, iter = 0;
    arr = (int **)malloc(MAX * sizeof(int *));
    for (i = 0; i < MAX; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    printf("Enter number of iterations: ");
    scanf("%d", &iter);

    printf("Enter number of percolations: ");
    scanf("%d", &num);

    per = num;

    for (r = 0; r < iter; r++)
    {
        for (c = 0; c < MAX; c++)
        {
            for (i = 0; i < MAX; i++)
            {
                arr[i][c] = 0;
            }
        }

        for (k = 0; k < per; k++)
        {
            r = rand() % MAX;
            c = rand() % MAX;
            arr[r][c] = 1;
        }

        per += num;
    }

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);
    return 0;
}