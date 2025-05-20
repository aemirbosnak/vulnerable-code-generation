//FormAI DATASET v1.0 Category: Image Editor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct pixel {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} pixel;

typedef struct image {
    uint32_t width;
    uint32_t height;
    pixel* pixels;
} image;

// returns a new blank image with given dimensions
image new_image(uint32_t width, uint32_t height) {
    image img;
    img.width = width;
    img.height = height;
    img.pixels = calloc(img.width * img.height, sizeof(pixel));
    return img;
}

// returns the pixel at the given coordinates
pixel* get_pixel(const image* img, uint32_t x, uint32_t y) {
    return &(img->pixels[y * img->width + x]);
}

// sets the pixel at the given coordinates to the given color
void set_pixel(image* img, uint32_t x, uint32_t y, pixel color) {
    *get_pixel(img, x, y) = color;
}

// applies a filter to the image
void apply_filter(image* img, bool (*filter)(const image* img, uint32_t x, uint32_t y, pixel* color)) {
    for (uint32_t x = 0; x < img->width; x++) {
        for (uint32_t y = 0; y < img->height; y++) {
            pixel color = *get_pixel(img, x, y);
            if (filter(img, x, y, &color)) {
                set_pixel(img, x, y, color);
            }
        }
    }
}

// a sample filter that makes the image grayscale
bool grayscale_filter(const image* img, uint32_t x, uint32_t y, pixel* color) {
    uint8_t gray = (color->red + color->green + color->blue) / 3;
    color->red = gray;
    color->green = gray;
    color->blue = gray;
    return true;
}

int main() {
    image img = new_image(256, 256);

    // draw a gradient
    for (uint32_t x = 0; x < img.width; x++) {
        for (uint32_t y = 0; y < img.height; y++) {
            pixel color = {
                .red = x * 255 / img.width,
                .green = y * 255 / img.height,
                .blue = 0
            };
            set_pixel(&img, x, y, color);
        }
    }

    // apply grayscale filter
    apply_filter(&img, grayscale_filter);

    // output the result in PPM format
    printf("P3\n%d %d\n255\n", img.width, img.height);
    for (uint32_t y = 0; y < img.height; y++) {
        for (uint32_t x = 0; x < img.width; x++) {
            pixel color = *get_pixel(&img, x, y);
            printf("%d %d %d ", color.red, color.green, color.blue);
        }
        printf("\n");
    }

    return 0;
}