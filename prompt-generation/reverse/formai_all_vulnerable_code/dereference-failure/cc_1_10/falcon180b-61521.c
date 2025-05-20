//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

typedef struct {
    int x, y;
    char c;
} pixel;

pixel *read_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    pixel *pixels = malloc(width * height * sizeof(pixel));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(&pixels[i * width + j].c, sizeof(char), 1, fp);
        }
    }

    fclose(fp);
    return pixels;
}

void print_ascii_art(pixel *pixels, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", pixels[i * width + j].c);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s input_image output_ascii_art\n", argv[0]);
        return 1;
    }

    char *input_filename = argv[1];
    char *output_filename = argv[2];

    pixel *pixels = read_image(input_filename);
    print_ascii_art(pixels, MAX_WIDTH, MAX_HEIGHT);

    free(pixels);
    return 0;
}