//Falcon2-11B DATASET v1.0 Category: Fractal Generation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the Mandelbrot set
int mandelbrot(int x, int y) {
    // The maximum number of iterations
    int max_iterations = 100;

    double c = 0.0;
    double real = x;
    double imaginary = y;

    int iteration = 0;

    while (real*real + imaginary*imaginary < 4 && iteration < max_iterations) {
        c = real - imaginary * 0.75 * c;
        real = 2 * imaginary * c + x;
        imaginary = imaginary * imaginary - real * real + y;
        iteration++;
    }

    return iteration - 1;
}

// Function to generate the Mandelbrot set
void generate_mandelbrot() {
    // Size of the image
    int image_width = 800;
    int image_height = 600;

    // Variables to store the image
    int *image = (int*)malloc(image_width * image_height * sizeof(int));

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the image with 0
    for (int i = 0; i < image_width * image_height; i++) {
        image[i] = 0;
    }

    // Iterate over the pixels and calculate the Mandelbrot set
    for (int i = 0; i < image_width * image_height; i++) {
        int x = rand() % image_width;
        int y = rand() % image_height;

        int color = 0;
        for (int j = 0; j < 100; j++) {
            color += mandelbrot(x, y);
        }

        image[i] = color;
    }

    // Print the image
    printf("Mandelbrot Set\n");
    for (int i = 0; i < image_height; i++) {
        for (int j = 0; j < image_width; j++) {
            printf("%d", image[i * image_width + j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    free(image);
}

int main() {
    generate_mandelbrot();
    return 0;
}