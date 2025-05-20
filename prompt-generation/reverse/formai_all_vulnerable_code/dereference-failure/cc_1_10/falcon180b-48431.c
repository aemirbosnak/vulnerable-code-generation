//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: unmistakable
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
} Color;

int main() {
    srand(time(NULL));

    Color *palette = malloc(MAX_COLORS * sizeof(Color));
    for (int i = 0; i < MAX_COLORS; ++i) {
        palette[i].r = rand() % 256;
        palette[i].g = rand() % 256;
        palette[i].b = rand() % 256;
    }

    int *pixels = malloc(WIDTH * HEIGHT * sizeof(int));
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            pixels[y * WIDTH + x] = rand() % MAX_COLORS;
        }
    }

    FILE *fp = fopen("pixel_art.ppm", "wb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    fprintf(fp, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, MAX_COLORS);

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            int color_index = pixels[y * WIDTH + x];
            Color color = palette[color_index];

            fprintf(fp, "%d %d %d ", color.r, color.g, color.b);
        }
    }

    fclose(fp);

    free(pixels);
    free(palette);

    return 0;
}