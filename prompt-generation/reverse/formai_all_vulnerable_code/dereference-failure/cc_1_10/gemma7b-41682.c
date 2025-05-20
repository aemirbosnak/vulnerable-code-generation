//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 255

int main()
{
    int x, y, iteration, color;
    double real, imaginary;

    // Allocates memory for the fractal image
    unsigned int *image = (unsigned int *)malloc(160000);

    // Initializes the fractal image with black pixels
    for (x = 0; x < 800; x++)
    {
        for (y = 0; y < 800; y++)
        {
            image[x * 800 + y] = 0;
        }
    }

    // Iterates over the complex numbers
    for (iteration = 0; iteration < MAX_ITERATIONS; iteration++)
    {
        // Sets the complex number
        real = -2.0 + (double)iteration / MAX_ITERATIONS;
        imaginary = 1.0;

        // Calculates the fractal distance
        double distance = sqrt(real * real + imaginary * imaginary);

        // Sets the pixel color based on the distance
        color = (int)(255 - distance * 255);
        image[x * 800 + y] = color;
    }

    // Writes the fractal image to a file
    FILE *file = fopen("fractal.ppm", "w");
    fprintf(file, "PPPM\n");
    fprintf(file, "800 800\n");
    fprintf(file, "RGB\n");
    for (x = 0; x < 800; x++)
    {
        for (y = 0; y < 800; y++)
        {
            fprintf(file, "%d ", image[x * 800 + y]);
        }
        fprintf(file, "\n");
    }
    fclose(file);

    // Free the memory allocated for the fractal image
    free(image);

    return 0;
}