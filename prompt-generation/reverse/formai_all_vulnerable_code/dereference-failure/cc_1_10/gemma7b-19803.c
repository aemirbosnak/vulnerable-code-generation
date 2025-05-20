//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x, y, i, n, m;
    double d, dx, dy, x0, y0, r, theta;

    // Set the number of iterations
    n = 1000;

    // Set the initial point
    x0 = -1.5;
    y0 = 1.0;

    // Set the radius of the fractal
    r = 2.0;

    // Set the angle of the fractal
    theta = 0.0;

    // Allocate memory for the fractal
    int *fractal = (int *)malloc(n * sizeof(int));

    // Generate the fractal
    for (i = 0; i < n; i++)
    {
        dx = x0 + r * cos(theta) * i / n;
        dy = y0 + r * sin(theta) * i / n;

        // Calculate the distance to the point
        d = sqrt(dx * dx + dy * dy);

        // Set the pixel color based on the distance
        fractal[i] = 255 - (int)(255 * d / r);
    }

    // Display the fractal
    for (x = 0; x < n; x++)
    {
        for (y = 0; y < n; y++)
        {
            printf("%d ", fractal[x * n + y]);
        }
        printf("\n");
    }

    // Free the memory
    free(fractal);

    return 0;
}