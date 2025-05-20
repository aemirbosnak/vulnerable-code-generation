//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define PIXEL_SIZE 5
#define NUM_COLORS 16

typedef struct {
    int r;
    int g;
    int b;
} color_t;

color_t colors[NUM_COLORS] = {
    {0, 0, 0}, {255, 0, 0}, {0, 255, 0}, {255, 255, 0},
    {0, 0, 255}, {255, 0, 255}, {0, 255, 255}, {255, 255, 255},
    {128, 0, 0}, {0, 128, 0}, {128, 128, 0}, {0, 0, 128},
    {128, 0, 128}, {0, 128, 128}, {128, 128, 128}, {192, 192, 192}
};

void generate_art(int* pixels) {
    srand(time(NULL));

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int color_index = rand() % NUM_COLORS;
            color_t color = colors[color_index];

            int pixel_x = x * PIXEL_SIZE;
            int pixel_y = y * PIXEL_SIZE;

            for (int i = 0; i < PIXEL_SIZE; i++) {
                for (int j = 0; j < PIXEL_SIZE; j++) {
                    if ((i + pixel_x) >= 0 && (i + pixel_x) < WIDTH &&
                        (j + pixel_y) >= 0 && (j + pixel_y) < HEIGHT) {
                        pixels[(y * WIDTH + x) * PIXEL_SIZE * PIXEL_SIZE +
                            (j * PIXEL_SIZE + i)] = color.r;
                    }
                }
            }
        }
    }
}

int main() {
    int* pixels = malloc(WIDTH * HEIGHT * PIXEL_SIZE * PIXEL_SIZE * sizeof(int));

    generate_art(pixels);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            for (int i = 0; i < PIXEL_SIZE; i++) {
                for (int j = 0; j < PIXEL_SIZE; j++) {
                    int pixel_index = (y * WIDTH + x) * PIXEL_SIZE * PIXEL_SIZE +
                        (j * PIXEL_SIZE + i);
                    int pixel_color = pixels[pixel_index];

                    printf("%d ", pixel_color);
                }
                printf("\n");
            }
        }
        printf("\n");
    }

    free(pixels);

    return 0;
}