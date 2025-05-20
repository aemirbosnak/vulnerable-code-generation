//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    // Define the number of grid points
    int nx = 100;
    int ny = 100;

    // Allocate memory for the grid
    double **u = (double**)malloc(nx * sizeof(double*));
    for (int i = 0; i < nx; i++)
    {
        u[i] = (double*)malloc(ny * sizeof(double));
    }

    // Initialize the grid
    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            u[i][j] = 0.0;
        }
    }

    // Define the boundary conditions
    u[0][0] = 10.0;
    u[0][ny - 1] = 20.0;
    u[nx - 1][0] = 30.0;
    u[nx - 1][ny - 1] = 40.0;

    // Solve the heat equation
    for (int t = 0; t < 1000; t++)
    {
        for (int i = 0; i < nx; i++)
        {
            for (int j = 0; j < ny; j++)
            {
                u[i][j] = 0.25 * (u[i - 1][j] + u[i + 1][j] + u[i][j - 1] + u[i][j + 1] - u[i][j]) + u[i][j];
            }
        }
    }

    // Print the solution
    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            printf("%f ", u[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < nx; i++)
    {
        free(u[i]);
    }
    free(u);

    return 0;
}