//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int MAX_ITERATIONS = 200;
double SCALE = 5.0;
double SHIFT = 1.0;

double mandelbrot(double x, double y)
{
    double cx = x;
    double cy = y;
    double zx = 0;
    double zy = 0;
    int i;

    for(i = 0; i < MAX_ITERATIONS; i++)
    {
        double zx_new = (zx * zx - zy * zy) + cx;
        double zy_new = (2 * zx * zy) + cy;

        zx = zx_new;
        zy = zy_new;

        if(fabs(zx + zy) > 4)
        {
            break;
        }
    }

    return (double) i / MAX_ITERATIONS;
}

int main()
{
    int width = 200;
    int height = 200;

    double** pixels = malloc(width * sizeof(double*));

    if(pixels == NULL)
    {
        fprintf(stderr, "Error: could not allocate memory for pixels.\n");
        exit(1);
    }

    int x, y;
    for(x = 0; x < width; x++)
    {
        pixels[x] = malloc(height * sizeof(double));

        if(pixels[x] == NULL)
        {
            fprintf(stderr, "Error: could not allocate memory for row %d.\n", x);
            exit(1);
        }

        for(y = 0; y < height; y++)
        {
            double pixel_x = (double) x / width * SCALE - SHIFT;
            double pixel_y = (double) y / height * SCALE - SHIFT;

            pixels[x][y] = mandelbrot(pixel_x, pixel_y);
        }
    }

    printf("\n");

    for(y = height - 1; y >= 0; y--)
    {
        for(x = 0; x < width; x++)
        {
            if(pixels[x][y] > 0.3)
            {
                printf(" ");
            }
            else if(pixels[x][y] > 0.2)
            {
                printf(".");
            }
            else if(pixels[x][y] > 0.1)
            {
                printf("*");
            }
            else
            {
                printf("#");
            }
        }

        printf("\n");
    }

    for(x = 0; x < width; x++)
    {
        free(pixels[x]);
    }

    free(pixels);

    return 0;
}