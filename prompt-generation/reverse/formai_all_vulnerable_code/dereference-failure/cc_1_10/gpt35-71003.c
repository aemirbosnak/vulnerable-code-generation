//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <pthread.h>

struct Image {
    int width;
    int height;
    uint8_t *data;
};

typedef void (*ImageModifier)(struct Image *);

void flipHorizontally(struct Image *image) {
    size_t rowLength = image->width * 3;
    uint8_t *tempRow = (uint8_t*)malloc(rowLength * sizeof(uint8_t));
    for (int y = 0; y < image->height; y++) {
        uint8_t *row = image->data + y * rowLength;
        memcpy(tempRow, row, rowLength * sizeof(uint8_t));
        for (int x = 0; x < image->width; x++) {
            row[x * 3] = tempRow[(image->width - x - 1) * 3];
            row[x * 3 + 1] = tempRow[(image->width - x - 1) * 3 + 1];
            row[x * 3 + 2] = tempRow[(image->width - x - 1) * 3 + 2];
        }
    }
    free(tempRow);
}

void adjustBrightness(struct Image *image) {
    int brightnessDelta = 100;
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            uint8_t *pixel = image->data + (y * image->width + x) * 3;
            pixel[0] = pixel[0] + brightnessDelta <= 255 ? pixel[0] + brightnessDelta : 255;
            pixel[1] = pixel[1] + brightnessDelta <= 255 ? pixel[1] + brightnessDelta : 255;
            pixel[2] = pixel[2] + brightnessDelta <= 255 ? pixel[2] + brightnessDelta : 255;
        }
    }
}

void adjustContrast(struct Image *image) {
    double contrastFactor = 1.5;
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            uint8_t *pixel = image->data + (y * image->width + x) * 3;
            pixel[0] = pixel[0] * contrastFactor <= 255 ? pixel[0] * contrastFactor : 255;
            pixel[1] = pixel[1] * contrastFactor <= 255 ? pixel[1] * contrastFactor : 255;
            pixel[2] = pixel[2] * contrastFactor <= 255 ? pixel[2] * contrastFactor : 255;
        }
    }
}

void processImage(struct Image *image, ImageModifier modifier) {
    pthread_t thread;
    pthread_create(&thread, NULL, (void *)&modifier, (void *)image);
}

int main() {
    // Your image processing code will go here
    struct Image image;
    image.width = 640;
    image.height = 480;
    image.data = (uint8_t*)malloc(image.width * image.height * 3 * sizeof(uint8_t));
    // Start by loading image data from file or somewhere else
    // ...

    // Flip image horizontally
    processImage(&image, flipHorizontally); 
    // Adjust image brightness
    processImage(&image, adjustBrightness);
    // Adjust image contrast
    processImage(&image, adjustContrast);

    // Save processed image to file or display on screen
    // ...

    free(image.data);
    return 0;
}