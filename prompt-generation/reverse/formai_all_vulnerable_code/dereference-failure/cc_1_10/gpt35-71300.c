//FormAI DATASET v1.0 Category: Fractal Generation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constants
const int WIDTH = 640;    // Width of the image
const int HEIGHT = 480;   // Height of the image

// Function prototypes
void mandelbrot(double cx, double cy, double *x, double *y, int iterations);
void write_bitmap(int *image, const char *filename);

int main()
{
    // Initialize image buffer
    int *image = (int*)malloc(WIDTH * HEIGHT * sizeof(int));

    // Initialize constants for Mandelbrot set
    const double xmin = -2.0, xmax = 1.0;
    const double ymin = -1.5, ymax = 1.5;
    const int max_iterations = 1000;

    // Loop over each pixel in the image
    for (int j = 0; j < HEIGHT; j++)
    {
        for (int i = 0; i < WIDTH; i++)
        {
            // Map pixel coordinates to complex number
            double cx = xmin + (xmax - xmin) * ((double)i / WIDTH);
            double cy = ymin + (ymax - ymin) * ((double)j / HEIGHT);

            // Compute the Mandelbrot set for the current pixel
            double x = 0, y = 0;
            mandelbrot(cx, cy, &x, &y, max_iterations);

            // Convert number of iterations to a color
            int color = floor(255.0 * (double)x / max_iterations);

            // Set the color of the current pixel
            image[j * WIDTH + i] = color;
        }
    }

    // Write the image buffer to a bitmap file
    write_bitmap(image, "fractal.bmp");

    // Free memory
    free(image);

    return 0;
}

void mandelbrot(double cx, double cy, double *x, double *y, int iterations)
{
    for (int i = 0; i < iterations; i++)
    {
        double xtemp = (*x * *x) - (*y * *y) + cx;
        *y = 2 * *x * *y + cy;
        *x = xtemp;

        if ((*x * *x + *y * *y) > 4)
            break;
    }
}

void write_bitmap(int *image, const char *filename)
{
    // Open the file for writing
    FILE *file = fopen(filename, "wb");

    if (!file)
    {
        printf("ERROR: Could not open file %s for writing.\n", filename);
        return;
    }

    // Write bitmap file header
    unsigned char header[54] = { 0x42, 0x4D, 0x36, 0x1C, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x80, 0x02, 0x00, 0x00, 0xE0, 0x01, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x0E, 0x00, 0x00, 0x13, 0x0B, 0x00, 0x00, 0x13, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
    fwrite(header, sizeof(unsigned char), 54, file);

    // Write pixel data
    for (int j = 0; j < HEIGHT; j++)
    {
        for (int i = 0; i < WIDTH; i++)
        {
            unsigned char color[3] = { (unsigned char)image[j * WIDTH + i], (unsigned char)image[j * WIDTH + i], (unsigned char)image[j * WIDTH + i] };
            fwrite(color, sizeof(unsigned char), 3, file);
        }
    }

    // Close the file
    fclose(file);
}