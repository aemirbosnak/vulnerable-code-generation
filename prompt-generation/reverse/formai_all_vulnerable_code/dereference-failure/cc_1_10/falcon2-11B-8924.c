//Falcon2-11B DATASET v1.0 Category: Image to ASCII art converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define MAX_PIXELS (MAX_WIDTH * MAX_HEIGHT)

// Global variables
int width, height;
unsigned char* pixels;

// Function to convert an image to ASCII art
void convertImage(const char* filename) {
    // Read image width and height
    FILE* imgFile = fopen(filename, "rb");
    if (!imgFile) {
        printf("Error: Failed to open image file\n");
        return;
    }
    fread(&width, sizeof(int), 1, imgFile);
    fread(&height, sizeof(int), 1, imgFile);
    fclose(imgFile);

    // Allocate memory for pixel value array
    pixels = (unsigned char*)malloc(MAX_PIXELS * sizeof(unsigned char));

    // Convert image to ASCII art
    FILE* outFile = fopen("ascii_art.txt", "wb");
    if (!outFile) {
        printf("Error: Failed to open output file\n");
        return;
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int color = 0; // Convert color value to ASCII characters
            if (x < width / 2) {
                if (y < height / 2) {
                    color = (int)pixels[x * width + y] / 10;
                } else {
                    color = (int)pixels[x * width + height - y - 1] / 10;
                }
            } else {
                if (y < height / 2) {
                    color = (int)pixels[width - x - 1] * 10 + (int)pixels[width - x - 1] / 10;
                } else {
                    color = (int)pixels[width - x - 1] * 10 + (int)pixels[width - x - 1] / 10;
                }
            }
            char asciiChar = (char)color;
            fprintf(outFile, "%c", asciiChar);
        }
        fprintf(outFile, "\n");
    }
    fclose(outFile);

    // Free allocated memory
    free(pixels);
}

int main() {
    convertImage("image.jpg");
    return 0;
}