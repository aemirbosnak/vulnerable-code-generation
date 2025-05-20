//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void GameOfLife(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int count = 0;
            if (i - 1 >= 0)
                count++;
            if (i + 1 < n)
                count++;
            if (j - 1 >= 0)
                count++;
            if (j + 1 < n)
                count++;

            if (arr[i][j] == 1 && count < 2)
                arr[i][j] = 0;
            else if (arr[i][j] == 0 && count == 3)
                arr[i][j] = 1;
        }
    }
}

int main()
{
    int n = MAX;
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    // Initializing the game board
    arr[0][0] = 1;
    arr[0][1] = 1;
    arr[1][0] = 1;
    arr[1][1] = 1;
    arr[1][2] = 1;

    GameOfLife(arr, n);

    // Printing the final game board
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Freeing memory
    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}