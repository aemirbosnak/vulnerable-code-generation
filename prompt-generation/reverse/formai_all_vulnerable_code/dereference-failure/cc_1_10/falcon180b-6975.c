//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#include <time.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define MAX_CHANNELS 4

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
} pixel_t;

typedef struct {
    pixel_t* pixels;
    int width;
    int height;
    int channels;
} image_t;

image_t* create_image(int width, int height, int channels) {
    image_t* image = malloc(sizeof(image_t));
    image->pixels = malloc(width * height * channels * sizeof(pixel_t));
    image->width = width;
    image->height = height;
    image->channels = channels;
    return image;
}

void destroy_image(image_t* image) {
    free(image->pixels);
    free(image);
}

pixel_t* get_pixel(image_t* image, int x, int y) {
    return &image->pixels[(y * image->width + x) * image->channels];
}

void set_pixel(image_t* image, int x, int y, pixel_t pixel) {
    pixel_t* target = get_pixel(image, x, y);
    *target = pixel;
}

void fill_image(image_t* image, pixel_t pixel) {
    int size = image->width * image->height * image->channels;
    memset(image->pixels, pixel.red, size * sizeof(pixel_t));
}

void save_image(image_t* image, char* filename) {
    FILE* file = fopen(filename, "wb");
    fwrite(image->pixels, image->width * image->height * image->channels, sizeof(pixel_t), file);
    fclose(file);
}

int main() {
    srand(time(NULL));

    image_t* image = create_image(MAX_WIDTH, MAX_HEIGHT, MAX_CHANNELS);
    fill_image(image, (pixel_t){ 255, 0, 0, 255 });

    for (int i = 0; i < 100; i++) {
        int x = rand() % image->width;
        int y = rand() % image->height;
        pixel_t pixel = (pixel_t){ rand() % 256, rand() % 256, rand() % 256, rand() % 256 };
        set_pixel(image, x, y, pixel);
    }

    save_image(image, "random.png");
    destroy_image(image);

    return 0;
}