//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: happy
#include<stdio.h>
#include<stdlib.h>

int flip_image(int width, int height, int* image) {
    // Flip the image horizontally
    int *new_image = malloc(width * height * sizeof(int));
    int index = 0;
    int temp;
    for (int h = 0; h < height; h++) {
        for (int w = width - 1; w >= 0; w--) {
            temp = image[h * width + w];
            new_image[index] = temp;
            index++;
        }
    }
    // Update the original image with the new flipped image
    for (int i = 0; i < width * height; i++) {
        image[i] = new_image[i];
    }
    free(new_image);
    return 0;
}

int adjust_brightness_contrast(int width, int height, int* image, int brightness, int contrast) {
    // Adjust the brightness and contrast of the image
    for (int i = 0; i < width * height; i++) {
        int pixel = image[i];
        // Adjust the brightness
        if (brightness > 0) {
            pixel += brightness;
            if (pixel > 255) pixel = 255;
        } else {
            pixel += brightness;
            if (pixel < 0) pixel = 0;
        }
        // Adjust the contrast
        if (contrast > 0) {
            pixel = pixel * (100 + contrast) / 100;
            if (pixel > 255) pixel = 255;
        } else {
            pixel = pixel * (100 - contrast) / 100;
            if (pixel < 0) pixel = 0;
        }
        image[i] = pixel;
    }
    return 0;
}

int main() {
    int width = 5;
    int height = 3;
    int image[] = {
        100, 120, 80, 200, 150,
        50, 70, 90, 120, 210,
        180, 160, 140, 110, 70
    };
    printf("Original Image:\n");
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            printf("%d ", image[h * width + w]);
        }
        printf("\n");
    }

    // Flip the image
    flip_image(width, height, image);

    printf("\nFlipped Image:\n");
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            printf("%d ", image[h * width + w]);
        }
        printf("\n");
    }

    // Adjust the brightness and contrast of the image
    int brightness = 20;
    int contrast = 10;
    adjust_brightness_contrast(width, height, image, brightness, contrast);

    printf("\nAdjusted Image:\n");
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            printf("%d ", image[h * width + w]);
        }
        printf("\n");
    }

    return 0;
}