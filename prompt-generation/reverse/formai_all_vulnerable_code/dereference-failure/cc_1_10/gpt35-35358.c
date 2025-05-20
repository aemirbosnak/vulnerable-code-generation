//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function to flip the image horizontally
void flipHorizontal(unsigned char *image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            int i = y * width + x;
            int j = y * width + (width - x - 1);
            unsigned char temp = image[i];
            image[i] = image[j];
            image[j] = temp;
        }
    }
}

// function to adjust the brightness of the image
void adjustBrightness(unsigned char *image, int width, int height, float brightness) {
    for (int i = 0; i < width * height; i++) {
        float pixel = (float)image[i] * brightness;
        image[i] = (unsigned char)fmin(fmax(pixel, 0), 255);
    }
}

// function to adjust the contrast of the image
void adjustContrast(unsigned char *image, int width, int height, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < width * height; i++) {
        float pixel = factor * ((float)image[i] - 128) + 128;
        image[i] = (unsigned char)fmin(fmax(pixel, 0), 255);
    }
}

int main() {
    // read image file
    FILE *file = fopen("image.raw", "rb");
    int width = 512, height = 512;
    unsigned char *image = malloc(width * height);
    fread(image, 1, width * height, file);
    fclose(file);

    // flip image horizontally
    flipHorizontal(image, width, height);

    // adjust brightness and contrast
    float brightness = 1.2;
    adjustBrightness(image, width, height, brightness);
    float contrast = 50.0;
    adjustContrast(image, width, height, contrast);

    // save output image
    file = fopen("output.raw", "wb");
    fwrite(image, 1, width * height, file);
    fclose(file);

    // free memory
    free(image);

    return 0;
}