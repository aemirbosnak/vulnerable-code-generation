//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL_VALUE 255

/* Function to flip an image horizontally */
void flipHorizontally(unsigned char *image, int width, int height) {
    unsigned char temp;
    int i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            temp = image[i * width + j];
            image[i * width + j] = image[i * width + width - j - 1];
            image[i * width + width - j - 1] = temp;
        }
    }
}

/* Function to change the brightness and contrast of an image */
void adjustBrightnessAndContrast(unsigned char *image, int width, int height, float brightness, float contrast) {
    int i;

    for (i = 0; i < width * height; i++) {
        /* Adjust brightness */
        if (brightness != 0) {
            image[i] += brightness * MAX_PIXEL_VALUE;
        }

        /* Adjust contrast */
        if (contrast != 1) {
            image[i] = (((image[i] / MAX_PIXEL_VALUE) - 0.5) * contrast + 0.5) * MAX_PIXEL_VALUE;
        }
    }
}

int main() {
    int width, height, channels;
    unsigned char *image;

    /* Read image from file */
    FILE *file = fopen("image.raw", "rb");
    if (file == NULL) {
        printf("Error: could not open file.");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    width = height = 512;
    channels = 1;

    /* Allocate memory for image */
    image = (unsigned char *) malloc(width * height * channels);

    /* Read data from file */
    if (fread(image, sizeof(unsigned char), fileSize, file) != fileSize) {
        printf("Error: could not read file.");
        return 1;
    }

    /* Close file */
    fclose(file);

    /* Flip image horizontally */
    flipHorizontally(image, width, height);

    /* Adjust brightness and contrast */
    adjustBrightnessAndContrast(image, width, height, 0.5, 2);

    /* Write processed image to file */
    FILE *outputFile = fopen("processed_image.raw", "wb");
    if (outputFile == NULL) {
        printf("Error: could not create output file.");
        return 1;
    }

    fwrite(image, sizeof(unsigned char), width * height * channels, outputFile);

    /* Close output file */
    fclose(outputFile);

    /* Free dynamically allocated memory */
    free(image);

    return 0;
}