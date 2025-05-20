//Gemma-7B DATASET v1.0 Category: Prime Number Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Recursive function to generate prime numbers
int primeGenerator(int n)
{
    int i, j, count = 0;

    // Iterate over the numbers from 1 to n
    for (i = 1; i <= n; i++)
    {
        // Iterate over the numbers from 1 to i/2
        for (j = 1; j <= i/2; j++)
        {
            // If i is divisible by any number other than 1 and itself, it is not prime
            if (i % j == 0)
            {
                count++;
            }
        }

        // If the number of divisors is 2, it is prime
        if (count == 2)
        {
            printf("%d ", i);
        }

        count = 0;
    }

    return 0;
}

// Fractal pattern generator
void fractal(int n)
{
    int i, j, x, y;

    // Create a grid of numbers
    int **grid = (int *)malloc(n * n * sizeof(int));

    // Initialize the grid
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Calculate the prime numbers
    primeGenerator(n);

    // Mark the prime numbers in the grid
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                grid[i][j] = 2;
            }
        }
    }

    // Draw the fractal pattern
    for (x = 0; x < n; x++)
    {
        for (y = 0; y < n; y++)
        {
            if (grid[x][y] == 2)
            {
                printf("%c ", '*');
            }
            else
            {
                printf("%c ", '.');
            }
        }

        printf("\n");
    }

    // Free the memory
    free(grid);
}

int main()
{
    fractal(100);

    return 0;
}