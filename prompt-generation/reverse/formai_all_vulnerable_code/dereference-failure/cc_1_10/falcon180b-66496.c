//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define SCALE 20
#define NUM_COLORS 8

typedef struct {
    int r;
    int g;
    int b;
} Color;

Color colors[NUM_COLORS] = {
    {255, 0, 0}, // red
    {0, 255, 0}, // green
    {0, 0, 255}, // blue
    {255, 255, 0}, // yellow
    {0, 255, 255}, // cyan
    {255, 0, 255}, // magenta
    {0, 0, 0}, // black
    {255, 255, 255} // white
};

int main() {
    srand(time(NULL));

    FILE *fp = fopen("image.ppm", "wb");

    fprintf(fp, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, 255);

    int **pixels = (int **)malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        pixels[i] = (int *)malloc(WIDTH * sizeof(int));
        for (int j = 0; j < WIDTH; j++) {
            pixels[i][j] = 0;
        }
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int colorIndex = rand() % NUM_COLORS;
            Color color = colors[colorIndex];

            int r = color.r * (rand() % 256);
            int g = color.g * (rand() % 256);
            int b = color.b * (rand() % 256);

            pixels[y][x] = (r << 16) | (g << 8) | b;
        }
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            fprintf(fp, "%d ", pixels[y][x]);
        }
    }

    fclose(fp);

    return 0;
}