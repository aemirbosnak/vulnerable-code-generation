//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to flip an image
void flip_image(int *pixels, int width, int height) {
    int temp;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            temp = pixels[j * height + i];
            pixels[j * height + i] = pixels[width * height - i - 1 + j];
            pixels[width * height - i - 1 + j] = temp;
        }
    }
}

// Function to change image brightness
void adjust_brightness(int *pixels, int width, int height, float factor) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int color = pixels[j * height + i];
            int brightness = (int) (color * factor);
            if (brightness > 255) {
                brightness = 255;
            } else if (brightness < 0) {
                brightness = 0;
            }
            pixels[j * height + i] = brightness;
        }
    }
}

// Function to change image contrast
void adjust_contrast(int *pixels, int width, int height, float factor) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int color = pixels[j * height + i];
            int contrast = (int) (color * factor);
            if (contrast > 255) {
                contrast = 255;
            } else if (contrast < 0) {
                contrast = 0;
            }
            pixels[j * height + i] = contrast;
        }
    }
}

int main() {
    int width = 640, height = 480;
    int *pixels = (int *) malloc(width * height * sizeof(int));

    for (int i = 0; i < width * height; i++) {
        pixels[i] = rand() % 255;
    }

    printf("Original image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", pixels[j * height + i]);
        }
        printf("\n");
    }

    printf("\nFlipped image:\n");
    flip_image(pixels, width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", pixels[j * height + i]);
        }
        printf("\n");
    }

    printf("\nBrightness increased by 1.5:\n");
    adjust_brightness(pixels, width, height, 1.5);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", pixels[j * height + i]);
        }
        printf("\n");
    }

    printf("\nContrast increased by 0.5:\n");
    adjust_contrast(pixels, width, height, 0.5);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", pixels[j * height + i]);
        }
        printf("\n");
    }

    free(pixels);
    return 0;
}