//FormAI DATASET v1.0 Category: Image Editor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024
#define MAX_PIXEL_VALUE 255

typedef unsigned char pixel_t;

typedef struct {
    pixel_t red;
    pixel_t green;
    pixel_t blue;
} RGB_pixel_t;

typedef struct {
    int width;
    int height;
    RGB_pixel_t pixels[MAX_WIDTH][MAX_HEIGHT];
} RGB_image_t;

void grayscale(RGB_image_t* image) {
    int row, column;
    unsigned char gs_value;

    for (row = 0; row < image->height; row++) {
        for (column = 0; column < image->width; column++) {
            RGB_pixel_t* pixel = &image->pixels[row][column];

            gs_value = (pixel->red + pixel->green + pixel->blue) / 3;

            pixel->red = gs_value;
            pixel->green = gs_value;
            pixel->blue = gs_value;
        }
    }
}

void invert_color(RGB_image_t* image) {
    int row, column;

    for (row = 0; row < image->height; row++) {
        for (column = 0; column < image->width; column++) {
            RGB_pixel_t* pixel = &image->pixels[row][column];

            pixel->red = MAX_PIXEL_VALUE - pixel->red;
            pixel->green = MAX_PIXEL_VALUE - pixel->green;
            pixel->blue = MAX_PIXEL_VALUE - pixel->blue;
        }
    }
}


int main(int argc, const char* argv[]) {
    RGB_image_t image;

    // Load image from disk
    FILE* image_file = fopen("image.rgb", "rb");
    if (!image_file) {
        printf("Error: could not open image file.");
        exit(1);
    }

    fread(&image.width, sizeof(int), 1, image_file);
    fread(&image.height, sizeof(int), 1, image_file);

    if (image.width > MAX_WIDTH) {
        printf("Error: image width exceeds maximum width of %d", MAX_WIDTH);
        exit(1);
    }

    if (image.height > MAX_HEIGHT) {
        printf("Error: image height exceeds maximum height of %d", MAX_HEIGHT);
        exit(1);
    }

    // Read pixel data
    int row, column;
    for (row = 0; row < image.height; row++) {
        for (column = 0; column < image.width; column++) {
            fread(&image.pixels[row][column], sizeof(RGB_pixel_t), 1, image_file);
        }
    }

    fclose(image_file);

    // Apply filters
    grayscale(&image);
    invert_color(&image);

    // Save modified image to disk
    FILE* output_file = fopen("modified_image.rgb", "wb");
    if (!output_file) {
        printf("Error: could not open output file.");
        exit(1);
    }

    fwrite(&image.width, sizeof(int), 1, output_file);
    fwrite(&image.height, sizeof(int), 1, output_file);

    for (row = 0; row < image.height; row++) {
        for (column = 0; column <image.width; column++) {
            fwrite(&image.pixels[row][column], sizeof(RGB_pixel_t), 1, output_file);
        }
    }

    fclose(output_file);

    printf("Finished processing image.");
    return 0;
}