//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: enthusiastic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Macro for a 2D array
#define ARRAY_2D(arr, r, c) arr = (int *)malloc(r * c * sizeof(int))

// Percolation Simulation Function
void percolate(int **arr, int r, int c)
{
    int i, j, k, p, x, y;

    // Randomly select a number of sites to be occupied
    for (k = 0; k < 0.5 * r * c; k++)
    {
        x = rand() % r;
        y = rand() % c;
        arr[x][y] = 1;
    }

    // Iterate over the lattice and connect occupied sites to their neighbors
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (arr[i][j] == 1)
            {
                p = 0;
                if (i > 0 && arr[i - 1][j] == 1) p++;
                if (j > 0 && arr[i][j - 1] == 1) p++;
                if (i < r - 1 && arr[i + 1][j] == 1) p++;
                if (j < c - 1 && arr[i][j + 1] == 1) p++;
                if (p > 0) arr[i][j] = 2;
            }
        }
    }

    // Print the percolated lattice
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int r, c;

    printf("Enter the number of rows: ");
    scanf("%d", &r);

    printf("Enter the number of columns: ");
    scanf("%d", &c);

    // Create a 2D array to store the lattice
    int **arr;
    ARRAY_2D(arr, r, c);

    // Percolate the lattice
    percolate(arr, r, c);

    return 0;
}