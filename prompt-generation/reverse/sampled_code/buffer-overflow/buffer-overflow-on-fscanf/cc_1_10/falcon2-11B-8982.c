//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 100

void flipImage(unsigned char *image) {
    int i;
    for (i = 0; i < MAX_LINE; i++) {
        unsigned char temp = image[i];
        image[i] = image[MAX_LINE - i - 1];
        image[MAX_LINE - i - 1] = temp;
    }
}

void changeBrightness(unsigned char *image, int factor) {
    int i;
    for (i = 0; i < MAX_LINE; i++) {
        int brightness = image[i] * factor;
        if (brightness > 255)
            brightness = 255;
        if (brightness < 0)
            brightness = 0;
        image[i] = brightness;
    }
}

void changeContrast(unsigned char *image, int factor) {
    int i;
    for (i = 0; i < MAX_LINE; i++) {
        int contrast = image[i] * factor;
        if (contrast > 255)
            contrast = 255;
        if (contrast < 0)
            contrast = 0;
        image[i] = contrast;
    }
}

int main() {
    unsigned char image[MAX_LINE][MAX_LINE];
    FILE *inputFile = fopen("input.pgm", "r");
    FILE *outputFile = fopen("output.pgm", "w");

    if (!inputFile ||!outputFile) {
        printf("Error opening files\n");
        return 1;
    }

    int width, height;
    fscanf(inputFile, "P5 %d %d %d %d\n", &width, &height, &image[0][0], &image[0][0]);
    fclose(inputFile);

    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fscanf(outputFile, "%d\n", &image[i][j]);
        }
    }
    fclose(outputFile);

    int factor = 2;
    flipImage(image);
    changeBrightness(image, factor);
    changeContrast(image, factor);

    outputFile = fopen("output.pgm", "w");
    if (!outputFile) {
        printf("Error opening output file\n");
        return 1;
    }

    fprintf(outputFile, "P5 %d %d %d %d\n", width, height, 255, 255);
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fprintf(outputFile, "%d ", image[i][j]);
        }
        fprintf(outputFile, "\n");
    }

    fclose(outputFile);

    return 0;
}