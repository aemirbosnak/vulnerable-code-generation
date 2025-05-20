//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Image manipulation functions
void flipImage(unsigned char *imageData, int width, int height) {
    unsigned char *tBuffer = (unsigned char*)malloc(width * height * 3);
    memcpy(tBuffer, imageData, width * height * 3);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            tBuffer[3 * (i * width + j)] = imageData[3 * ((height - i - 1) * width + j)];
            tBuffer[3 * (i * width + j) + 1] = imageData[3 * ((height - i - 1) * width + j) + 1];
            tBuffer[3 * (i * width + j) + 2] = imageData[3 * ((height - i - 1) * width + j) + 2];
        }
    }

    memcpy(imageData, tBuffer, width * height * 3);
    free(tBuffer);
}

void changeBrightness(unsigned char *imageData, int width, int height, float bias) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            imageData[3 * (i * width + j)] = (unsigned char) fmin(255, fmax(0, bias + imageData[3 * (i * width + j)]));
            imageData[3 * (i * width + j) + 1] = (unsigned char) fmin(255, fmax(0, bias + imageData[3 * (i * width + j) + 1]));
            imageData[3 * (i * width + j) + 2] = (unsigned char) fmin(255, fmax(0, bias + imageData[3 * (i * width + j) + 2]));
        }
    }
}

void changeContrast(unsigned char *imageData, int width, int height, float contrast) {
    float factor = (259.0f * (contrast + 255.0f)) / (255.0f * (259.0f - contrast));

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            imageData[3 * (i * width + j)] = (unsigned char) fmin(255, fmax(0, factor * (imageData[3 * (i * width + j)] - 128.0f) + 128.0f));
            imageData[3 * (i * width + j) + 1] = (unsigned char) fmin(255, fmax(0, factor * (imageData[3 * (i * width + j) + 1] - 128.0f) + 128.0f));
            imageData[3 * (i * width + j) + 2] = (unsigned char) fmin(255, fmax(0, factor * (imageData[3 * (i * width + j) + 2] - 128.0f) + 128.0f));
        }
    }
}

// Main function
int main() {
    // Load image data
    FILE *file = fopen("image.raw", "rb");
    unsigned char *imageData = (unsigned char*)malloc(256 * 256 * 3);
    fread(imageData, 1, 256 * 256 * 3, file);
    fclose(file);

    // Flip image horizontally
    flipImage(imageData, 256, 256);

    // Increase brightness by 50 units
    changeBrightness(imageData, 256, 256, 50);

    // Decrease contrast by 25%
    changeContrast(imageData, 256, 256, -25.0f);

    // Save image data
    file = fopen("altered_image.raw", "wb");
    fwrite(imageData, 1, 256 * 256 * 3, file);
    fclose(file);

    // Free memory
    free(imageData);

    return 0;
}