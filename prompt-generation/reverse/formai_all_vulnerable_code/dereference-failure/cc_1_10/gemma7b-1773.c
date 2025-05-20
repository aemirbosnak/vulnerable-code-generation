//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void percolat(int **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] == 0)
            {
                int flag = 0;
                for (int k = 0; k < size; k++)
                {
                    for (int l = 0; l < size; l++)
                    {
                        if (arr[k][l] == 1 && k == i && l == j)
                        {
                            flag = 1;
                        }
                    }
                }
                if (flag == 1)
                {
                    arr[i][j] = 1;
                }
            }
        }
    }
}

int main()
{
    int size = MAX_SIZE;
    int **arr = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        arr[i] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the array
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Percolation
    percolat(arr, size);

    // Print the array
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}