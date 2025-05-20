//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: careful
#include <stdio.h>

#define MAX_WIDTH 1920
#define MAX_HEIGHT 1080

void flip_horizontal(unsigned char *image, int width, int height) {
    unsigned char tmp;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            tmp = image[y * width + x];
            image[y * width + x] = image[y * width + (width - x - 1)];
            image[y * width + (width - x - 1)] = tmp;
        }
    }
}

void flip_vertical(unsigned char *image, int width, int height) {
    unsigned char tmp;

    for (int y = 0; y < height / 2; y++) {
        for (int x = 0; x < width; x++) {
            tmp = image[y * width + x];
            image[y * width + x] = image[(height - y - 1) * width + x];
            image[(height - y - 1) * width + x] = tmp;
        }
    }
}

void adjust_brightness(unsigned char *image, int width, int height, float amount) {
    unsigned char value;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            value = image[y * width + x] * amount;
            if (value > 255) value = 255;
            image[y * width + x] = value;
        }
    }
}

void adjust_contrast(unsigned char *image, int width, int height, float amount) {
    unsigned char value;

    float factor = (259.0 * (amount + 255.0)) / (255.0 * (259.0 - amount));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            value = factor * (image[y * width + x] - 128) + 128;
            if (value < 0) value = 0;
            if (value > 255) value = 255;
            image[y * width + x] = value;
        }
    }
}

int main() {
    unsigned char image[MAX_WIDTH * MAX_HEIGHT];
    int width, height;

    // load image from file
    FILE *fp = fopen("input.pgm", "rb");
    if (fp == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }
    char magic[3];
    fscanf(fp, "%s\n", magic);
    if (magic[0] != 'P' || magic[1] != '5') {
        printf("Error: not a PGM file!\n");
        return 1;
    }
    fscanf(fp, "%d %d\n", &width, &height);
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: image too large!\n");
        return 1;
    }
    fread(image, sizeof(unsigned char), width * height, fp);
    fclose(fp);

    // flip image horizontally
    flip_horizontal(image, width, height);

    // flip image vertically
    flip_vertical(image, width, height);

    // adjust brightness
    adjust_brightness(image, width, height, 1.5f);

    // adjust contrast
    adjust_contrast(image, width, height, 50.0f);

    // save image to file
    fp = fopen("output.pgm", "wb");
    fprintf(fp, "P5\n%d %d\n255\n", width, height);
    fwrite(image, sizeof(unsigned char), width * height, fp);
    fclose(fp);

    return 0;
}