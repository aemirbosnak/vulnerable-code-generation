//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_PIXEL_VALUE 255

void flipImage(unsigned char* image, int width, int height) {
    unsigned char temp;
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            temp = image[i * width + j];
            image[i * width + j] = image[(height - 1 - i) * width + j];
            image[(height - 1 - i) * width + j] = temp;
        }
    }
}

void adjustBrightnessContrast(unsigned char* image, int width, int height, int brightness, int contrast) {
    double contrastFactor = (double)(100 + contrast) / 100;
    double brightnessFactor = (double)brightness / MAX_PIXEL_VALUE;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixelValue = image[i * width + j];
            pixelValue = (int)((contrastFactor * pixelValue) - contrast);
            pixelValue = (int)(brightnessFactor * pixelValue + 0.5);

            if (pixelValue < 0) {
                pixelValue = 0;
            }
            else if (pixelValue > MAX_PIXEL_VALUE) {
                pixelValue = MAX_PIXEL_VALUE;
            }

            image[i * width + j] = (unsigned char)pixelValue;
        }
    }
}

int main() {
    FILE* inputImageFile = fopen("input_image.raw", "rb");
    if (inputImageFile == NULL) {
        printf("Failed to open input image file\n");
        return 1;
    }

    FILE* outputImageFile = fopen("output_image.raw", "wb");
    if (outputImageFile == NULL) {
        printf("Failed to open output image file\n");
        return 1;
    }

    unsigned char image[WIDTH * HEIGHT];
    fread(image, sizeof(unsigned char), WIDTH * HEIGHT, inputImageFile);

    flipImage(image, WIDTH, HEIGHT);
    adjustBrightnessContrast(image, WIDTH, HEIGHT, 100, 50);

    fwrite(image, sizeof(unsigned char), WIDTH * HEIGHT, outputImageFile);

    fclose(inputImageFile);
    fclose(outputImageFile);
    return 0;
}