//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

Pixel *readImage(char *filename, int *width, int *height);
void writeImage(char *filename, Pixel *image, int width, int height);
void flipHorizontal(Pixel *image, int width, int height);
void flipVertical(Pixel *image, int width, int height);
void adjustBrightness(Pixel *image, int width, int height, int brightness);
void adjustContrast(Pixel *image, int width, int height, float contrast);

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int width, height;
    Pixel *image = readImage(argv[1], &width, &height);

    // Flip image horizontally
    flipHorizontal(image, width, height);

    // Flip image vertically
    flipVertical(image, width, height);

    // Adjust brightness of image
    adjustBrightness(image, width, height, 50);

    // Adjust contrast of image
    adjustContrast(image, width, height, 1.5);

    // Write new image
    writeImage(argv[2], image, width, height);

    free(image);

    return 0;
}

Pixel *readImage(char *filename, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Could not open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char magic[3];
    fscanf(file, "%2s\n", magic);
    if (strcmp(magic, "P6")) {
        fprintf(stderr, "Error: Invalid file format\n");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d %d\n", width, height);

    int max;
    fscanf(file, "%d\n", &max);
    if (max != 255) {
        fprintf(stderr, "Error: Unsupported image format\n");
        exit(EXIT_FAILURE);
    }

    Pixel *image = malloc(*width * *height * sizeof(Pixel));

    fread(image, sizeof(Pixel), *width * *height, file);

    fclose(file);
    return image;
}

void writeImage(char *filename, Pixel *image, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: Could not open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fprintf(file, "P6\n%d %d\n%d\n", width, height, 255);

    fwrite(image, sizeof(Pixel), width * height, file);

    fclose(file);
}

void flipHorizontal(Pixel *image, int width, int height) {
    Pixel temp;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            temp = image[y * width + x];
            image[y * width + x] = image[y * width + (width - x - 1)];
            image[y * width + (width - x - 1)] = temp;
        }
    }
}

void flipVertical(Pixel *image, int width, int height) {
    Pixel temp;
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height / 2; y++) {
            temp = image[y * width + x];
            image[y * width + x] = image[(height - y - 1) * width + x];
            image[(height - y - 1) * width + x] = temp;
        }
    }
}

void adjustBrightness(Pixel *image, int width, int height, int brightness) {
    for (int i = 0; i < width * height; i++) {
        image[i].red = image[i].red + brightness;
        image[i].green = image[i].green + brightness;
        image[i].blue = image[i].blue + brightness;
    }
}

void adjustContrast(Pixel *image, int width, int height, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < width * height; i++) {
        image[i].red = factor * (image[i].red - 128) + 128;
        image[i].green = factor * (image[i].green - 128) + 128;
        image[i].blue = factor * (image[i].blue - 128) + 128;
    }
}