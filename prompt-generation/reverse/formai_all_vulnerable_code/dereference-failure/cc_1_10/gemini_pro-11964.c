//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    int width;
    int height;
    char data[MAX_WIDTH * MAX_HEIGHT];
} Image;

Image *image_new(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    memset(image->data, 0, width * height);
    return image;
}

void image_free(Image *image) {
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
        return ' ';
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
    Image *image = image_new(50, 50);

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            double dx = (x - image->width / 2.0) / (image->width / 2.0);
            double dy = (y - image->height / 2.0) / (image->height / 2.0);
            double r = sqrt(dx * dx + dy * dy);
            if (r < 0.5) {
                image_set_pixel(image, x, y, '*');
            }
        }
    }

    image_print(image);

    image_free(image);

    return 0;
}