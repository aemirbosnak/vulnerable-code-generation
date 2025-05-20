//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define MAX_COLOR 256

typedef struct {
    int x, y;
    int r, g, b;
} Pixel;

int main(int argc, char *argv[]) {
    if (argc!= 5) {
        printf("Usage: %s <width> <height> <output_file> <color>\n", argv[0]);
        return 1;
    }

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    char *output_file = argv[3];
    char *color = argv[4];

    Pixel *pixels = malloc(sizeof(Pixel) * width * height);
    memset(pixels, 0, sizeof(Pixel) * width * height);

    int r, g, b;
    sscanf(color, "#%02x%02x%02x", &r, &g, &b);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            pixels[j * width + i].x = i;
            pixels[j * width + i].y = j;
            pixels[j * width + i].r = r;
            pixels[j * width + i].g = g;
            pixels[j * width + i].b = b;
        }
    }

    FILE *fp = fopen(output_file, "wb");
    if (fp == NULL) {
        printf("Error: cannot open %s\n", output_file);
        return 1;
    }

    fprintf(fp, "P6\n%d %d\n%d\n", width, height, MAX_COLOR);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            fprintf(fp, "%d %d %d ", pixels[j * width + i].r, pixels[j * width + i].g, pixels[j * width + i].b);
        }
    }

    fclose(fp);
    free(pixels);

    printf("Done.\n");
    return 0;
}