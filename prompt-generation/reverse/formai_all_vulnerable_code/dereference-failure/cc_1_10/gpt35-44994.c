//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXELS 1000000

// Function to convert a single pixel to ASCII
char pixelToChar(int pixel) {
    if (pixel > 230)
        return '.';
    else if (pixel > 200)
        return ':';
    else if (pixel > 170)
        return 'o';
    else if (pixel > 140)
        return '&';
    else if (pixel > 110)
        return '8';
    else if (pixel > 80)
        return '#';
    else if (pixel > 50)
        return 'W';
    else
        return '@';
}

// Function to convert a whole image to ASCII art
char* imageToAscii(int* pixels, int width, int height) {
    char ascii[MAX_PIXELS];
    int asciiWidth = width * 2;
    int asciiHeight = height;
    int index = 0;
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            int pixel = pixels[h * width + w];
            ascii[index++] = pixelToChar(pixel);
            ascii[index++] = pixelToChar(pixel);
        }
        ascii[index++] = '\n';
    }
    ascii[index] = '\0';
    char* result = (char*)malloc(sizeof(char) * (index + 1));
    strcpy(result, ascii);
    return result;
}

// Driver function
int main() {
    int pixels[] = {/* pixel data */};
    int width = 10;
    int height = 10;
    char* asciiArt = imageToAscii(pixels, width, height);
    printf("%s", asciiArt);
    free(asciiArt);
    return 0;
}