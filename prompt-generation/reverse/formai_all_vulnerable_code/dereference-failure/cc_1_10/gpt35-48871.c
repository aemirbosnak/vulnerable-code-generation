//FormAI DATASET v1.0 Category: Fractal Generation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

#define MAX_ITERATIONS 200

typedef struct {
    double real;
    double imag;
} ComplexNumber;

void drawPixel(unsigned char *image, int x, int y, int red, int green, int blue) {
    int index = (x + y * WINDOW_WIDTH) * 3;
    image[index] = red;
    image[index + 1] = green;
    image[index + 2] = blue;
}

void generateFractal(unsigned char *image, ComplexNumber c) {
    for (int y=0; y<WINDOW_HEIGHT; y++) {
        for (int x=0; x<WINDOW_WIDTH; x++) {

            double real = (x - WINDOW_WIDTH / 2.0) / (WINDOW_WIDTH / 4.0);
            double imag = (y - WINDOW_HEIGHT / 2.0) / (WINDOW_HEIGHT / 4.0);
            ComplexNumber z = {real, imag};

            int iterations = 0;
            while (iterations < MAX_ITERATIONS && z.real * z.real + z.imag * z.imag < 4.0) {
                double newReal = z.real * z.real - z.imag * z.imag + c.real;
                double newImag = 2.0 * z.real * z.imag + c.imag;
                z.real = newReal;
                z.imag = newImag;
                iterations++;
            }

            int red = 255 - iterations % 255;
            int green = 255 - iterations % 200;
            int blue = 255 - iterations % 150;

            drawPixel(image, x, y, red, green, blue);

        }
    }
}

int main() {
    srand(time(NULL));
    ComplexNumber c = {rand() / (RAND_MAX / 4.0) - 2.0, rand() / (RAND_MAX / 4.0) - 2.0};
    printf("Generating fractal with c = %.2f + %.2fi\n", c.real, c.imag);

    unsigned char *image = calloc(WINDOW_WIDTH * WINDOW_HEIGHT * 3, sizeof(unsigned char));
    generateFractal(image, c);

    FILE *file = fopen("fractal.ppm", "w");
    fprintf(file, "P3 %d %d 255\n", WINDOW_WIDTH, WINDOW_HEIGHT);
    for (int i=0; i<WINDOW_WIDTH * WINDOW_HEIGHT * 3; i++) {
        fprintf(file, "%d ", image[i]);
    }
    fclose(file);
    printf("Fractal saved to fractal.ppm\n");

    free(image);
    return 0;
}