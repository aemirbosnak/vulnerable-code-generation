//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to load an image from a file
void loadImage(const char* filename, unsigned char* image, int width, int height) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    fread(image, sizeof(unsigned char), width * height, file);
    fclose(file);
}

// Function to flip the image vertically
void flipImage(unsigned char* image, int width, int height) {
    for (int y = 0; y < height / 2; y++) {
        for (int x = 0; x < width; x++) {
            unsigned char temp = image[y * width + x];
            image[y * width + x] = image[height - (y * width + x) - 1];
            image[height - (y * width + x) - 1] = temp;
        }
    }
}

// Function to change the brightness of the image
void changeBrightness(unsigned char* image, int width, int height, int brightness) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            unsigned char value = image[y * width + x];
            value += brightness;
            if (value > 255) {
                value = 255;
            }
            image[y * width + x] = value;
        }
    }
}

// Function to change the contrast of the image
void changeContrast(unsigned char* image, int width, int height, int contrast) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            unsigned char value = image[y * width + x];
            if (value > 128) {
                value -= contrast;
                if (value < 0) {
                    value = 0;
                }
            } else {
                value += contrast;
                if (value > 255) {
                    value = 255;
                }
            }
            image[y * width + x] = value;
        }
    }
}

int main() {
    const char* filename = "image.png";
    unsigned char image[1000][1000];
    int width, height;

    // Load the image
    loadImage(filename, image, width, height);
    printf("Image loaded successfully\n");

    // Flip the image
    flipImage(image, width, height);
    printf("Image flipped vertically\n");

    // Change the brightness of the image
    int brightness = 50;
    changeBrightness(image, width, height, brightness);
    printf("Brightness changed by %d\n", brightness);

    // Change the contrast of the image
    int contrast = 50;
    changeContrast(image, width, height, contrast);
    printf("Contrast changed by %d\n", contrast);

    // Save the modified image
    FILE* file = fopen("output.png", "wb");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fwrite(image, sizeof(unsigned char), width * height, file);
    fclose(file);

    return 0;
}