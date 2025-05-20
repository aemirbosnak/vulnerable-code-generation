//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to flip an image horizontally
void flip(unsigned char *img, int width, int height) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int temp = img[i * width + j];
            img[i * width + j] = img[width - i - 1 * width + j];
            img[width - i - 1 * width + j] = temp;
        }
    }
}

// Function to change brightness of an image
void change_brightness(unsigned char *img, int width, int height, float factor) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            img[i * width + j] = round(img[i * width + j] * factor);
        }
    }
}

// Function to adjust contrast of an image
void change_contrast(unsigned char *img, int width, int height, float factor) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int contrast_factor = (img[i * width + j] * factor);
            int contrast_max = pow(contrast_factor, 0.3333);
            int contrast_min = pow(contrast_factor, 1.3333);
            int contrast_range = contrast_max - contrast_min;
            int contrast_level = round(contrast_range * (img[i * width + j] - contrast_min) / (contrast_max - contrast_min));
            img[i * width + j] = round(img[i * width + j] * factor + contrast_level * contrast_factor);
        }
    }
}

int main() {
    // Load an image
    FILE *imgFile = fopen("image.bmp", "rb");
    fseek(imgFile, 0, SEEK_END);
    int size = ftell(imgFile);
    fseek(imgFile, 0, SEEK_SET);
    unsigned char *img = (unsigned char *) malloc(size);
    fread(img, 1, size, imgFile);
    fclose(imgFile);

    // Flip the image
    flip(img, 640, 480);

    // Change brightness
    float factor = 1.5;
    change_brightness(img, 640, 480, factor);

    // Adjust contrast
    factor = 1.2;
    change_contrast(img, 640, 480, factor);

    // Save the modified image
    FILE *outFile = fopen("modified_image.bmp", "wb");
    fwrite(img, 1, size, outFile);
    fclose(outFile);

    free(img);
    return 0;
}