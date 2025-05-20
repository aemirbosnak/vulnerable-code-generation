//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Function to flip the image
void flipImage(int *image, int width, int height) {
    int *temp = malloc(sizeof(int) * width * height);
    int index = 0;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            temp[(height - 1 - row) * width + col] = image[index++];
        }
    }
    // Copy the flipped image back into original image
    for (int i = 0; i < width * height; i++) {
        image[i] = temp[i];
    }
    free(temp);
}

// Function to change the brightness of the image
void changeBrightness(int *image, int width, int height, int brightness) {
    for (int i = 0; i < width * height; i++) {
        image[i] += brightness;
        if (image[i] > 255) {
            image[i] = 255;
        }
        if (image[i] < 0) {
            image[i] = 0;
        }
    }
}

// Function to change the contrast of the image
void changeContrast(int *image, int width, int height, float contrast) {
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for (int i = 0; i < width * height; i++) {
        image[i] = factor * (image[i] - 128) + 128;
        if (image[i] > 255) {
            image[i] = 255;
        }
        if (image[i] < 0) {
            image[i] = 0;
        }
    }
}

int main() {
    int image[] = {
        0, 0, 0, 255, 255, 255,
        0, 0, 0, 255, 255, 255,
        0, 0, 0, 255, 255, 255,
        0, 0, 0, 255, 255, 255
    };
    int width = 6;
    int height = 4;
    int brightness = 50;
    float contrast = 150;
    
    printf("Flipping the image...\n");
    flipImage(image, width, height);
    printf("The image has been flipped!\n\n");
    
    printf("Increasing brightness...\n");
    changeBrightness(image, width, height, brightness);
    printf("The brightness has been increased by %d!\n\n", brightness);
    
    printf("Changing contrast...\n");
    changeContrast(image, width, height, contrast);
    printf("The contrast has been changed by %.2f!\n\n", contrast);
    
    printf("The final image is:\n");
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            printf("%d ", image[row * width + col]);
        }
        printf("\n");
    }
    
    return 0;
}