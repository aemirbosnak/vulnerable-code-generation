//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x, y, i, j, n, m, iter;
    double dx, dy, x1, x2, y1, y2, c, r;

    printf("The fog hangs thick in the streets of Baker Street, Mr. Holmes.\n");
    printf("Tonight, you have been invited to a grand estate... The Baskerville Hall.\n");
    printf("But something is amiss... Can you unravel the mystery?\n");

    // Set the number of iterations
    iter = 255;

    // Set the fractal parameters
    x1 = -2.0;
    x2 = 1.0;
    y1 = -1.0;
    y2 = 1.0;
    r = 2.0;
    c = 0.2;

    // Allocate memory for the fractal
    n = 1024;
    m = 1024;
    int *fractal = (int *)malloc(n * m * sizeof(int));

    // Generate the fractal
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            dx = x1 + (x2 - x1) * i / n;
            dy = y1 + (y2 - y1) * j / m;
            r = sqrt(dx * dx + dy * dy);
            fractal[i * m + j] = iter - (int)(r * c) / iter;
        }
    }

    // Draw the fractal
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", fractal[i * m + j]);
        }
        printf("\n");
    }

    // Free the memory
    free(fractal);

    return 0;
}