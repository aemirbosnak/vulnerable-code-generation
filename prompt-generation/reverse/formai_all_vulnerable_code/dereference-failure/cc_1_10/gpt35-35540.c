//FormAI DATASET v1.0 Category: Fractal Generation ; Style: careful
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define WIDTH 1024
#define HEIGHT 1024
#define NUM_ITERATIONS 1000

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} color_t;

void apply_color(color_t *color, double value, double multiplier) {
    double brightness = 1 - pow(1 - value, multiplier);
    color->r = (uint8_t) (brightness * 255);
    color->g = (uint8_t) (brightness * 255);
    color->b = 0;
}

void write_image(char *filename, color_t *image) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        fwrite(&(image[i].r), 1, 1, file);
        fwrite(&(image[i].g), 1, 1, file);
        fwrite(&(image[i].b), 1, 1, file);
    }
    fclose(file);
}

int main() {
    uint16_t *counts = calloc(WIDTH * HEIGHT, sizeof(uint16_t));
    color_t *image = calloc(WIDTH * HEIGHT, sizeof(color_t));
    double x_start = -2.75;
    double y_start = -1.75;
    double x_end = 1;
    double y_end = 1.75;
    double x_pixel_size = (x_end - x_start) / WIDTH;
    double y_pixel_size = (y_end - y_start) / HEIGHT;
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            double zx = 0;
            double zy = 0;
            double cx = x_start + x * x_pixel_size;
            double cy = y_start + y * y_pixel_size;
            int i;
            for (i = 0; i < NUM_ITERATIONS; i++) {
                double new_zx = zx * zx - zy * zy + cx;
                double new_zy = 2 * zx * zy + cy;
                if (new_zx * new_zx + new_zy * new_zy > 4) {
                    break;
                }
                zx = new_zx;
                zy = new_zy;
            }
            counts[y * WIDTH + x] = i;
        }
    }
    uint16_t max_count = 0;
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        if (counts[i] > max_count) {
            max_count = counts[i];
        }
    }
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        double value = (double) counts[i] / max_count;
        apply_color(&(image[i]), value, 5);
    }
    write_image("fractal.ppm", image);
    free(counts);
    free(image);
    return 0;
}