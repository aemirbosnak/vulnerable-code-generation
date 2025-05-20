//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    char *pixels;
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height);
    return image;
}

void destroy_image(Image *image) {
    free(image->pixels);
    free(image);
}

void set_pixel(Image *image, int x, int y, char color) {
    image->pixels[y * image->width + x] = color;
}

char get_pixel(Image *image, int x, int y) {
    return image->pixels[y * image->width + x];
}

void save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);
    fwrite(image->pixels, 1, image->width * image->height, file);
    fclose(file);
}

int main() {
    Image *image = create_image(100, 100);

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            char color = (x + y) % 256;
            set_pixel(image, x, y, color);
        }
    }

    save_image(image, "image.bin");
    destroy_image(image);
    return 0;
}