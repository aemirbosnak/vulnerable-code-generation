//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 255

int main()
{
    int x, y, iteration, color, max_iter;

    // Configure maximum iterations
    max_iter = MAX_ITERATIONS;

    // Set up the fractal parameters
    double x_min = -2.0;
    double x_max = 1.0;
    double y_min = -1.0;
    double y_max = 1.0;

    // Allocate memory for the image
    unsigned char *image = (unsigned char *)malloc(max_iter * max_iter * 3);

    // Generate the fractal
    for (y = 0; y < max_iter; y++)
    {
        for (x = 0; x < max_iter; x++)
        {
            iteration = 0;
            color = 0;

            // Iterate over the number of iterations
            while (iteration < max_iter && color == 0)
            {
                double z_real = x_min + (x / (double)max_iter) * (x_max - x_min);
                double z_imag = y_min + (y / (double)max_iter) * (y_max - y_min);
                double w = z_real * z_real + z_imag * z_imag;

                if (w > 4)
                {
                    color = iteration;
                }
                iteration++;
            }

            // Store the color in the image
            image[y * max_iter + x * 3] = color;
            image[y * max_iter + x * 3 + 1] = color;
            image[y * max_iter + x * 3 + 2] = color;
        }
    }

    // Display the fractal
    printf("Image saved to fractal.ppm\n");
    system("ppm -o fractal.ppm ./fractal.ppm");

    // Free the memory
    free(image);

    return 0;
}