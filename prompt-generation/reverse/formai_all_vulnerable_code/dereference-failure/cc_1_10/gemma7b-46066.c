//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct Pixel {
    int r, g, b, a;
} Pixel;

Pixel pixels[MAX_WIDTH * MAX_HEIGHT];

void draw_pixel(int x, int y, int r, int g, int b, int a) {
    pixels[x + MAX_WIDTH * y].r = r;
    pixels[x + MAX_WIDTH * y].g = g;
    pixels[x + MAX_WIDTH * y].b = b;
    pixels[x + MAX_WIDTH * y].a = a;
}

void image_load(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return;
    }

    int width = MAX_WIDTH;
    int height = MAX_HEIGHT;
    unsigned char *data = (unsigned char *)malloc(width * height * 4);

    fread(data, 1, width * height * 4, fp);
    fclose(fp);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            draw_pixel(x, y, data[x + width * y * 3], data[x + width * y * 3] >> 8, data[x + width * y * 3] >> 16, data[x + width * y * 3] >> 24);
        }
    }

    free(data);
}

void image_save(char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        return;
    }

    int width = MAX_WIDTH;
    int height = MAX_HEIGHT;

    unsigned char *data = (unsigned char *)malloc(width * height * 4);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            data[x + width * y * 3] = pixels[x + MAX_WIDTH * y].r;
            data[x + width * y * 3] |= pixels[x + MAX_WIDTH * y].g << 8;
            data[x + width * y * 3] |= pixels[x + MAX_WIDTH * y].b << 16;
            data[x + width * y * 3] |= pixels[x + MAX_WIDTH * y].a << 24;
        }
    }

    fwrite(data, 1, width * height * 4, fp);
    fclose(fp);

    free(data);
}

int main() {
    image_load("image.jpg");
    image_save("image_edited.jpg");

    return 0;
}