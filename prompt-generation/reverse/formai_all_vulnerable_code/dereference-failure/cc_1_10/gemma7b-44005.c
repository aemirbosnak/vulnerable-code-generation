//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 255

int main()
{
    int x, y;
    double zx, zy, r, g, b;

    // Allocate memory for the fractal
    int *fractal = (int *)malloc(MAX_ITERATIONS * sizeof(int));

    // Generate the fractal
    for (x = 0; x < MAX_ITERATIONS; x++)
    {
        for (y = 0; y < MAX_ITERATIONS; y++)
        {
            zx = (x - MAX_ITERATIONS / 2) / MAX_ITERATIONS;
            zy = (y - MAX_ITERATIONS / 2) / MAX_ITERATIONS;

            r = 2.0 * zx * zx + zy * zy;
            g = 2.0 * zy * zx + zy * zy;
            b = 2.0 * zx * zy + 2.0 * zy * zy;

            fractal[x * MAX_ITERATIONS + y] = (int)round(r);
            fractal[x * MAX_ITERATIONS + y] |= (int)round(g) << 8;
            fractal[x * MAX_ITERATIONS + y] |= (int)round(b) << 16;
        }
    }

    // Display the fractal
    for (x = 0; x < MAX_ITERATIONS; x++)
    {
        for (y = 0; y < MAX_ITERATIONS; y++)
        {
            r = fractal[x * MAX_ITERATIONS + y] & 0xFF;
            g = (fractal[x * MAX_ITERATIONS + y] & 0xFF00) >> 8;
            b = (fractal[x * MAX_ITERATIONS + y] & 0xFF0000) >> 16;

            printf("%c%c%c ", r, g, b);
        }
        printf("\n");
    }

    // Free the memory
    free(fractal);

    return 0;
}