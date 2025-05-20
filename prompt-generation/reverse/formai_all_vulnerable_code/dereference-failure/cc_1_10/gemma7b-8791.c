//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main()
{
    int size = MAX_SIZE;
    int **arr = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        arr[i] = (int *)malloc(size * sizeof(int));
    }

    int n, m;
    scanf("Enter the number of rows and columns: ", &n);
    scanf("Enter the number of iterations: ", &m);

    // Percolation simulation
    for (int iter = 0; iter < m; iter++)
    {
        // Randomly select two cells
        int x1 = rand() % size;
        int y1 = rand() % size;
        int x2 = rand() % size;
        int y2 = rand() % size;

        // If both cells are occupied, swap them
        if (arr[x1][y1] && arr[x2][y2])
        {
            int temp = arr[x1][y1];
            arr[x1][y1] = arr[x2][y2];
            arr[x2][y2] = temp;
        }
    }

    // Print the final array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < size; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}