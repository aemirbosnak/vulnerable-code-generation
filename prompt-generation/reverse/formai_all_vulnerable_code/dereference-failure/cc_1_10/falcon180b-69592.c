//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024
#define MAX_LAYERS 10

typedef struct {
    int width;
    int height;
    int layers;
    char *data;
} Image;

Image *createImage(int width, int height, int layers) {
    Image *image = (Image *)malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->layers = layers;
    image->data = (char *)malloc(sizeof(char) * width * height * layers);
    return image;
}

void destroyImage(Image *image) {
    free(image->data);
    free(image);
}

void setPixel(Image *image, int x, int y, int layer, int value) {
    int offset = (y * image->width + x) * image->layers + layer;
    image->data[offset] = value;
}

int getPixel(Image *image, int x, int y, int layer) {
    int offset = (y * image->width + x) * image->layers + layer;
    return image->data[offset];
}

void fillLayer(Image *image, int layer, int value) {
    int size = image->width * image->height;
    memset(image->data + layer * size, value, size);
}

void copyImage(Image *src, Image *dst) {
    memcpy(dst->data, src->data, src->width * src->height * src->layers);
}

int main() {
    Image *image1 = createImage(512, 512, 3);
    Image *image2 = createImage(512, 512, 3);

    fillLayer(image1, 0, 255);
    fillLayer(image1, 1, 0);
    fillLayer(image1, 2, 128);

    fillLayer(image2, 0, 0);
    fillLayer(image2, 1, 255);
    fillLayer(image2, 2, 128);

    copyImage(image1, image2);

    destroyImage(image1);
    destroyImage(image2);

    return 0;
}