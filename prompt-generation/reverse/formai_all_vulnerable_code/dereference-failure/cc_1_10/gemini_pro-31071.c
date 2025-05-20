//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    COLOR_BLACK,
    COLOR_WHITE
} Color;

typedef struct {
    Color** pixels;
    int width;
    int height;
} Image;

Image* image_new(int width, int height) {
    Image* image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(sizeof(Color*) * height);
    for (int y = 0; y < height; y++) {
        image->pixels[y] = malloc(sizeof(Color) * width);
    }
    return image;
}

void image_free(Image* image) {
    for (int y = 0; y < image->height; y++) {
        free(image->pixels[y]);
    }
    free(image->pixels);
    free(image);
}

void image_set_pixel(Image* image, int x, int y, Color color) {
    image->pixels[y][x] = color;
}

Color image_get_pixel(Image* image, int x, int y) {
    return image->pixels[y][x];
}

void image_print(Image* image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            printf("%c", image_get_pixel(image, x, y) == COLOR_BLACK ? ' ' : '.');
        }
        printf("\n");
    }
}

int main() {
    Image* image = image_new(200, 100);
    for (int y = 10; y < 90; y++) {
        for (int x = 10; x < 190; x++) {
            if ((x - 100) * (x - 100) + (y - 50) * (y - 50) < 10000) {
                image_set_pixel(image, x, y, COLOR_BLACK);
            }
        }
    }
    image_print(image);
    image_free(image);
    return 0;
}