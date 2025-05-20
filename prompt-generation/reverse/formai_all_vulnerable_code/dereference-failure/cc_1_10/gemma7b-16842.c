//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Define the grid size
    int nx = 100;
    int ny = 100;

    // Allocate memory for the grid
    double **u = (double**)malloc(ny * sizeof(double*));
    for (int i = 0; i < ny; i++)
    {
        u[i] = (double*)malloc(nx * sizeof(double));
    }

    // Initialize the grid
    for (int i = 0; i < ny; i++)
    {
        for (int j = 0; j < nx; j++)
        {
            u[i][j] = 0.0;
        }
    }

    // Set up the boundary conditions
    u[0][0] = 20.0;
    u[0][nx - 1] = 20.0;
    u[ny - 1][0] = 20.0;
    u[ny - 1][nx - 1] = 20.0;

    // Perform the numerical simulation
    int niter = 1000;
    for (int iter = 0; iter < niter; iter++)
    {
        for (int i = 1; i < ny - 1; i++)
        {
            for (int j = 1; j < nx - 1; j++)
            {
                u[i][j] = 0.5 * (u[i - 1][j] + u[i + 1][j] + u[i][j - 1] + u[i][j + 1] - 4.0 * u[i][j]) / 4.0;
            }
        }
    }

    // Print the final grid
    for (int i = 0; i < ny; i++)
    {
        for (int j = 0; j < nx; j++)
        {
            printf("%f ", u[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < ny; i++)
    {
        free(u[i]);
    }
    free(u);

    return 0;
}