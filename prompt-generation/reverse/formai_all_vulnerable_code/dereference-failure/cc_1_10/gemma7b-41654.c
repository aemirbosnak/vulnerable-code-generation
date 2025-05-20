//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: active
#include <stdlib.h>
#include <time.h>

int main()
{
    int x, y, z;
    int **arr;

    // Allocate memory for the array
    arr = (int**)malloc(10 * sizeof(int*));
    for (x = 0; x < 10; x++)
    {
        arr[x] = (int*)malloc(10 * sizeof(int));
    }

    // Initialize the array
    for (x = 0; x < 10; x++)
    {
        for (y = 0; y < 10; y++)
        {
            arr[x][y] = 0;
        }
    }

    // Simulate percolation
    for (z = 0; z < 1000; z++)
    {
        x = rand() % 10;
        y = rand() % 10;

        if (arr[x][y] == 0)
        {
            arr[x][y] = 1;
        }
    }

    // Print the array
    for (x = 0; x < 10; x++)
    {
        for (y = 0; y < 10; y++)
        {
            printf("%d ", arr[x][y]);
        }
        printf("\n");
    }

    // Free memory
    for (x = 0; x < 10; x++)
    {
        free(arr[x]);
    }
    free(arr);

    return 0;
}