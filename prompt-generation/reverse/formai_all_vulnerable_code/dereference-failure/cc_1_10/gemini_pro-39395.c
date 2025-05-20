//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 256

typedef struct {
    double x;
    double y;
} complex_t;

int main() {
    // Create an image buffer
    unsigned char *image = malloc(WIDTH * HEIGHT * 3);

    // Iterate over each pixel in the image buffer
    complex_t p, z;
    double c_real, c_imag;
    int iterations;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Calculate the complex coordinates of the pixel
            c_real = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            c_imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;

            // Initialize the complex value of the pixel
            z.x = 0;
            z.y = 0;

            // Iterate the pixel to determine whether it is in the Mandelbrot set
            for (iterations = 0; iterations < MAX_ITERATIONS; iterations++) {
                // Calculate the next complex value of the pixel
                p.x = z.x * z.x - z.y * z.y + c_real;
                p.y = 2 * z.x * z.y + c_imag;

                // If the complex value of the pixel is outside the unit circle, it is not in the Mandelbrot set
                if (p.x * p.x + p.y * p.y > 4.0) {
                    break;
                }

                // Update the complex value of the pixel
                z.x = p.x;
                z.y = p.y;
            }

            // Set the color of the pixel based on the number of iterations
            if (iterations == MAX_ITERATIONS) {
                image[3 * (y * WIDTH + x) + 0] = 0;
                image[3 * (y * WIDTH + x) + 1] = 0;
                image[3 * (y * WIDTH + x) + 2] = 0;
            } else {
                image[3 * (y * WIDTH + x) + 0] = iterations % 64 * 4;
                image[3 * (y * WIDTH + x) + 1] = iterations % 32 * 8;
                image[3 * (y * WIDTH + x) + 2] = iterations % 16 * 16;
            }
        }
    }

    // Write the image buffer to a file
    FILE *fp = fopen("mandelbrot.ppm", "w");
    fprintf(fp, "P3\n");
    fprintf(fp, "%d %d\n", WIDTH, HEIGHT);
    fprintf(fp, "255\n");
    fwrite(image, sizeof(unsigned char), WIDTH * HEIGHT * 3, fp);
    fclose(fp);

    // Free the image buffer
    free(image);

    return 0;
}