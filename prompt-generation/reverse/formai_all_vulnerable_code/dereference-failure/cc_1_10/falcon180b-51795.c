//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_HEIGHT 1000
#define MAX_WIDTH 1000

typedef struct {
    int width;
    int height;
    int **data;
} Image;

Image *createImage(int width, int height) {
    Image *img = (Image *)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        img->data[i] = (int *)malloc(width * sizeof(int));
    }
    return img;
}

void destroyImage(Image *img) {
    for (int i = 0; i < img->height; i++) {
        free(img->data[i]);
    }
    free(img->data);
    free(img);
}

void printImage(Image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            printf("%d ", img->data[i][j]);
        }
        printf("\n");
    }
}

void flipImage(Image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width / 2; j++) {
            int temp = img->data[i][j];
            img->data[i][j] = img->data[i][img->width - j - 1];
            img->data[i][img->width - j - 1] = temp;
        }
    }
}

void changeBrightness(Image *img, int delta) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int value = img->data[i][j] + delta;
            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }
            img->data[i][j] = value;
        }
    }
}

void changeContrast(Image *img, int delta) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int value = img->data[i][j] + delta * (255 - img->data[i][j]);
            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }
            img->data[i][j] = value;
        }
    }
}

int main() {
    Image *img = createImage(10, 10);
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->data[i][j] = i * img->width + j;
        }
    }
    printImage(img);
    flipImage(img);
    printImage(img);
    changeBrightness(img, 50);
    printImage(img);
    changeContrast(img, 50);
    printImage(img);
    destroyImage(img);
    return 0;
}