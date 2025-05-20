//MISTRAL-7B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXEL_VALUE 255

void readPGM(FILE *fp, int **image, int *width, int *height) {
    char magicNumber[3];
    fgets(magicNumber, 3, fp);
    if (strncmp(magicNumber, "P5\n", 3) != 0) {
        fprintf(stderr, "Invalid PGM file.\n");
        exit(EXIT_FAILURE);
    }

    int pixels;
    fscanf(fp, "%d %d\n", width, height);
    pixels = *width * *height;

    *image = (int *)malloc(pixels * sizeof(int));

    for (int i = 0; i < pixels; i++) {
        fscanf(fp, "%d\n", &(*image)[i]);
    }
}

void writePGM(FILE *fp, int *image, int width, int height) {
    fprintf(fp, "P5\n%d %d\n255\n", width, height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(fp, "%d ", image[i * width + j]);
        }
        fprintf(fp, "\n");
    }
}

void flipImageHorizontally(int *image, int width, int height) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            int temp = image[i * width + j];
            image[i * width + j] = image[(height - i - 1) * width + j];
            image[(height - i - 1) * width + j] = temp;
        }
    }
}

int main() {
    FILE *fp;
    int width, height;
    int *image;

    fp = fopen("input.pgm", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open input file.\n");
        return EXIT_FAILURE;
    }

    readPGM(fp, &image, &width, &height);
    fclose(fp);

    // Flip horizontally
    flipImageHorizontally(image, width, height);

    // Increase brightness
    for (int i = 0; i < height * width; i++) {
        image[i] *= 1.5;
        if (image[i] > MAX_PIXEL_VALUE) {
            image[i] = MAX_PIXEL_VALUE;
        }
    }

    // Decrease contrast
    for (int i = 0; i < height * width; i++) {
        image[i] = image[i] * 0.7;
    }

    fp = fopen("output.pgm", "w");
    writePGM(fp, image, width, height);
    fclose(fp);

    free(image);

    return EXIT_SUCCESS;
}