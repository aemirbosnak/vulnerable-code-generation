//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100
#define MAX_COLOR 256

typedef struct {
    int r;
    int g;
    int b;
} Color;

void init_color(Color* color) {
    color->r = rand() % MAX_COLOR;
    color->g = rand() % MAX_COLOR;
    color->b = rand() % MAX_COLOR;
}

int main() {
    srand(time(NULL));

    Color* colors = malloc(MAX_COLOR * sizeof(Color));
    for (int i = 0; i < MAX_COLOR; i++) {
        init_color(&colors[i]);
    }

    int* pixels = malloc(WIDTH * HEIGHT * sizeof(int));
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int index = rand() % MAX_COLOR;
            pixels[y * WIDTH + x] = index;
        }
    }

    FILE* fp = fopen("pixel_art.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, MAX_COLOR);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int index = pixels[y * WIDTH + x];
            Color color = colors[index];
            fprintf(fp, "%d %d %d ", color.r, color.g, color.b);
        }
    }

    fclose(fp);

    free(pixels);
    free(colors);

    return 0;
}