//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define the width and height of the image
#define WIDTH 800
#define HEIGHT 600

// Define the maximum number of iterations for each pixel
#define MAX_ITERATIONS 500

// Define the complex number type
typedef struct {
    double real;
    double imaginary;
} complex_t;

// Generate a random complex number within the given range
complex_t random_complex(double min_real, double max_real, double min_imag, double max_imag) {
    complex_t c;
    c.real = min_real + (max_real - min_real) * (double)rand() / (double)RAND_MAX;
    c.imaginary = min_imag + (max_imag - min_imag) * (double)rand() / (double)RAND_MAX;
    return c;
}

// Calculate the Mandelbrot set value for the given complex number
int mandelbrot(complex_t c) {
    complex_t z = {0, 0};
    int iterations = 0;

    while (iterations < MAX_ITERATIONS && (z.real * z.real + z.imaginary * z.imaginary) < 4) {
        z.real = z.real * z.real - z.imaginary * z.imaginary + c.real;
        z.imaginary = 2 * z.real * z.imaginary + c.imaginary;
        iterations++;
    }

    return iterations;
}

// Generate the Mandelbrot set image
void generate_mandelbrot(int *image, double min_real, double max_real, double min_imag, double max_imag) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            complex_t c = {min_real + (max_real - min_real) * x / WIDTH, min_imag + (max_imag - min_imag) * y / HEIGHT};
            int iterations = mandelbrot(c);
            image[y * WIDTH + x] = iterations;
        }
    }
}

// Write the Mandelbrot set image to a PPM file
void write_ppm(int *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int iterations = image[y * WIDTH + x];
            unsigned char color[3];
            if (iterations == MAX_ITERATIONS) {
                color[0] = color[1] = color[2] = 0;
            } else {
                color[0] = iterations % 256;
                color[1] = (iterations / 256) % 256;
                color[2] = (iterations / 65536) % 256;
            }
            fwrite(color, sizeof(color), 1, fp);
        }
    }
    fclose(fp);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate the Mandelbrot set image
    int *image = malloc(WIDTH * HEIGHT * sizeof(int));
    generate_mandelbrot(image, -2.0, 1.0, -1.5, 1.5);

    // Write the Mandelbrot set image to a PPM file
    write_ppm(image, "mandelbrot.ppm");

    // Free the memory allocated for the image
    free(image);

    return 0;
}