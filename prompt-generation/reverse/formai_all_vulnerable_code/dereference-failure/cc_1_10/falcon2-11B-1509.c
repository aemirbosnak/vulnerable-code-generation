//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to flip an image horizontally
void flipHorizontal(int* image, int width, int height) {
    int temp = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            temp = image[i * width + j];
            image[i * width + j] = image[(height - 1 - i) * width + j];
            image[(height - 1 - i) * width + j] = temp;
        }
    }
}

// Function to change the brightness of an image
void changeBrightness(int* image, int width, int height, int brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel = image[i * width + j];
            int newPixel = (pixel * brightness) / 255;
            image[i * width + j] = newPixel;
        }
    }
}

// Function to change the contrast of an image
void changeContrast(int* image, int width, int height, int contrast) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel = image[i * width + j];
            int newPixel = (pixel * contrast) / 255;
            image[i * width + j] = newPixel;
        }
    }
}

// Main function
int main() {
    // Read image data
    int width, height, channels;
    FILE* imageFile = fopen("image.ppm", "r");
    fscanf(imageFile, "%d %d %d", &width, &height, &channels);
    int* imageData = (int*)malloc(width * height * channels * sizeof(int));
    fread(imageData, width * height * channels, 1, imageFile);
    fclose(imageFile);

    // Flip image horizontally
    flipHorizontal(imageData, width, height);

    // Change brightness of the image
    int brightness = 2;
    changeBrightness(imageData, width, height, brightness);

    // Change contrast of the image
    int contrast = 0.5;
    changeContrast(imageData, width, height, contrast);

    // Write modified image data to a new file
    FILE* outputFile = fopen("modified_image.ppm", "w");
    fprintf(outputFile, "P3\n%d %d\n255\n", width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(outputFile, "%d ", imageData[i * width + j]);
        }
        fprintf(outputFile, "\n");
    }
    fclose(outputFile);

    return 0;
}