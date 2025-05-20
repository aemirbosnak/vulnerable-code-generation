//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to flip an image
void flip(char *img, char *dest) {
    FILE *fp = fopen(img, "rb");
    FILE *fpout = fopen(dest, "wb");

    if (fp == NULL || fpout == NULL) {
        printf("Failed to open image or destination file.\n");
        return;
    }

    int rows = 0, cols = 0;
    unsigned char *image = NULL;
    int row, col, i;

    fread(&rows, sizeof(int), 1, fp);
    fread(&cols, sizeof(int), 1, fp);

    image = (unsigned char *)malloc(rows * cols * sizeof(unsigned char));

    fread(image, rows * cols * sizeof(unsigned char), 1, fp);

    fclose(fp);
    fclose(fpout);

    for (row = 0; row < rows; row++) {
        for (col = 0; col < cols; col++) {
            image[col + rows - 1 - row] = image[col + row];
        }
    }

    fwrite(image, rows * cols * sizeof(unsigned char), 1, fpout);

    free(image);

    fclose(fpout);
}

// Function to change the brightness and contrast of an image
void brightness(char *img, char *dest, float brightnessFactor) {
    FILE *fp = fopen(img, "rb");
    FILE *fpout = fopen(dest, "wb");

    if (fp == NULL || fpout == NULL) {
        printf("Failed to open image or destination file.\n");
        return;
    }

    int rows = 0, cols = 0;
    unsigned char *image = NULL;
    int row, col, i;

    fread(&rows, sizeof(int), 1, fp);
    fread(&cols, sizeof(int), 1, fp);

    image = (unsigned char *)malloc(rows * cols * sizeof(unsigned char));

    fread(image, rows * cols * sizeof(unsigned char), 1, fp);

    fclose(fp);
    fclose(fpout);

    for (row = 0; row < rows; row++) {
        for (col = 0; col < cols; col++) {
            image[col] *= brightnessFactor;
        }
    }

    fwrite(image, rows * cols * sizeof(unsigned char), 1, fpout);

    free(image);

    fclose(fpout);
}

int main() {
    // Flip an image
    flip("input.jpg", "output.jpg");

    // Change the brightness and contrast of an image
    brightness("input.jpg", "output.jpg", 0.5);

    return 0;
}