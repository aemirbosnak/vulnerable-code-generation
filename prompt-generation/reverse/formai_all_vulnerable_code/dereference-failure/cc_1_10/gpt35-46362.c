//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL 255

void flip_image(int* image, int width, int height) {
    int temp;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            temp = *(image + i * width + j);
            *(image + i * width + j) = *(image + i * width + (width - j - 1));
            *(image + i * width + (width - j - 1)) = temp;
        }
    }
}

void adjust_brightness_contrast(int* image, int width, int height, int brightness, int contrast) {
    float factor;
    contrast = (contrast / 100.0f) * MAX_PIXEL;

    if (contrast > 0) {
        factor = (259.0f * (contrast + 255.0f)) / (255.0f * (259.0f - contrast));
    }
    else {
        factor = (-contrast) / (-contrast + 259.0f);
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int value = *(image + i * width +j);
            value = (int)(factor * (value - 128.0f) + 128.0f + brightness);
            *(image + i * width + j) = value < 0 ? 0 : value > MAX_PIXEL ? MAX_PIXEL : value;
        }
    }
}

int main() {
    int width = 4, height = 4;
    int* image = (int*)malloc(width * height * sizeof(int));

    // Initialize Image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            *(image + i * width + j) = i * width + j;
        }
    }

    printf("Original Image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", *(image + i * width + j));
        }
        printf("\n");
    }

    flip_image(image, width, height);

    printf("Flipped Image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", *(image + i * width + j));
        }
        printf("\n");
    }

    adjust_brightness_contrast(image, width, height, 50, -25);

    printf("Adjusted Image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", *(image + i * width + j));
        }
        printf("\n");
    }

    free(image);

    return 0;
}