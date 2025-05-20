//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 60

char asciiChars[10] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image-file>\n", argv[0]);
        return 1;
    }

    FILE *fp;
    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Unable to open file %s\n", argv[1]);
        return 1;
    }

    // Read the image header
    char magicNum[2];
    fread(magicNum, 1, 2, fp);
    int imgWidth, imgHeight, maxVal;
    fscanf(fp, "%d %d %d", &imgWidth, &imgHeight, &maxVal);

    if (magicNum[0] != 'P' || magicNum[1] != '3') {
        printf("Invalid image format. Expected P3 but got %c%c\n", magicNum[0], magicNum[1]);
        return 1;
    }

    if (maxVal != 255) {
        printf("Invalid pixel depth. Expected 255 but got %d\n", maxVal);
        return 1;
    }

    // Allocate memory for the image data
    int *pixels = malloc(sizeof(int) * imgWidth * imgHeight);
    if (pixels == NULL) {
        printf("Failed to allocate memory for image data\n");
        return 1;
    }

    // Read the pixel data
    for (int i = 0; i < imgWidth * imgHeight; i++) {
        int r, g, b;
        fscanf(fp, "%d %d %d", &r, &g, &b);
        pixels[i] = (int) round(0.299*r + 0.587*g + 0.114*b);
    }

    // Print the ASCII art
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int pixelX = (int) round((float) x / WIDTH * imgWidth);
            int pixelY = (int) round((float) y / HEIGHT * imgHeight);
            int pixel = pixels[pixelY * imgWidth + pixelX];
            int asciiIndex = (int) round((float) pixel / 25.5);
            printf("%c", asciiChars[asciiIndex]);
        }
        printf("\n");
    }

    free(pixels);
    fclose(fp);
    return 0;
}