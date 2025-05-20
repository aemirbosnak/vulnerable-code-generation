//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void percol_sim(int **arr, int n)
{
    int i, j, k, r, c;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            r = rand() % MAX;
            c = rand() % MAX;
            if (r < arr[i][j] && c < arr[i][j])
            {
                arr[i][j] = 1;
            }
        }
    }
}

int main()
{
    int n, i, j;
    scanf("Enter the number of squares: ", &n);
    int **arr = (int **)malloc(n * sizeof(int *)), **temp = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
        temp[i] = (int *)malloc(n * sizeof(int));
    }

    percol_sim(arr, n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
            {
                printf("%c ", 'A' + i);
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }

    return 0;
}