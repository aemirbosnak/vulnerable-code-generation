//Falcon2-11B DATASET v1.0 Category: Pixel Art Generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

void generatePixelArt(char *filename, int width, int height, bool square) {
    // Create a black image
    int size = width * height;
    char *image = malloc(size * sizeof(char));
    for (int i = 0; i < size; i++) {
        image[i] = '0';
    }
    
    // Create a white image
    image[0] = '1';
    for (int i = 1; i < size; i++) {
        if (i % width == 0 && i % height == 0) {
            image[i] = '1';
        }
    }
    
    // Generate pixel art
    for (int i = 1; i < size; i++) {
        if (i % width == 0 && i % height == 0) {
            image[i] = '1';
        } else {
            image[i] = '0';
        }
    }
    
    // Save the image to file
    FILE *fptr = fopen(filename, "w");
    if (fptr == NULL) {
        printf("Error: unable to open file\n");
        free(image);
        return;
    }
    fwrite(image, sizeof(char), size, fptr);
    fclose(fptr);
    free(image);
}

int main() {
    char *filename = "pixelart.txt";
    int width = 10;
    int height = 10;
    bool square = true;
    generatePixelArt(filename, width, height, square);
    printf("Pixel art generated successfully!\n");
    return 0;
}