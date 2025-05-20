//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

typedef struct Image {
    int width;
    int height;
    char **pixels;
} Image;

Image *image_create(int w, int h) {
    Image *image = malloc(sizeof(Image));
    image->width = w;
    image->height = h;
    image->pixels = malloc(h * sizeof(char *) + 1);
    for (int i = 0; i < h; i++) {
        image->pixels[i] = malloc(w * sizeof(char) + 1);
    }
    return image;
}

void image_destroy(Image *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}

void image_set_pixel(Image *image, int x, int y, char value) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    image->pixels[y][x] = value;
}

char image_get_pixel(Image *image, int x, int y) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return 0;
    }
    return image->pixels[y][x];
}

int main() {
    Image *image = image_create(16, 16);
    image_set_pixel(image, 0, 0, 'X');
    image_set_pixel(image, 1, 1, 'O');
    image_set_pixel(image, 3, 3, '#');

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            printf("%c ", image_get_pixel(image, x, y));
        }
        printf("\n");
    }

    image_destroy(image);

    return 0;
}