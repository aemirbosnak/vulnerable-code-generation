//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_DEPTH 10
#define NOISE_SCALE 0.05
#define NOISE_OFFSET 1.0
#define NOISE_POWER 1.5
#define NOISE_FREQUENCY 0.01
#define NOISE_SEED 42

typedef struct {
    int x, y;
    int depth;
    int color;
} Pixel;

void generate(int x, int y, int depth, Pixel *pixels) {
    if (depth == 0) {
        pixels[y * WIDTH + x].color = rand() % 7 + 1;
        return;
    }

    int nx = x + rand() % 3 - 1;
    int ny = y + rand() % 3 - 1;

    if (nx < 0 || nx >= WIDTH || ny < 0 || ny >= HEIGHT)
        return;

    generate(nx, ny, depth - 1, pixels);
}

int main() {
    srand(time(NULL));

    Pixel *pixels = (Pixel *)malloc(WIDTH * HEIGHT * sizeof(Pixel));

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            generate(x, y, MAX_DEPTH, pixels);
        }
    }

    FILE *fp = fopen("art.ppm", "wb");

    fprintf(fp, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, 255);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            Pixel p = pixels[y * WIDTH + x];
            fprintf(fp, "%d %d %d ", p.color, p.color, p.color);
        }
    }

    fclose(fp);

    free(pixels);

    return 0;
}