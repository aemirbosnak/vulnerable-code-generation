//GPT-4o-mini DATASET v1.0 Category: Fractal Generation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000

// Function to generate the Mandelbrot set
void generateMandelbrot(double minRe, double maxRe, double minIm, double maxIm, int maxIter) {
    int *image = (int *)malloc(WIDTH * HEIGHT * sizeof(int));
    
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double cRe = minRe + (maxRe - minRe) * x / (WIDTH - 1);
            double cIm = minIm + (maxIm - minIm) * y / (HEIGHT - 1);
            double zRe = cRe, zIm = cIm;
            int isInside = 1;
            int n;
            for (n = 0; n < maxIter; n++) {
                if (zRe * zRe + zIm * zIm > 4.0) {
                    isInside = 0;
                    break;
                }
                double tempRe = zRe * zRe - zIm * zIm + cRe;
                zIm = 2 * zRe * zIm + cIm;
                zRe = tempRe;
            }
            if (isInside) {
                image[y * WIDTH + x] = 0; // Black for points in the Mandelbrot set
            } else {
                image[y * WIDTH + x] = (n % 256); // Color depending on how fast the point escapes
            }
        }
    }

    // Save to PPM format
    FILE *fp = fopen("mandelbrot.ppm", "wb");
    if (!fp) {
        fprintf(stderr, "Error opening file for writing.\n");
        free(image);
        return;
    }
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        fputc(image[i], fp);  // Red channel
        fputc(image[i], fp);  // Green channel
        fputc(image[i], fp);  // Blue channel
    }
    fclose(fp);
    free(image);
}

// Main function for user input and initial setup
int main() {
    double minRe = -2.0, maxRe = 1.0;
    double minIm = -1.5, maxIm = 1.5;
    int maxIter = MAX_ITER;

    printf("Generating the Mandelbrot Set:\n");
    printf("-------------------------------------------------\n");
    printf("Width: %d, Height: %d\n", WIDTH, HEIGHT);
    printf("Range: [%f, %f] to [%f, %f]\n", minRe, minIm, maxRe, maxIm);
    printf("Maximum Iterations: %d\n", maxIter);
    printf("Output will be saved as 'mandelbrot.ppm'\n");

    generateMandelbrot(minRe, maxRe, minIm, maxIm, maxIter);
    
    printf("Mandelbrot set generation complete.\n");
    return 0;
}