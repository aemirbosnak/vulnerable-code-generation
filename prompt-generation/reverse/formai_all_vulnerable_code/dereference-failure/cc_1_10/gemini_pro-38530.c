//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 1000

typedef struct {
    double real;
    double imaginary;
} complex_t;

int main() {
    // Initialize the output image
    unsigned char *image = malloc(WIDTH * HEIGHT * 3);
    for (int i = 0; i < WIDTH * HEIGHT * 3; i++) {
        image[i] = 0;
    }

    // Initialize the complex plane
    complex_t c;
    c.real = -0.7;
    c.imaginary = 0.27015;

    // Iterate over each pixel in the output image
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Convert the pixel coordinates to a complex number
            complex_t z;
            z.real = 1.5 * (x - WIDTH / 2) / (0.5 * WIDTH);
            z.imaginary = (y - HEIGHT / 2) / (0.5 * HEIGHT);

            // Iterate the complex number using the Mandelbrot set formula
            int iter = 0;
            while (iter < MAX_ITER && z.real * z.real + z.imaginary * z.imaginary < 4) {
                double temp = z.real * z.real - z.imaginary * z.imaginary + c.real;
                z.imaginary = 2 * z.real * z.imaginary + c.imaginary;
                z.real = temp;
                iter++;
            }

            // Set the pixel color based on the number of iterations
            int color = 255 * iter / MAX_ITER;
            image[3 * (y * WIDTH + x) + 0] = color;
            image[3 * (y * WIDTH + x) + 1] = color;
            image[3 * (y * WIDTH + x) + 2] = color;
        }
    }

    // Write the output image to a file
    FILE *fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(image, 1, WIDTH * HEIGHT * 3, fp);
    fclose(fp);

    // Free the allocated memory
    free(image);

    return 0;
}