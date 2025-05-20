//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Elementary, my dear Watson!

typedef struct {
    uint8_t *data;
    size_t width, height;
} Image;

Image *image_new(size_t width, size_t height) {
    Image *image = malloc(sizeof(Image));
    if (!image) return NULL;
    image->data = malloc(width * height);
    if (!image->data) { free(image); return NULL; }
    image->width = width;
    image->height = height;
    return image;
}

void image_free(Image *image) {
    free(image->data);
    free(image);
}

int image_load(Image *image, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return -1;
    fread(&image->width, sizeof(size_t), 1, file);
    fread(&image->height, sizeof(size_t), 1, file);
    fread(image->data, image->width * image->height, 1, file);
    fclose(file);
    return 0;
}

int image_save(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) return -1;
    fwrite(&image->width, sizeof(size_t), 1, file);
    fwrite(&image->height, sizeof(size_t), 1, file);
    fwrite(image->data, image->width * image->height, 1, file);
    fclose(file);
    return 0;
}

void image_flip_horizontal(Image *image) {
    for (size_t y = 0; y < image->height; y++) {
        for (size_t x = 0; x < image->width / 2; x++) {
            uint8_t temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[y * image->width + image->width - x - 1];
            image->data[y * image->width + image->width - x - 1] = temp;
        }
    }
}

void image_flip_vertical(Image *image) {
    for (size_t y = 0; y < image->height / 2; y++) {
        for (size_t x = 0; x < image->width; x++) {
            uint8_t temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[(image->height - y - 1) * image->width + x];
            image->data[(image->height - y - 1) * image->width + x] = temp;
        }
    }
}

void image_adjust_brightness(Image *image, int delta) {
    for (size_t y = 0; y < image->height; y++) {
        for (size_t x = 0; x < image->width; x++) {
            image->data[y * image->width + x] = image->data[y * image->width + x] + delta;
        }
    }
}

void image_adjust_contrast(Image *image, float factor) {
    for (size_t y = 0; y < image->height; y++) {
        for (size_t x = 0; x < image->width; x++) {
            image->data[y * image->width + x] = image->data[y * image->width + x] * factor;
        }
    }
}

int main() {
    Image *image = image_new(640, 480);
    if (!image) return -1;
    if (image_load(image, "image.raw") != 0) return -1;

    // Enhance the image using our elementary methods.

    image_flip_horizontal(image);
    image_flip_vertical(image);
    image_adjust_brightness(image, 32);
    image_adjust_contrast(image, 1.5);

    // The game is afoot!

    if (image_save(image, "enhanced.raw") != 0) return -1;
    image_free(image);
    return 0;
}