//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void flipImage(int rows, int cols, unsigned char *image);
void adjustBrightnessContrast(int rows, int cols, unsigned char *image, int brightness, float contrast);

int main() {
    // Load image data from binary file
    FILE *fp = fopen("image.bin", "rb");
    if (fp == NULL) {
        printf("Error opening image file");
        return -1;
    }
    int rows, cols;
    fread(&rows, sizeof(int), 1, fp);
    fread(&cols, sizeof(int), 1, fp);
    unsigned char *image = (unsigned char*)malloc(rows * cols * sizeof(unsigned char));
    fread(image, sizeof(unsigned char), rows * cols, fp);
    fclose(fp);

    // Perform image processing tasks
    flipImage(rows, cols, image);
    adjustBrightnessContrast(rows, cols, image, 50, 1.5);

    // Save processed image data to binary file
    fp = fopen("processed_image.bin", "wb");
    fwrite(&rows, sizeof(int), 1, fp);
    fwrite(&cols, sizeof(int), 1, fp);
    fwrite(image, sizeof(unsigned char), rows * cols, fp);
    fclose(fp);
    free(image);

    return 0;
}

// Function to flip image horizontally
void flipImage(int rows, int cols, unsigned char *image) {
    unsigned char *tempRow = (unsigned char*)malloc(cols * sizeof(unsigned char));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols / 2; j++) {
            // Swap pixels on opposite sides of the row
            tempRow[j] = image[i*cols + j];
            image[i*cols + j] = image[i*cols + cols - j - 1];
            image[i*cols + cols - j - 1] = tempRow[j];
        }
    }
    free(tempRow);
}

// Function to adjust brightness and contrast of image
void adjustBrightnessContrast(int rows, int cols, unsigned char *image, int brightness, float contrast) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Adjust pixel value using linear transformation equation
            image[i*cols + j] = (unsigned char)(contrast * (image[i*cols + j] - 128) + 128 + brightness);
        }
    }
}