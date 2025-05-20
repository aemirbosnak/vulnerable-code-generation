//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
    char *data;
} Image;

Image *image_new(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height);
    return image;
}

void image_free(Image *image) {
    free(image->data);
    free(image);
}

void image_set_pixel(Image *image, int x, int y, char c) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    image->data[y * image->width + x] = c;
}

char image_get_pixel(Image *image, int x, int y) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return 0;
    }
    return image->data[y * image->width + x];
}

void image_print(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            printf("%c", image_get_pixel(image, x, y));
        }
        printf("\n");
    }
}

int main() {
    Image *image = image_new(10, 10);

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            if (y == 0 || y == image->height - 1 || x == 0 || x == image->width - 1) {
                image_set_pixel(image, x, y, '*');
            } else {
                image_set_pixel(image, x, y, ' ');
            }
        }
    }
    image_print(image);

    image_free(image);

    return 0;
}