//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define NUM_PIXELS (WIDTH * HEIGHT)
#define PIXEL_SIZE 3

typedef struct {
    int r;
    int g;
    int b;
} Color;

void generate_random_color(Color* color) {
    color->r = rand() % 256;
    color->g = rand() % 256;
    color->b = rand() % 256;
}

void generate_pixels(Color* pixels) {
    for (int i = 0; i < NUM_PIXELS; i++) {
        generate_random_color(&pixels[i]);
    }
}

void print_pixels(Color* pixels) {
    for (int i = 0; i < NUM_PIXELS; i++) {
        printf("%02X%02X%02X ", pixels[i].r, pixels[i].g, pixels[i].b);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Color* pixels = malloc(NUM_PIXELS * sizeof(Color));
    generate_pixels(pixels);

    printf("P6\n%d %d\n255\n", WIDTH, HEIGHT);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int pixel_index = (y * WIDTH) + x;
            Color pixel = pixels[pixel_index];

            printf("%02X%02X%02X ", pixel.r, pixel.g, pixel.b);
        }
    }

    free(pixels);
    return 0;
}