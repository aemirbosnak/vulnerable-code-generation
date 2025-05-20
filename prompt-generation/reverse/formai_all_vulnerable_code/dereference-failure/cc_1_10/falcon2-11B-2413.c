//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to flip an image horizontally
void flipImageHorizontal(unsigned char* image, int width, int height) {
    int i;
    for (i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char temp = image[width - 1 - j];
            image[width - 1 - j] = image[j];
            image[j] = temp;
        }
    }
}

// Function to change brightness/contrast of an image
void changeBrightnessContrast(unsigned char* image, int width, int height, float contrast, float brightness) {
    int i;
    for (i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char temp = image[j];
            image[j] = (unsigned char) ((temp * contrast) + (brightness * 255));
        }
    }
}

// Function to apply a grayscale filter to an image
void applyGrayscaleFilter(unsigned char* image, int width, int height) {
    int i;
    for (i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char temp = image[j];
            image[j] = (unsigned char) (0.299f * temp + 0.587f * image[j + 1] + 0.114f * image[j + 2]);
        }
    }
}

int main() {
    unsigned char* image;
    int width, height;

    // Read image from file
    printf("Enter the file name: ");
    scanf("%s", &image);
    width = 640;
    height = 480;
    image = (unsigned char*) malloc(width * height * sizeof(unsigned char));

    // Perform image processing tasks
    flipImageHorizontal(image, width, height);
    changeBrightnessContrast(image, width, height, 1.5, 0.5);
    applyGrayscaleFilter(image, width, height);

    // Save processed image to file
    printf("Enter the file name to save the processed image: ");
    scanf("%s", &image);
    FILE* fp = fopen(image, "wb");
    fwrite(image, sizeof(unsigned char), width * height, fp);
    fclose(fp);

    return 0;
}