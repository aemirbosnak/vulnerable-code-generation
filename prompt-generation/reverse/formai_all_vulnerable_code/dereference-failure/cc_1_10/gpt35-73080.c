//FormAI DATASET v1.0 Category: Fractal Generation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* Securely generate random numbers using XORSHIFT */
uint32_t xorshift32(uint32_t *seed) {
    uint32_t x = *seed;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    *seed = x;
    return x;
}

/* Generate fractal based on the Mandelbrot set */
void generate_fractal(uint8_t *data, int width, int height, int iterations) {
    uint32_t seed = 42;
    #pragma omp parallel for schedule(dynamic)
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double cx = (double)x / width * 3.5 - 2.5;
            double cy = (double)y / height * 2.0 - 1.0;
            double zx = 0.0;
            double zy = 0.0;
            int i;
            for (i = 0; i < iterations; i++) {
                double nx = zx * zx - zy * zy + cx;
                double ny = 2.0 * zx * zy + cy;
                zx = nx;
                zy = ny;
                if (zx * zx + zy * zy > 4.0) break;
            }
            uint8_t value = (uint8_t)((double)i / iterations * 255);
            #pragma omp critical
            data[y * width + x] = value;
        }
    }
}

/* Save fractal image to file */
void save_image(uint8_t *data, int width, int height, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P5\n%d %d\n%d\n", width, height, 255);
    for (int i = 0; i < width * height; i++) {
        fputc(data[i], fp);
    }
    fclose(fp);
}

int main(void) {
    int width = 1024;
    int height = 768;
    int iterations = 512;
    uint8_t *data = (uint8_t *)malloc(width * height);
    generate_fractal(data, width, height, iterations);
    save_image(data, width, height, "fractal.pgm");
    free(data);
    return 0;
}