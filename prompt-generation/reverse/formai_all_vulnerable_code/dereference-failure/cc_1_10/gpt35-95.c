//FormAI DATASET v1.0 Category: Image Editor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXEL 255

// Struct to represent an image pixel
typedef struct Pixel {
    unsigned char r, g, b;
} Pixel;

// Struct to represent an image
typedef struct Image {
    Pixel *pixels;
    int width, height;
} Image;

// Function to create a new image
Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(sizeof(Pixel) * width * height);
    return image;
}

// Function to free an image from memory
void free_image(Image *image) {
    free(image->pixels);
    free(image);
}

// Function to get the color value of a pixel at a given location in the image
Pixel get_pixel(Image *image, int x, int y) {
    int index = (y * image->width) + x;
    return image->pixels[index];
}

// Function to set the color value of a pixel at a given location in the image
void set_pixel(Image *image, int x, int y, Pixel pixel) {
    int index = (y * image->width) + x;
    image->pixels[index] = pixel;
}

// Function to apply a color filter to an image
void color_filter(Image *image, int r, int g, int b) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            Pixel pixel = get_pixel(image, j, i);
            pixel.r = pixel.r * r / MAX_PIXEL;
            pixel.g = pixel.g * g / MAX_PIXEL;
            pixel.b = pixel.b * b / MAX_PIXEL;
            set_pixel(image, j, i, pixel);
        }
    }
}

// Function to apply a grayscale filter to an image
void grayscale_filter(Image *image) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            Pixel pixel = get_pixel(image, j, i);
            unsigned char gray_value = (pixel.r + pixel.g + pixel.b) / 3;
            pixel.r = gray_value;
            pixel.g = gray_value;
            pixel.b = gray_value;
            set_pixel(image, j, i, pixel);
        }
    }
}

// Function to apply a noise filter to an image
void noise_filter(Image *image, double factor) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            Pixel pixel = get_pixel(image, j, i);
            unsigned char noise_value = (rand() % (int)(MAX_PIXEL * factor)) + (MAX_PIXEL * (1 - factor));
            pixel.r = (pixel.r + noise_value) / 2;
            pixel.g = (pixel.g + noise_value) / 2;
            pixel.b = (pixel.b + noise_value) / 2;
            set_pixel(image, j, i, pixel);
        }
    }
}

int main() {
    int width = 640;
    int height = 480;
    Image *image = create_image(width, height);

    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            Pixel pixel = {rand() % MAX_PIXEL, rand() % MAX_PIXEL, rand() % MAX_PIXEL};
            set_pixel(image, j, i, pixel);
        }
    }

    printf("Original image created.\n");

    grayscale_filter(image);

    printf("Grayscale filter applied.\n");

    color_filter(image, 100, 50, 200);

    printf("Color filter applied.\n");

    noise_filter(image, 0.1);

    printf("Noise filter applied.\n");

    free_image(image);

    printf("Image memory freed.\n");

    return 0;
}