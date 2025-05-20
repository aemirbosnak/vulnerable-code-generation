//Falcon2-11B DATASET v1.0 Category: Pixel Art Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PIXEL_SIZE 3

// Function to generate a random pixel color
void generatePixelColor(int *pixel) {
    pixel[0] = rand() % 256;
    pixel[1] = rand() % 256;
    pixel[2] = rand() % 256;
}

// Function to generate a random pixel location
void generatePixelLocation(int *x, int *y) {
    *x = rand() % 500;
    *y = rand() % 500;
}

// Function to generate a pixel art image
void generatePixelArt() {
    int pixels[PIXEL_SIZE][PIXEL_SIZE];
    int x, y, i, j;

    // Generate 100 pixels
    for (i = 0; i < PIXEL_SIZE; i++) {
        for (j = 0; j < PIXEL_SIZE; j++) {
            generatePixelLocation(&x, &y);
            pixels[i][j] = 0;
        }
    }

    // Generate pixel colors
    for (i = 0; i < PIXEL_SIZE; i++) {
        for (j = 0; j < PIXEL_SIZE; j++) {
            generatePixelColor(&pixels[i][j]);
        }
    }

    // Print the pixel art image
    printf("Pixel Art Generator\n");
    for (i = 0; i < PIXEL_SIZE; i++) {
        for (j = 0; j < PIXEL_SIZE; j++) {
            printf("(%d,%d) ", pixels[i][j] / 256, pixels[i][j] % 256);
        }
        printf("\n");
    }
}

int main() {
    generatePixelArt();
    return 0;
}