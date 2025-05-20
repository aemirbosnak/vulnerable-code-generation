//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    int r, g, b;
} pixel_t;

void flip_image(pixel_t image[MAX_WIDTH][MAX_HEIGHT], int width, int height) {
    int i, j;
    for (i = 0; i < height / 2; i++) {
        for (j = 0; j < width; j++) {
            pixel_t tmp = image[j][i];
            image[j][i] = image[j][height - i - 1];
            image[j][height - i - 1] = tmp;
        }
    }
}

void adjust_brightness(pixel_t image[MAX_WIDTH][MAX_HEIGHT], int width, int height, int brightness) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            image[j][i].r += brightness;
            image[j][i].g += brightness;
            image[j][i].b += brightness;
        }
    }
}

void adjust_contrast(pixel_t image[MAX_WIDTH][MAX_HEIGHT], int width, int height, int contrast) {
    int i, j;
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            image[j][i].r = factor * (image[j][i].r - 128) + 128;
            image[j][i].g = factor * (image[j][i].g - 128) + 128;
            image[j][i].b = factor * (image[j][i].b - 128) + 128;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s input_file output_file brightness contrast\n", argv[0]);
        return 1;
    }
    FILE* input_file = fopen(argv[1], "rb");
    if (!input_file) {
        printf("Error: could not open input file %s\n", argv[1]);
        return 1;
    }
    FILE* output_file = fopen(argv[2], "wb");
    if (!output_file) {
        fclose(input_file);
        printf("Error: could not open output file %s\n", argv[2]);
        return 1;
    }
    int brightness = atoi(argv[3]);
    int contrast = atoi(argv[4]);
    int width, height;
    pixel_t image[MAX_WIDTH][MAX_HEIGHT];
    fread(&width, sizeof(int), 1, input_file);
    fread(&height, sizeof(int), 1, input_file);
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: image dimensions are too large\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fread(&image[j][i].r, sizeof(unsigned char), 1, input_file);
            fread(&image[j][i].g, sizeof(unsigned char), 1, input_file);
            fread(&image[j][i].b, sizeof(unsigned char), 1, input_file);
        }
    }
    fclose(input_file);
    adjust_brightness(image, width, height, brightness);
    adjust_contrast(image, width, height, contrast);
    flip_image(image, width, height);
    fwrite(&width, sizeof(int), 1, output_file);
    fwrite(&height, sizeof(int), 1, output_file);
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fwrite(&image[j][i].r, sizeof(unsigned char), 1, output_file);
            fwrite(&image[j][i].g, sizeof(unsigned char), 1, output_file);
            fwrite(&image[j][i].b, sizeof(unsigned char), 1, output_file);
        }
    }
    fclose(output_file);
    return 0;
}