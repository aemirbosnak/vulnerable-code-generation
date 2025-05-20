//FormAI DATASET v1.0 Category: Fractal Generation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 50

void writeImage(char* filename, unsigned char* buffer, int width, int height) {
    FILE* imageFile = fopen(filename, "wb");
    fprintf(imageFile, "P5\n%d %d\n255\n", width, height);
    fwrite(buffer, 1, width * height, imageFile);
    fclose(imageFile);
}

void generateFractal(double xMin, double xMax, double yMin, double yMax, int width, int height, unsigned char* buffer) {

    double x, y, xTemp;
    int i, j, iteration;
    double xScale = (xMax - xMin) / (double)width;
    double yScale = (yMax - yMin) / (double)height;

    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            x = xMin + i * xScale;
            y = yMin + j * yScale;

            iteration = 0;
            xTemp = 0.0;

            while (x * x + y * y <= 4.0 && iteration < MAX_ITERATIONS) {
                xTemp = x * x - y * y + x;
                y = 2.0 * x * y + y;
                x = xTemp;
                iteration++;
            }

            buffer[i + j * width] = iteration * 5;
        }
    }
}

int main() {
    double xMin = -2.0;
    double xMax = 2.0;
    double yMin = -1.5;
    double yMax = 1.5;

    unsigned char *buffer = (unsigned char*)malloc(WIDTH * HEIGHT * sizeof(unsigned char));
    generateFractal(xMin, xMax, yMin, yMax, WIDTH, HEIGHT, buffer);

    char filename[20];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(filename, "fractal_%d%d%d.pgm", tm.tm_hour, tm.tm_min, tm.tm_sec);

    writeImage(filename, buffer, WIDTH, HEIGHT);

    free(buffer);

    printf("Fractal image saved as %s\n", filename);

    return 0;
}