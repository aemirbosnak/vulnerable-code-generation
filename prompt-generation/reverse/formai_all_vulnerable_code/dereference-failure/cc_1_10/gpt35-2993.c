//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 512
#define HEIGHT 512

// Function to flip the image horizontally
void flipImageHorizontally(unsigned char* image) {
    unsigned char tempArray[WIDTH];
    for(int i = 0; i < HEIGHT; i++) {
        int rowOffset = i * WIDTH;
        for(int j = 0; j < WIDTH/2; j++) {
            int currentIndex = rowOffset + j;
            int oppositeIndex = rowOffset + WIDTH - 1 - j;
            // Swap pixel values
            unsigned char temp = image[currentIndex];
            image[currentIndex] = image[oppositeIndex];
            image[oppositeIndex] = temp;
        }
    }
}

// Function to adjust the brightness of the image
void adjustBrightness(unsigned char* image, int brightness) {
    for(int i = 0; i < WIDTH * HEIGHT; i++) {
        // Clamp pixel values between 0 and 255
        int val = (int) image[i] + brightness;
        if(val > 255) {
            image[i] = 255;
        } else if(val < 0) {
            image[i] = 0;
        } else {
            image[i] = val;
        }
    }
}

// Function to adjust the contrast of the image
void adjustContrast(unsigned char* image, float contrast) {
    float factor = (259.0f * (contrast + 255.0f)) / (255.0f * (259.0f - contrast));
    for(int i = 0; i < WIDTH * HEIGHT; i++) {
        // Adjust pixel values according to contrast factor
        int val = (int) ((factor * ((float) image[i] - 128.0f)) + 128.0f);
        if(val > 255) {
            image[i] = 255;
        } else if(val < 0) {
            image[i] = 0;
        } else {
            image[i] = val;
        }
    }
}

int main() {
    unsigned char* image = (unsigned char*) malloc(WIDTH * HEIGHT * sizeof(unsigned char));

    // Generate random grayscale values for the image
    for(int i = 0; i < WIDTH * HEIGHT; i++) {
        image[i] = (unsigned char) (rand() % 256);
    }

    // Flip the image horizontally
    flipImageHorizontally(image);

    // Adjust the brightness of the image
    adjustBrightness(image, 50);

    // Adjust the contrast of the image
    adjustContrast(image, 50.0f);

    // Write the processed image to a PGM file for viewing
    FILE* outFile = fopen("processed_image.pgm", "wb");
    fprintf(outFile, "P5\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(image, sizeof(unsigned char), WIDTH * HEIGHT, outFile);
    fclose(outFile);

    // Free the memory allocated for the image
    free(image);

    return 0;
}