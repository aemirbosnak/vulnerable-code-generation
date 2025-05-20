//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define IMAGE_HEIGHT 100
#define IMAGE_WIDTH 100
#define MAX_PIXEL_VALUE 255

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel_t;

typedef struct {
    int height;
    int width;
    pixel_t *pixels;
} image_t;

void flip_image(image_t *image) {
    int half_width = image->width / 2;
    int row_size = sizeof(pixel_t) * image->width;
    pixel_t *temp_row = malloc(row_size);
    for (int i = 0; i < image->height; i++) {
        int opposite_row_index = (image->height - 1) - i;
        pixel_t *current_row = image->pixels + (i * image->width);
        pixel_t *opposite_row = image->pixels + (opposite_row_index * image->width);
        memcpy(temp_row, current_row, row_size);
        memcpy(current_row, opposite_row, row_size);
        memcpy(opposite_row, temp_row, row_size);
    }
    free(temp_row);
}

void adjust_brightness(image_t *image, int brightness) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            pixel_t *pixel = &image->pixels[i * image->width + j];
            int r = pixel->red + brightness;
            int g = pixel->green + brightness;
            int b = pixel->blue + brightness;
            r = r < 0 ? 0 : r;
            r = r > MAX_PIXEL_VALUE ? MAX_PIXEL_VALUE : r;
            g = g < 0 ? 0 : g;
            g = g > MAX_PIXEL_VALUE ? MAX_PIXEL_VALUE : g;
            b = b < 0 ? 0 : b;
            b = b > MAX_PIXEL_VALUE ? MAX_PIXEL_VALUE : b;
            pixel->red = (unsigned char)r;
            pixel->green = (unsigned char)g;
            pixel->blue = (unsigned char)b;
        }
    }
}

void adjust_contrast(image_t *image, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            pixel_t *pixel = &image->pixels[i * image->width + j];
            int r = (int)(factor * (pixel->red - 128) + 128);
            int g = (int)(factor * (pixel->green - 128) + 128);
            int b = (int)(factor * (pixel->blue - 128) + 128);
            r = r < 0 ? 0 : r;
            r = r > MAX_PIXEL_VALUE ? MAX_PIXEL_VALUE : r;
            g = g < 0 ? 0 : g;
            g = g > MAX_PIXEL_VALUE ? MAX_PIXEL_VALUE : g;
            b = b < 0 ? 0 : b;
            b = b > MAX_PIXEL_VALUE ? MAX_PIXEL_VALUE : b;
            pixel->red = (unsigned char)r;
            pixel->green = (unsigned char)g;
            pixel->blue = (unsigned char)b;
        }
    }
}

int main() {
    image_t image = {IMAGE_HEIGHT, IMAGE_WIDTH, malloc(sizeof(pixel_t) * IMAGE_HEIGHT * IMAGE_WIDTH)};
    srand(1);
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            pixel_t *pixel = &image.pixels[i * IMAGE_WIDTH + j];
            pixel->red = rand() % MAX_PIXEL_VALUE;
            pixel->green = rand() % MAX_PIXEL_VALUE;
            pixel->blue = rand() % MAX_PIXEL_VALUE;
        }
    }

    flip_image(&image);
    adjust_brightness(&image, 50);
    adjust_contrast(&image, 50.0f);

    free(image.pixels);
    return 0;
}