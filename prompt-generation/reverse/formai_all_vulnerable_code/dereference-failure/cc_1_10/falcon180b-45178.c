//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

typedef struct {
    int width;
    int height;
    int **data;
} Image;

void createImage(Image *img, int width, int height) {
    img->width = width;
    img->height = height;
    img->data = (int **) malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        img->data[i] = (int *) malloc(width * sizeof(int));
    }
}

void destroyImage(Image *img) {
    for (int i = 0; i < img->height; i++) {
        free(img->data[i]);
    }
    free(img->data);
}

void printImage(const Image *img) {
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
            int value = (img->data[i][j] * (256 - delta)) / 256;
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
    Image img;
    createImage(&img, 100, 100);

    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            img.data[i][j] = i * img.width + j;
        }
    }

    printImage(&img);

    flipImage(&img);
    printf("Flipped image:\n");
    printImage(&img);

    changeBrightness(&img, 50);
    printf("Brightened image:\n");
    printImage(&img);

    changeContrast(&img, 50);
    printf("Contrasted image:\n");
    printImage(&img);

    destroyImage(&img);

    return 0;
}