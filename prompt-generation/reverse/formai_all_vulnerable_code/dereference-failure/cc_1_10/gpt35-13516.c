//FormAI DATASET v1.0 Category: Fractal Generation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WINDOW_WIDTH 800 // width of the window
#define WINDOW_HEIGHT 600 // height of the window
#define MAX_ITERATIONS 10000 // maximum number of iterations per pixel
#define BAILOUT 2 // bailout value for Mandelbrot set

double map(double value, double start1, double stop1, double start2, double stop2) {
    return start2 + (stop2 - start2) * ((value - start1) / (stop1 - start1));
}

int mandelbrot(double x, double y) {
    double real = x;
    double imag = y;
    int iterations = 0;

    while (iterations < MAX_ITERATIONS) {
        double r2 = real * real;
        double i2 = imag * imag;
        if (r2 + i2 > BAILOUT) {
            break;
        }
        double new_real = r2 - i2 + x;
        double new_imag = 2 * real * imag + y;
        real = new_real;
        imag = new_imag;
        iterations++;
    }
    return iterations;
}

void generate_fractal(unsigned char *image_data) {
    srand(time(NULL)); // seed the random number generator
    double x_start = map(rand(), 0, RAND_MAX, -2, 1); // generate a random number for the x start value
    double x_end = map(rand(), 0, RAND_MAX, x_start, x_start + 3); // generate a random number for the x end value
    double y_start = map(rand(), 0, RAND_MAX, -1.5, 1.5); // generate a random number for the y start value
    double y_end = map(rand(), 0, RAND_MAX, y_start, y_start + 3); // generate a random number for the y end value

    // iterate through each pixel of the window
    for (int y = 0; y < WINDOW_HEIGHT; y++) {
        for (int x = 0; x < WINDOW_WIDTH; x++) {
            double real = map(x, 0, WINDOW_WIDTH, x_start, x_end);
            double imag = map(y, 0, WINDOW_HEIGHT, y_start, y_end);
            int iterations = mandelbrot(real, imag);
            double brightness = map(iterations, 0, MAX_ITERATIONS, 0, 255);
            int index = (x + y * WINDOW_WIDTH) * 4;
            image_data[index] = brightness;
            image_data[index + 1] = brightness;
            image_data[index + 2] = brightness;
            image_data[index + 3] = 255;
        }
    }
}

int main() {
    unsigned char *image_data = (unsigned char *) malloc(WINDOW_WIDTH * WINDOW_HEIGHT * 4 * sizeof(unsigned char)); // allocate memory for the image data
    generate_fractal(image_data);

    FILE *fp = fopen("fractal.ppm", "wb"); // open a binary file for writing
    fprintf(fp, "P6 %d %d 255\n", WINDOW_WIDTH, WINDOW_HEIGHT); // write the header of the PPM file
    fwrite(image_data, sizeof(unsigned char), WINDOW_WIDTH * WINDOW_HEIGHT * 4, fp); // write the image data to the file
    fclose(fp); // close the file

    free(image_data); // free the memory
    return 0;
}