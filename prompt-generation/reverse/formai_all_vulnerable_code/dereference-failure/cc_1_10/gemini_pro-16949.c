//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    unsigned char r, g, b;
} pixel_t;

typedef struct {
    int width, height;
    pixel_t pixels[MAX_WIDTH][MAX_HEIGHT];
} image_t;

image_t* image_new(int width, int height) {
    image_t* image = malloc(sizeof(image_t));
    image->width = width;
    image->height = height;
    for (int i = 0; i < MAX_WIDTH; i++) {
        for (int j = 0; j < MAX_HEIGHT; j++) {
            image->pixels[i][j].r = 0;
            image->pixels[i][j].g = 0;
            image->pixels[i][j].b = 0;
        }
    }
    return image;
}

void image_free(image_t* image) {
    free(image);
}

void image_set_pixel(image_t* image, int x, int y, pixel_t color) {
    image->pixels[x][y] = color;
}

pixel_t image_get_pixel(image_t* image, int x, int y) {
    return image->pixels[x][y];
}

void image_save_ppm(image_t* image, const char* filename) {
    FILE* f = fopen(filename, "wb");
    fprintf(f, "P6\n%d %d\n255\n", image->width, image->height);
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            pixel_t color = image->pixels[j][i];
            fwrite(&color.r, 1, 1, f);
            fwrite(&color.g, 1, 1, f);
            fwrite(&color.b, 1, 1, f);
        }
    }
    fclose(f);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    const char* input_filename = argv[1];
    const char* output_filename = argv[2];

    FILE* f = fopen(input_filename, "rb");
    if (f == NULL) {
        fprintf(stderr, "Error: Could not open input file '%s'\n", input_filename);
        return 1;
    }

    int width, height;
    fscanf(f, "%d %d\n", &width, &height);

    image_t* image = image_new(width, height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixel_t color;
            fread(&color.r, 1, 1, f);
            fread(&color.g, 1, 1, f);
            fread(&color.b, 1, 1, f);
            image_set_pixel(image, j, i, color);
        }
    }

    fclose(f);

    // Apply a filter to the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixel_t color = image_get_pixel(image, j, i);
            color.r = (color.r + color.g + color.b) / 3;
            color.g = (color.r + color.g + color.b) / 3;
            color.b = (color.r + color.g + color.b) / 3;
            image_set_pixel(image, j, i, color);
        }
    }

    image_save_ppm(image, output_filename);

    image_free(image);

    return 0;
}