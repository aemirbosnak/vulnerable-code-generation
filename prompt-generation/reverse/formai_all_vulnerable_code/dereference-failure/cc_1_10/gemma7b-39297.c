//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: funny
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int x, y, iter, maxIter = 1000;
    double cx, cy, cr, ci, r, theta;

    // Allocate memory for the fractal image
    unsigned char *image = (unsigned char *)malloc(1600000);

    // Initialize the image with black pixels
    for (x = 0; x < 800; x++)
    {
        for (y = 0; y < 800; y++)
        {
            image[x * 800 + y] = 0;
        }
    }

    // Generate the fractal
    for (iter = 0; iter < maxIter; iter++)
    {
        for (x = 0; x < 800; x++)
        {
            for (y = 0; y < 800; y++)
            {
                cx = x / 800.0;
                cy = y / 800.0;
                cr = (cx - 0.5) * 2.0;
                ci = (cy - 0.5) * 2.0;
                r = sqrt(cr * cr + ci * ci);

                if (r < 2.0)
                {
                    image[x * 800 + y] = 255;
                }
            }
        }
    }

    // Save the fractal image to a file
    FILE *fp = fopen("fractal.bmp", "wb");
    fwrite(image, 1, 1600000, fp);
    fclose(fp);

    // Free the memory allocated for the fractal image
    free(image);

    return 0;
}