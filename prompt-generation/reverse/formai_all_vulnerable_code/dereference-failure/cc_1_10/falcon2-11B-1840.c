//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
    int* pixels;
} Image;

Image* create_image(int width, int height) {
    Image* image = (Image*)malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = (int*)malloc(width * height * sizeof(int));
    return image;
}

void destroy_image(Image* image) {
    free(image->pixels);
    free(image);
}

void set_pixel(Image* image, int x, int y, int color) {
    image->pixels[x + y * image->width] = color;
}

int get_pixel(Image* image, int x, int y) {
    return image->pixels[x + y * image->width];
}

void print_image(Image* image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            printf("%d ", get_pixel(image, x, y));
        }
        printf("\n");
    }
}

int main() {
    Image* image = create_image(100, 100);

    set_pixel(image, 50, 50, 255);
    set_pixel(image, 75, 75, 0);
    set_pixel(image, 25, 25, 0);
    set_pixel(image, 75, 25, 0);
    set_pixel(image, 25, 75, 0);

    print_image(image);

    destroy_image(image);

    return 0;
}