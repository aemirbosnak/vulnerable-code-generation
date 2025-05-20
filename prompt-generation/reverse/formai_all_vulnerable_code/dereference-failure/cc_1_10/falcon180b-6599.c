//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24
#define MAX_COLORS 256

struct pixel {
    int x, y;
    char color;
};

struct image {
    int width, height;
    struct pixel *pixels;
};

void read_image(const char *filename, struct image *img) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    img->pixels = malloc(size);
    fread(img->pixels, size, 1, fp);

    fclose(fp);

    img->width = size / 3;
    img->height = 1;
}

void write_ascii_art(const struct image *img, FILE *fp) {
    int i, j;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            struct pixel p = img->pixels[i * img->width + j];
            fprintf(fp, "%c", p.color);
        }
        fprintf(fp, "\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input.bmp output.txt\n", argv[0]);
        return 1;
    }

    struct image img;
    read_image(argv[1], &img);

    FILE *fp = fopen(argv[2], "w");
    if (fp == NULL) {
        printf("Error: Could not open %s\n", argv[2]);
        return 1;
    }

    write_ascii_art(&img, fp);

    fclose(fp);

    printf("Done.\n");
    return 0;
}