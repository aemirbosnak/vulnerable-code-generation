//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: expert-level
#include <stdio.h>
#include <math.h>

#define MAX 1024

int main()
{
    int x, y, i, j, n, m, iter = 0, maxIter = 1000;

    // Allocate memory for the image
    unsigned int *img = (unsigned int *)malloc(MAX * MAX * sizeof(unsigned int));

    // Initialize the image
    for (x = 0; x < MAX; x++)
    {
        for (y = 0; y < MAX; y++)
        {
            img[x * MAX + y] = 0;
        }
    }

    // Iterate over the number of iterations
    for (iter = 0; iter < maxIter; iter++)
    {
        // Iterate over the pixels
        for (x = 0; x < MAX; x++)
        {
            for (y = 0; y < MAX; y++)
            {
                // Calculate the complex number z = x + i*y
                double z_re = (double)x / MAX;
                double z_im = (double)y / MAX;

                // Calculate the number of iterations it took for z to escape from the unit circle
                int numIter = 0;
                while (numIter < iter && z_re * z_re + z_im * z_im < 1)
                {
                    double w_re = z_re * z_re - z_im * z_im + z_re;
                    double w_im = 2 * z_re * z_im + z_im;
                    z_re = w_re;
                    z_im = w_im;
                    numIter++;
                }

                // Set the pixel color based on the number of iterations
                img[x * MAX + y] = numIter;
            }
        }
    }

    // Write the image to a file
    FILE *fp = fopen("fractal.ppm", "w");
    fprintf(fp, "PPPM\n%d %d\n%d\n", MAX, MAX, MAX);
    for (x = 0; x < MAX; x++)
    {
        for (y = 0; y < MAX; y++)
        {
            fprintf(fp, "%d ", img[x * MAX + y]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);

    // Free the memory
    free(img);

    return 0;
}