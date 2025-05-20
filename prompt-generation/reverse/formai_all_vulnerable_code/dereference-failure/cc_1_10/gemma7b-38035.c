//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_POINTS 1000

int main()
{
    int x, y, i, n, m, fractal_type = 1;
    double x_min, x_max, y_min, y_max, zoom_factor = 2.0;

    // Configure fractal type
    switch (fractal_type)
    {
        case 1:
            x_min = -2.0;
            x_max = 1.0;
            y_min = -1.0;
            y_max = 1.0;
            break;
        case 2:
            x_min = -1.0;
            x_max = 1.0;
            y_min = -1.0;
            y_max = 0.0;
            break;
        case 3:
            x_min = -1.0;
            x_max = 0.0;
            y_min = -1.0;
            y_max = 0.0;
            break;
    }

    // Set number of points
    n = MAX_POINTS;

    // Allocate memory
    int **points = (int *)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        points[i] = (int *)malloc(2 * sizeof(int));

    // Generate points
    for (i = 0; i < n; i++)
    {
        points[i][0] = rand() % ((int)(x_max - x_min) + 1) + x_min;
        points[i][1] = rand() % ((int)(y_max - y_min) + 1) + y_min;
    }

    // Free memory
    for (i = 0; i < n; i++)
    {
        free(points[i]);
    }
    free(points);

    return 0;
}