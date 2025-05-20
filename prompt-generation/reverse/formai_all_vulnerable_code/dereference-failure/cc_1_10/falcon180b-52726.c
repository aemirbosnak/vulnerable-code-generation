//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

typedef struct {
    int x, y;
    char c;
    unsigned char r, g, b;
} pixel;

void render(pixel *pixels, int width, int height) {
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            pixel p = pixels[(j * width) + i];
            printf("%c", p.c);
        }
        printf("\n");
    }
}

void load_image(char *filename, pixel *pixels, int width, int height) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open image file.\n");
        exit(1);
    }

    fseek(fp, 54, SEEK_SET); // skip header
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            unsigned char bgr[3];
            fread(bgr, 3, 1, fp);
            pixels[(j * width) + i].r = bgr[0];
            pixels[(j * width) + i].g = bgr[1];
            pixels[(j * width) + i].b = bgr[2];
        }
    }

    fclose(fp);
}

int main() {
    char filename[256];
    printf("Enter image filename: ");
    scanf("%s", filename);

    pixel *pixels = malloc(sizeof(pixel) * WIDTH * HEIGHT);
    load_image(filename, pixels, WIDTH, HEIGHT);

    render(pixels, WIDTH, HEIGHT);

    free(pixels);

    return 0;
}