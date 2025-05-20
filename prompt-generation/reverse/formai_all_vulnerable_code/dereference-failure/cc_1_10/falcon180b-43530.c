//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 24
#define CHARSET_SIZE 94
#define ALPHA 0.7
#define BETA 0.3
#define GAMMA 0.5
#define DELTA 0.1

typedef struct {
    int r, g, b;
} Color;

Color image[HEIGHT][WIDTH];
char charset[CHARSET_SIZE] = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

void load_image(char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        exit(1);
    }
    fseek(fp, 54, SEEK_SET); // Skip header
    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);
    if (width!= WIDTH || height!= HEIGHT) {
        printf("Error: Image dimensions do not match (%dx%d).\n", width, height);
        exit(1);
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            unsigned char pixel;
            fread(&pixel, sizeof(unsigned char), 1, fp);
            int r = pixel >> 16 & 0xFF;
            int g = pixel >> 8 & 0xFF;
            int b = pixel & 0xFF;
            image[y][x].r = r;
            image[y][x].g = g;
            image[y][x].b = b;
        }
    }
    fclose(fp);
}

void convert_to_ascii(char* filename) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Could not create file '%s'.\n", filename);
        exit(1);
    }
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            Color c = image[y][x];
            int index = (int)round(ALPHA * c.r + BETA * c.g + GAMMA * c.b);
            if (index < 0) index = 0;
            if (index >= CHARSET_SIZE) index = CHARSET_SIZE - 1;
            fprintf(fp, "%c", charset[index]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii>\n", argv[0]);
        return 1;
    }
    char* input_image = argv[1];
    char* output_ascii = argv[2];
    load_image(input_image);
    convert_to_ascii(output_ascii);
    printf("Conversion completed successfully!\n");
    return 0;
}