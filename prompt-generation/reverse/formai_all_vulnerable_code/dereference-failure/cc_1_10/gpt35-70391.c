//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BRIGHTNESS 50
#define CONTRAST 1.5

typedef struct {
    uint8_t* pixels;
    size_t width;
    size_t height;
} image;

void flip_image(image* img) {
    uint8_t* tmp = (uint8_t*)malloc(sizeof(uint8_t) * img->width);
    size_t row_size = img->width * sizeof(uint8_t);
    for (size_t i = 0; i < img->height / 2; ++i) {
        memcpy(tmp, img->pixels + i * row_size, row_size);
        memcpy(img->pixels + i * row_size, img->pixels + (img->height - i - 1) * row_size, row_size);
        memcpy(img->pixels + (img->height - i - 1) * row_size, tmp, row_size);
    }
    free(tmp);
}

void adjust_brightness(image* img, int brightness) {
    for (size_t i = 0; i < img->width * img->height; ++i) {
        int val = img->pixels[i] + brightness;
        val = val < 0 ? 0 : (val > 255 ? 255 : val);
        img->pixels[i] = (uint8_t)val;
    }
}

void adjust_contrast(image* img, float contrast) {
    float factor = (259.0f * (contrast * 255.0f + 255.0f)) / (255.0f * (259.0f - contrast * 255.0f));
    for (size_t i = 0; i < img->width * img->height; ++i) {
        int val = (int)(((float)img->pixels[i] - 128.0f) * factor + 128.0f + 0.5f);
        val = val < 0 ? 0 : (val > 255 ? 255 : val);
        img->pixels[i] = (uint8_t)val;
    }
}

int main() {
    // Load the image
    // For simplicity, let's just assume we have a 3x3 grayscale image
    uint8_t pixels[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    image img = { pixels, 3, 3 };

    // Print the original image
    printf("Original image:\n");
    for (size_t i = 0; i < img.height; ++i) {
        for (size_t j = 0; j < img.width; ++j) {
            printf("%d ", img.pixels[i * img.width + j]);
        }
        printf("\n");
    }

    // Flip the image
    flip_image(&img);
    printf("Flipped image:\n");
    for (size_t i = 0; i < img.height; ++i) {
        for (size_t j = 0; j < img.width; ++j) {
            printf("%d ", img.pixels[i * img.width + j]);
        }
        printf("\n");
    }

    // Adjust brightness
    adjust_brightness(&img, BRIGHTNESS);
    printf("Brightness adjusted:\n");
    for (size_t i = 0; i < img.height; ++i) {
        for (size_t j = 0; j < img.width; ++j) {
            printf("%d ", img.pixels[i * img.width + j]);
        }
        printf("\n");
    }

    // Adjust contrast
    adjust_contrast(&img, CONTRAST);
    printf("Contrast adjusted:\n");
    for (size_t i = 0; i < img.height; ++i) {
        for (size_t j = 0; j < img.width; ++j) {
            printf("%d ", img.pixels[i * img.width + j]);
        }
        printf("\n");
    }

    return 0;
}