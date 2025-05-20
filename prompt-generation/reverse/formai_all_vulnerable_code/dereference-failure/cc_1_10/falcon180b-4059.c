//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

typedef struct {
    int width;
    int height;
    int *data;
} Image;

Image *createImage(int width, int height) {
    Image *img = (Image *)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = (int *)malloc(sizeof(int) * width * height);
    return img;
}

void destroyImage(Image *img) {
    free(img->data);
    free(img);
}

void flipImage(Image *img) {
    int width = img->width;
    int height = img->height;
    int *data = img->data;
    for (int y = 0; y < height / 2; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;
            int newIndex = (height - y - 1) * width + x;
            int temp = data[index];
            data[index] = data[newIndex];
            data[newIndex] = temp;
        }
    }
}

void changeBrightness(Image *img, float factor) {
    int width = img->width;
    int height = img->height;
    int *data = img->data;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;
            int value = data[index];
            int newValue = round((1 - factor) * value + factor * 255);
            data[index] = newValue;
        }
    }
}

void changeContrast(Image *img, float factor) {
    int width = img->width;
    int height = img->height;
    int *data = img->data;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;
            int value = data[index];
            int newValue = round((value - 127) * factor + 127);
            data[index] = newValue;
        }
    }
}

void printImage(Image *img) {
    int width = img->width;
    int height = img->height;
    int *data = img->data;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;
            printf("%d ", data[index]);
        }
        printf("\n");
    }
}

int main() {
    Image *img = createImage(10, 10);
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int index = y * img->width + x;
            img->data[index] = x * y;
        }
    }
    flipImage(img);
    changeBrightness(img, 2.0);
    changeContrast(img, 1.5);
    printImage(img);
    destroyImage(img);
    return 0;
}