//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100
#define MAX_COLORS 256

typedef struct {
    int r, g, b;
} color_t;

void init_colors(color_t colors[MAX_COLORS]) {
    int i;
    for (i = 0; i < MAX_COLORS; i++) {
        colors[i].r = rand() % 256;
        colors[i].g = rand() % 256;
        colors[i].b = rand() % 256;
    }
}

void draw_pixel(int x, int y, color_t color, FILE *fp) {
    fprintf(fp, "%c%c%c", color.r, color.g, color.b);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <output.png> <seed>\n", argv[0]);
        return 1;
    }

    int seed = atoi(argv[2]);
    srand(seed);

    color_t colors[MAX_COLORS];
    init_colors(colors);

    FILE *fp = fopen(argv[1], "wb");
    if (fp == NULL) {
        printf("Error: could not open output file.\n");
        return 1;
    }

    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);

    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            int color_index = rand() % MAX_COLORS;
            draw_pixel(x, y, colors[color_index], fp);
        }
    }

    fclose(fp);
    printf("Generated %s.\n", argv[1]);

    return 0;
}