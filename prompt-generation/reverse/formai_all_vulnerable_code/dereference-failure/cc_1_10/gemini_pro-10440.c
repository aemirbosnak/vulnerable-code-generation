//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char pixel_t;

struct image {
    int width;
    int height;
    pixel_t *pixels;
};

struct image *create_image(int width, int height) {
    struct image *image = malloc(sizeof(struct image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(sizeof(pixel_t) * width * height);
    return image;
}

void destroy_image(struct image *image) {
    free(image->pixels);
    free(image);
}

void read_image(struct image *image, FILE *file) {
    fread(image->pixels, sizeof(pixel_t), image->width * image->height, file);
}

void write_image(struct image *image, FILE *file) {
    fwrite(image->pixels, sizeof(pixel_t), image->width * image->height, file);
}

void flip_image(struct image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width / 2; j++) {
            pixel_t temp = image->pixels[i * image->width + j];
            image->pixels[i * image->width + j] = image->pixels[i * image->width + image->width - 1 - j];
            image->pixels[i * image->width + image->width - 1 - j] = temp;
        }
    }
}

void change_brightness(struct image *image, int brightness) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            image->pixels[i * image->width + j] += brightness;
        }
    }
}

void change_contrast(struct image *image, int contrast) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            image->pixels[i * image->width + j] *= contrast;
        }
    }
}

int main() {
    struct image *image = create_image(640, 480);
    read_image(image, stdin);

    flip_image(image);
    change_brightness(image, 50);
    change_contrast(image, 1.2);

    write_image(image, stdout);
    destroy_image(image);
    return 0;
}