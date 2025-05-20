//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Function to flip the image horizontally
void flipHorizontally(int width, int height, unsigned char *image) {
    int row, col;
    unsigned char temp;

    for (row = 0; row < height; row++) {
        for (col = 0; col < width/2; col++) {
            temp = image[row*width + col];
            image[row*width + col] = image[row*width + (width-col-1)];
            image[row*width + (width-col-1)] = temp;
        }
    }
}

// Function to adjust the brightness of the image
void adjustBrightness(int width, int height, unsigned char *image, int brightness) {
    int i;

    for (i = 0; i < width*height; i++) {
        if (image[i] + brightness > 255) {
            image[i] = 255;
        } else if (image[i] + brightness < 0) {
            image[i] = 0;
        } else {
            image[i] += brightness;
        }
    }
}

// Function to adjust the contrast of the image
void adjustContrast(int width, int height, unsigned char *image, float contrast) {
    int i;
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));

    for (i = 0; i < width*height; i++) {
        image[i] = (unsigned char) (factor * (image[i] - 128) + 128);
    }
}

int main() {
    FILE *fp;
    unsigned char *image;
    char fname[] = "image.raw";
    int width = 512;
    int height = 512;

    // Allocate memory for the image
    image = (unsigned char *) malloc(width * height);

    // Read the raw image file
    if (!(fp = fopen(fname, "rb"))) {
        printf("Cannot open file: %s\n", fname);
        exit(1);
    }
    fread(image, sizeof(unsigned char), width*height, fp);
    fclose(fp);

    // Flip the image horizontally
    flipHorizontally(width, height, image);

    // Adjust the brightness by increasing it by 50
    adjustBrightness(width, height, image, 50);

    // Adjust the contrast by increasing it by 50%
    adjustContrast(width, height, image, 1.5);

    // Write the modified image to a new raw file
    char newfname[] = "modified_image.raw";
    if (!(fp = fopen(newfname, "wb"))) {
        printf("Cannot write file: %s\n", newfname);
        exit(1);
    }
    fwrite(image, sizeof(unsigned char), width*height, fp);
    fclose(fp);

    // Free allocated memory
    free(image);

    return 0;
}