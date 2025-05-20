//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define WIDTH 1024
#define HEIGHT 1024
#define MAX_ITER 1000

typedef struct {
    double real;
    double imag;
} complex;

complex c, z;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <real> <imag>\n", argv[0]);
        exit(1);
    }

    c.real = atof(argv[1]);
    c.imag = atof(argv[2]);

    // Create the image
    unsigned char *image = malloc(WIDTH * HEIGHT * 3);

    // Iterate over each pixel
    #pragma omp parallel for schedule(dynamic)
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Convert pixel coordinates to complex number
            z.real = (4.0 * x / WIDTH) - 2.0;
            z.imag = (4.0 * y / HEIGHT) - 2.0;

            // Iterate the complex number
            int iter = 0;
            while (z.real * z.real + z.imag * z.imag < 4.0 && iter < MAX_ITER) {
                double temp = z.real * z.real - z.imag * z.imag + c.real;
                z.imag = 2.0 * z.real * z.imag + c.imag;
                z.real = temp;
                iter++;
            }

            // Set the pixel color
            int color = (iter == MAX_ITER) ? 0 : (255 * iter / MAX_ITER);
            image[y * WIDTH * 3 + x * 3 + 0] = color; // Red
            image[y * WIDTH * 3 + x * 3 + 1] = color; // Green
            image[y * WIDTH * 3 + x * 3 + 2] = color; // Blue
        }
    }

    // Write the image to a file
    FILE *fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(image, 1, WIDTH * HEIGHT * 3, fp);
    fclose(fp);

    // Free the image
    free(image);

    return 0;
}