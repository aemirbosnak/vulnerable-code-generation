//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_IMAGE_SIZE 1024

typedef struct Image {
    int width, height;
    unsigned char *data;
} Image;

Image *createImage(int w, int h) {
    Image *image = malloc(sizeof(Image));
    image->width = w;
    image->height = h;
    image->data = malloc(w * h * 3);
    return image;
}

void setImagePixel(Image *image, int x, int y, int r, int g, int b) {
    if (x >= image->width || y >= image->height) {
        return;
    }
    image->data[3 * (x * image->width + y)] = r;
    image->data[3 * (x * image->width + y) + 1] = g;
    image->data[3 * (x * image->width + y) + 2] = b;
}

void displayImage(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int r = image->data[3 * (x * image->width + y)];
            int g = image->data[3 * (x * image->width + y) + 1];
            int b = image->data[3 * (x * image->width + y) + 2];
            printf("(%d, %d, %d) ", r, g, b);
        }
        printf("\n");
    }
}

int main() {
    Image *image = createImage(5, 5);
    setImagePixel(image, 2, 2, 255, 0, 0);
    setImagePixel(image, 3, 2, 0, 255, 0);
    setImagePixel(image, 4, 2, 0, 0, 255);
    displayImage(image);

    free(image->data);
    free(image);

    return 0;
}