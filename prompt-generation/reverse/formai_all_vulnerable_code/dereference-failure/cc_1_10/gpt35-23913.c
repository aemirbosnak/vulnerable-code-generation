//FormAI DATASET v1.0 Category: Fractal Generation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_ITERATIONS 100000
#define WIDTH 500
#define HEIGHT 500
#define MAX_COLOR 255

int main()
{
    int x, y, i, j, k, l, color;
    double c_re, c_im, z_re, z_im, temp;
    double zoom = 1, moveX = 0, moveY = 0;

    srand(time(NULL)); // seed the random number generator

    // Create a blank bitmap
    unsigned char* bitmap = (unsigned char*) malloc(WIDTH * HEIGHT * sizeof(unsigned char));

    // Loop through each pixel on the screen
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            
            // Map pixel coordinates to the complex plane
            c_re = (x - WIDTH/2.0) / (0.5 * zoom * WIDTH) + moveX;
            c_im = (y - HEIGHT/2.0) / (0.5 * zoom * HEIGHT) + moveY;

            // Initialize z to the origin
            z_re = 0;
            z_im = 0;

            // Iterate the Mandelbrot formula
            for (i = 0; i < MAX_ITERATIONS; i++) {

                // Calculate z^2 + c
                temp = z_re*z_re - z_im*z_im + c_re;
                z_im = 2 * z_re * z_im + c_im;
                z_re = temp;

                // Check if we have escaped the Mandelbrot set
                if (z_re*z_re + z_im*z_im > 4) {

                    // Color the pixel based on the number of iterations
                    color = (i * MAX_COLOR) / MAX_ITERATIONS;
                    bitmap[y*WIDTH + x] = color;
                    break;
                }
            }

            // If we haven't escaped, color the pixel black
            if (i == MAX_ITERATIONS) {
                bitmap[y*WIDTH + x] = 0;
            }
        }
    }

    // Output the bitmap as a PGM file
    FILE* fp = fopen("fractal.pgm", "wb");
    fprintf(fp, "P5\n%d %d\n%d\n", WIDTH, HEIGHT, MAX_COLOR);
    fwrite(bitmap, 1, WIDTH * HEIGHT, fp);
    fclose(fp);

    free(bitmap); // Free the memory allocated for the bitmap

    return 0;
}