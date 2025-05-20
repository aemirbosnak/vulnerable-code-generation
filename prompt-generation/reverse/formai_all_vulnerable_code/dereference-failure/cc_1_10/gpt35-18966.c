//FormAI DATASET v1.0 Category: Fractal Generation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800 // width of the window
#define HEIGHT 800 // height of the window
#define MAX_ITERATIONS 100 // maximum iteration per pixel
#define MIN_C_REAL -2.0 // minimum real value of C
#define MAX_C_REAL 2.0 // maximum real value of C
#define MIN_C_IMAG -2.0 // minimum imaginary value of C
#define MAX_C_IMAG 2.0 // maximum imaginary value of C

// function to generate colors for the fractal
int get_color(int iteration) {
    int r, g, b;
    r = iteration * 255 / MAX_ITERATIONS;
    g = iteration * 255 / MAX_ITERATIONS;
    b = iteration * 255 / MAX_ITERATIONS;
    return (r << 16) | (g << 8) | b;
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Open the output file
    FILE *f = fopen("fractal.ppm", "wb");
    if (!f) {
        printf("Unable to create output file");
        return 1;
    }

    // Write the PPM header
    fprintf(f, "P6\n%d %d\n255\n", WIDTH, HEIGHT);

    // Allocate memory for the fractal
    unsigned char *image = (unsigned char *)malloc(WIDTH * HEIGHT * 3);

    // Loop through every pixel
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Map the pixel coordinates to the range of C values
            double c_real = ((double)x / WIDTH) * (MAX_C_REAL - MIN_C_REAL) + MIN_C_REAL;
            double c_imag = ((double)y / HEIGHT) * (MAX_C_IMAG - MIN_C_IMAG) + MIN_C_IMAG;

            // Initialize the real and imaginary parts of Z to 0.0
            double z_real = 0.0;
            double z_imag = 0.0;

            // Loop through the iterations
            int iteration = 0;
            while (z_real * z_real + z_imag * z_imag < 4 && iteration < MAX_ITERATIONS) {
                // Perform the complex multiplication
                double temp_real = z_real * z_real - z_imag * z_imag + c_real;
                double temp_imag = 2.0 * z_real * z_imag + c_imag;
                z_real = temp_real;
                z_imag = temp_imag;
                iteration++;
            }

            // Set the pixel color
            int color;
            if (iteration == MAX_ITERATIONS) {
                // Pixel is in the fractal
                color = get_color(0);
            } else {
                // Pixel is not in the fractal
                color = get_color(iteration);
            }

            // Write the pixel color to the image buffer
            image[(y * WIDTH + x) * 3] = color >> 16;
            image[(y * WIDTH + x) * 3 + 1] = color >> 8;
            image[(y * WIDTH + x) * 3 + 2] = color;

        }
    }

    // Write the image to the output file
    fwrite(image, sizeof(unsigned char), WIDTH * HEIGHT * 3, f);

    // Clean up
    fclose(f);
    free(image);

    return 0;
}