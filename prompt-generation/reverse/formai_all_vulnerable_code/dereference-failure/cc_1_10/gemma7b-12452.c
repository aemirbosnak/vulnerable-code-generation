//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the Percolation Simulation function
int percolat(int **arr, int n, int m)
{
    // Allocate memory for the array
    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    // Initialize the array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Randomly assign some sites to be wet
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (rand() % 2 == 0)
            {
                arr[i][j] = 1;
            }
        }
    }

    // Simulate the percolating water
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                // Check if the site above is wet
                if (i > 0 && arr[i - 1][j] == 1)
                {
                    arr[i][j] = 1;
                }
                // Check if the site to the left is wet
                if (j > 0 && arr[i][j - 1] == 1)
                {
                    arr[i][j] = 1;
                }
            }
        }
    }

    // Count the number of wet sites
    int num_wet = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                num_wet++;
            }
        }
    }

    // Free the memory
    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    // Return the number of wet sites
    return num_wet;
}

int main()
{
    // Percolation Simulation
    int n = 5;
    int m = 5;
    int num_wet = percolat(NULL, n, m);

    // Print the number of wet sites
    printf("The number of wet sites is: %d", num_wet);

    return 0;
}