//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: careful
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_ITERATIONS 255

int main()
{
    int x, y, i, iteration, color;
    double real, imag, magnitude;

    // Allocate memory for the image
    unsigned char *image = (unsigned char *)malloc(256 * 256 * 3);

    // Initialize the image
    for (x = 0; x < 256; x++)
    {
        for (y = 0; y < 256; y++)
        {
            image[x * 256 + y * 3] = 0;
            image[x * 256 + y * 3 + 1] = 0;
            image[x * 256 + y * 3 + 2] = 0;
        }
    }

    // Iterate over the pixels
    for (x = 0; x < 256; x++)
    {
        for (y = 0; y < 256; y++)
        {
            real = (double)x / 255.0;
            imag = (double)y / 255.0;

            iteration = 0;
            magnitude = 0.0;

            // Iterate over the iterations
            for (i = 0; i < MAX_ITERATIONS && magnitude < 2.0; i++)
            {
                double z_real = real * z_real - imag * imag + real;
                double z_imag = 2.0 * real * imag + z_imag;
                magnitude = sqrt(z_real * z_real + z_imag * z_imag);

                if (magnitude > 2.0)
                {
                    break;
                }

                real = z_real;
                imag = z_imag;
                iteration++;
            }

            // Set the pixel color
            color = iteration;
            image[x * 256 + y * 3] = color;
            image[x * 256 + y * 3 + 1] = color;
            image[x * 256 + y * 3 + 2] = color;
        }
    }

    // Save the image
    FILE *file = fopen("fractal.ppm", "w");
    fprintf(file, "PPPM %d %d %d\n", 256, 256, 3);
    fwrite(image, 256 * 256 * 3, 1, file);
    fclose(file);

    // Free the memory
    free(image);

    return 0;
}