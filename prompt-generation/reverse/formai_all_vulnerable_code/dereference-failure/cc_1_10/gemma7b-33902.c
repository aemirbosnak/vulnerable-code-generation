//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

typedef struct Image {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *createImage(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * 3);
    return image;
}

void setImagePixel(Image *image, int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    if (x >= image->width || y >= image->height) {
        return;
    }
    image->data[3 * (x * image->width) + y] = r;
    image->data[3 * (x * image->width) + y + 1] = g;
    image->data[3 * (x * image->width) + y + 2] = b;
}

void displayImage(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            unsigned char r = image->data[3 * (x * image->width) + y];
            unsigned char g = image->data[3 * (x * image->width) + y + 1];
            unsigned char b = image->data[3 * (x * image->width) + y + 2];
            printf("(%d, %d) -> (%u, %u, %u)\n", x, y, r, g, b);
        }
    }
}

int main() {
    Image *image = createImage(10, 10);
    setImagePixel(image, 0, 0, 255, 0, 0);
    setImagePixel(image, 0, 1, 0, 255, 0);
    setImagePixel(image, 1, 0, 0, 0, 255);
    setImagePixel(image, 1, 1, 255, 255, 255);

    displayImage(image);

    free(image->data);
    free(image);

    return 0;
}