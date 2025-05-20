//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to flip an image horizontally
void flipImage(int height, int width, int* image) {
    int temp = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            temp = image[i * width + j];
            image[i * width + j] = image[i * width + width - 1 - j];
            image[i * width + width - 1 - j] = temp;
        }
    }
}

// Function to change brightness of an image
void adjustBrightness(int height, int width, int* image, int brightness) {
    int temp = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            temp = image[i * width + j];
            image[i * width + j] = (temp * brightness) / 255;
        }
    }
}

// Function to change contrast of an image
void adjustContrast(int height, int width, int* image, int contrast) {
    int temp = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            temp = image[i * width + j];
            image[i * width + j] = (temp * contrast) / 255;
        }
    }
}

int main() {
    int height = 512;
    int width = 512;
    int* image = (int*)malloc(height * width * sizeof(int));

    // Read image data from file
    FILE* fp = fopen("image.bmp", "rb");
    fread(image, height * width * sizeof(int), 1, fp);
    fclose(fp);

    // Flip image horizontally
    flipImage(height, width, image);

    // Adjust brightness of the image
    adjustBrightness(height, width, image, 1.5);

    // Adjust contrast of the image
    adjustContrast(height, width, image, 0.5);

    // Write image data to file
    fp = fopen("output.bmp", "wb");
    fwrite(image, height * width * sizeof(int), 1, fp);
    fclose(fp);

    printf("Image processing completed successfully!\n");

    free(image);

    return 0;
}