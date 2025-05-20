//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 32
#define HEIGHT 32
#define MAX_COLOR 256

typedef struct {
    unsigned char r, g, b;
} Color;

Color palette[MAX_COLOR];
unsigned char pixel[WIDTH * HEIGHT];

void init_palette() {
    int i;

    for (i = 0; i < MAX_COLOR; i++) {
        palette[i].r = i * 32;
        palette[i].g = i;
        palette[i].b = i * 22;
    }
}

void generate_pixel(int x, int y) {
    Color c1, c2, result;
    int i;

    c1 = palette[x % 256];
    c2 = palette[(y % 256) + (x % 2)];

    result.r = (c1.r + c2.r) / 2;
    result.g = (c1.g + c2.g) / 2;
    result.b = (c1.b + c2.b) / 2;

    pixel[y * WIDTH + x] = (unsigned char)(result.r << 5 | result.g >> 3 | result.b >> 3);
}

void generate_image(int seed) {
    int i, j;

    srand(seed);

    init_palette();

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            generate_pixel(j, i);
        }
    }

    FILE *fp = fopen("output.ppm", "wb");

    fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fprintf(fp, "%d ", pixel[i * WIDTH + j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <seed>\n", argv[0]);
        return 1;
    }

    generate_image(atoi(argv[1]));

    return 0;
}