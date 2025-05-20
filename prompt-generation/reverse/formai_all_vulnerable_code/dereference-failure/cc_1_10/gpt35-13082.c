//FormAI DATASET v1.0 Category: Fractal Generation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int width = 800;
    int height = 800;
    int max_steps = 10000;
    double zoom = 0.5;
    double offsetX = -0.6;
    double offsetY = 0.0;
    double minR = -2.0;
    double maxR = 2.0;
    double minI = -2.0;
    double maxI = 2.0;

    unsigned char* image = (unsigned char*)calloc(width * height, sizeof(unsigned char));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double cR = x / (double)width * (maxR - minR) + minR - offsetX;
            double cI = y / (double)height * (maxI - minI) + minI - offsetY;

            double zR = 0.0;
            double zI = 0.0;

            int steps = 0;
            while (zR * zR + zI * zI < 4 && steps < max_steps) {
                double tmp = zR * zR - zI * zI + cR;
                zI = 2 * zR * zI + cI;
                zR = tmp;
                steps++;
            }

            if (steps == max_steps) {
                image[y * width + x] = 0;
            }
            else {
                double log_zn = log(zR * zR + zI * zI) / 2;
                double nu = log(log_zn / log(2)) / log(2);
                image[y * width + x] = 255 * nu;
            }
        }
    }

    FILE* outfile = fopen("fractal.pgm", "wb");
    fprintf(outfile, "P5 %d %d 255\n", width, height);
    fwrite(image, sizeof(unsigned char), width * height, outfile);
    fclose(outfile);

    free(image);

    return 0;
}