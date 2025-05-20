//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void flip(int width, int height, int *image, int numpixels) {
    int i, j;
    int *temp = (int*)malloc(sizeof(int) * numpixels);

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            temp[i * width + j] = image[height - 1 - i * width + j];
        }
    }
    free(image);
    image = temp;
}

void change_brightness(int width, int height, int *image, int numpixels, int factor) {
    int i, j;
    int *temp = (int*)malloc(sizeof(int) * numpixels);

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            temp[i * width + j] = image[i * width + j] * factor;
        }
    }
    free(image);
    image = temp;
}

int main() {
    int width, height, numpixels;
    int *image;

    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);
    printf("Enter the number of pixels: ");
    scanf("%d", &numpixels);

    image = (int*)malloc(sizeof(int) * numpixels);

    printf("Enter the pixels of the image: ");
    for (int i = 0; i < numpixels; i++) {
        scanf("%d", &image[i]);
    }

    printf("Flipping the image...\n");
    flip(width, height, image, numpixels);

    printf("Changing the brightness of the image by a factor of 1.5...\n");
    change_brightness(width, height, image, numpixels, 1.5);

    printf("Pixels of the flipped and brightened image: ");
    for (int i = 0; i < numpixels; i++) {
        printf("%d ", image[i]);
    }
    printf("\n");

    free(image);
    return 0;
}