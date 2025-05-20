//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100
#define MAX_COLORS 256

typedef struct {
    int r;
    int g;
    int b;
} color_t;

int main(int argc, char *argv[]) {
    srand(time(NULL));

    color_t *palette = malloc(MAX_COLORS * sizeof(color_t));

    for (int i = 0; i < MAX_COLORS; i++) {
        palette[i].r = rand() % 256;
        palette[i].g = rand() % 256;
        palette[i].b = rand() % 256;
    }

    int **pixels = malloc(HEIGHT * sizeof(int *));
    for (int y = 0; y < HEIGHT; y++) {
        pixels[y] = malloc(WIDTH * sizeof(int));
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int color_index = rand() % MAX_COLORS;
            pixels[y][x] = color_index;
        }
    }

    FILE *output = fopen("pixel_art.ppm", "w");

    fprintf(output, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, 255);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            color_t color = palette[pixels[y][x]];
            fprintf(output, "%d %d %d ", color.r, color.g, color.b);
        }
    }

    fclose(output);

    return 0;
}