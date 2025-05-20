//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *pixels;
} Image;

Image *image_new(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(Pixel));
    return image;
}

void image_destroy(Image *image) {
    free(image->pixels);
    free(image);
}

Pixel *image_get_pixel(Image *image, int x, int y) {
    return &image->pixels[y * image->width + x];
}

void image_set_pixel(Image *image, int x, int y, Pixel color) {
    Pixel *pixel = image_get_pixel(image, x, y);
    *pixel = color;
}

void image_save_ppm(Image *image, char *filename) {
    FILE *file = fopen(filename, "w");
    fprintf(file, "P3\n%d %d\n255\n", image->width, image->height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            Pixel *pixel = image_get_pixel(image, x, y);
            fprintf(file, "%d %d %d ", pixel->r, pixel->g, pixel->b);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

int main() {
    Image *image = image_new(640, 480);

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            Pixel color = { .r = 255, .g = 0, .b = 0 };
            image_set_pixel(image, x, y, color);
        }
    }

    image_save_ppm(image, "output.ppm");

    image_destroy(image);

    return 0;
}