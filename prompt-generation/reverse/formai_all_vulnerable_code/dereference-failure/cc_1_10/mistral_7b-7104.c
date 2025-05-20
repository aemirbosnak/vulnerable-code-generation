//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512

typedef struct {
    float r, g, b, c, m, y, k;
} pixel_t;

void rgb_to_cmyk(float r, float g, float b, pixel_t *dest) {
    float max = fmax(fmax(r, g), b);
    float min = fmin(fmin(r, g), b);

    dest->c = (r > max) ? (1.0 - r / max) : 0.0;
    dest->m = (g > max) ? (1.0 - g / max) : (r > max) ? dest->c : 0.0;
    dest->y = (b > max) ? (1.0 - b / max) : 0.0;
    dest->k = 0.0;

    if (r < min) min = r;
    if (g < min) min = g;
    if (b < min) min = b;

    dest->k = (dest->k + max - min) / (2.0 * (1.0 - min));
}

void print_pixel(pixel_t pixel) {
    printf("\033[38;5;%dm\033[48;5;%dm\033[38;5;%dm\033[0m",
        (int)(255.0 * pixel.y + 16),
        (int)(255.0 * pixel.m + 16),
        (int)(255.0 * pixel.c + 16));
}

int main(void) {
    int i, j;
    pixel_t *image = malloc(WIDTH * HEIGHT * sizeof(pixel_t));

    for (i = 0; i < WIDTH * HEIGHT; i++) {
        image[i].r = i / (WIDTH * HEIGHT) * 255.0;
        image[i].g = i / (WIDTH * HEIGHT) * 128.0 + 128.0;
        image[i].b = i / (WIDTH * HEIGHT) * 64.0;

        rgb_to_cmyk(image[i].r, image[i].g, image[i].b, &image[i]);
    }

    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            print_pixel(image[j * WIDTH + i]);
            if (i < WIDTH - 1)
                printf("╶");
            else if (j < HEIGHT - 1)
                 printf("\n╺");
            else
                printf("\n\n");
        }
    }

    free(image);

    return 0;
}