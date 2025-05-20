//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, i, x, y, z, color, max_iter = 255;
    double zoom = 2.0, x_offset = -1.0, y_offset = 0.0;

    // Allocate memory for the image
    unsigned char *image = (unsigned char *)malloc(640 * 480 * sizeof(unsigned char));

    // Initialize the image
    for (x = 0; x < 640; x++)
    {
        for (y = 0; y < 480; y++)
        {
            image[x * 480 + y] = 0;
        }
    }

    // Iterative coloring of the fractal
    for (n = 0; n < max_iter; n++)
    {
        for (x = 0; x < 640; x++)
        {
            for (y = 0; y < 480; y++)
            {
                z = (int)floor((x - x_offset) / zoom) + (int)floor((y - y_offset) / zoom) * 480;
                color = image[z];
                image[x * 480 + y] = color + n;
            }
        }
    }

    // Save the image
    FILE *file = fopen("fractal.ppm", "wb");
    fprintf(file, "PPPM\n");
    fprintf(file, "%d %d\n", 640, 480);
    fprintf(file, "RGB\n");
    for (x = 0; x < 640; x++)
    {
        for (y = 0; y < 480; y++)
        {
            fprintf(file, "%d ", image[x * 480 + y]);
        }
        fprintf(file, "\n");
    }
    fclose(file);

    // Free the memory
    free(image);

    return 0;
}