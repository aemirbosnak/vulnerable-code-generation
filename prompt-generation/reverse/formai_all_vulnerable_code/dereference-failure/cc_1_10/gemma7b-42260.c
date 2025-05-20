//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000

int main()
{
    // Allocate memory for the fractal
    int *fractal = (int *)malloc(MAX_ITERATIONS * sizeof(int));

    // Initialize the fractal with the initial values
    for (int i = 0; i < MAX_ITERATIONS; i++)
    {
        fractal[i] = 0;
    }

    // Generate the fractal
    for (int x = -MAX_ITERATIONS / 2; x <= MAX_ITERATIONS / 2; x++)
    {
        for (int y = -MAX_ITERATIONS / 2; y <= MAX_ITERATIONS / 2; y++)
        {
            int iterations = 0;
            while (iterations < MAX_ITERATIONS && fractal[iterations] != 1)
            {
                double r = (x + 1) / MAX_ITERATIONS;
                double b = (y + 1) / MAX_ITERATIONS;
                double z = sqrt(r * r + b * b);
                fractal[iterations] = (int)z;
                iterations++;
            }
        }
    }

    // Print the fractal
    for (int i = 0; i < MAX_ITERATIONS; i++)
    {
        for (int j = 0; j < MAX_ITERATIONS; j++)
        {
            int intensity = fractal[i * MAX_ITERATIONS + j];
            printf("%c", 255 - intensity);
        }
        printf("\n");
    }

    // Free the memory allocated for the fractal
    free(fractal);

    return 0;
}