//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

#define MAX_IMAGE_SIZE 1000

typedef struct {
    uint8_t *data;
    int width;
    int height;
} Image;

void flip_image(Image *image) {
    int i, j;
    uint8_t temp;

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[i * image->width + image->width - 1 - j];
            image->data[i * image->width + image->width - 1 - j] = temp;
        }
    }
}

int main() {
    Image image;
    image.data = (uint8_t*)malloc(MAX_IMAGE_SIZE);
    image.width = 10;
    image.height = 10;

    for (int i = 0; i < image.width * image.height; i++) {
        image.data[i] = (uint8_t)rand() % 255;
    }

    flip_image(&image);

    printf("Original image:\n");
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            printf("%d ", image.data[i * image.width + j]);
        }
        printf("\n");
    }

    printf("\nFlipped image:\n");
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            printf("%d ", image.data[i * image.width + image.width - 1 - j]);
        }
        printf("\n");
    }

    free(image.data);
    return 0;
}