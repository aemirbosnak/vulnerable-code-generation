//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert an image to ASCII art
void convertToASCII(char *imagePath) {
    // open the image file
    FILE *imageFile = fopen(imagePath, "rb");
    if (imageFile == NULL) {
        printf("Error: Unable to open the image file. Please check if the file exists and has correct permissions.\n");
        return;
    }
    
    // obtain the image dimensions
    fseek(imageFile, 18, SEEK_SET);
    int width = 0, height = 0;
    fread(&width, sizeof(int), 1, imageFile);
    fread(&height, sizeof(int), 1, imageFile);
    
    // calculate the RGB values of each pixel in the image
    fseek(imageFile, 54, SEEK_SET);
    int bytesPerPixel = 3; // RGB values are 3 bytes each
    unsigned char *imageData = (unsigned char *)malloc(width * height * bytesPerPixel);
    fread(imageData, sizeof(unsigned char), width * height * bytesPerPixel, imageFile);
    
    // convert each pixel's RGB values to a corresponding ASCII character
    char asciiArt[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = i * width * bytesPerPixel + j * bytesPerPixel;
            int brightness = (int)(0.2989 * (int)imageData[index] + 0.5870 * (int)imageData[index + 1] + 0.1140 * (int)imageData[index + 2]);
            char asciiChar = ' ';
            if (brightness >= 0 && brightness <= 31) {
                asciiChar = '@';
            } else if (brightness >= 32 && brightness <= 63) {
                asciiChar = '#';
            } else if (brightness >= 64 && brightness <= 95) {
                asciiChar = '$';
            } else if (brightness >= 96 && brightness <= 127) {
                asciiChar = '*';
            } else if (brightness >= 128 && brightness <= 159) {
                asciiChar = '|';
            } else if (brightness >= 160 && brightness <= 191) {
                asciiChar = '/';
            } else if (brightness >= 192 && brightness <= 223) {
                asciiChar = '-';
            } else if (brightness >= 224 && brightness <= 255) {
                asciiChar = '.';
            }
            asciiArt[i][j] = asciiChar;
        }
    }
    
    // output the ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            putchar(asciiArt[i][j]);
        }
        putchar('\n');
    }
    
    // free the allocated memory and close the file
    free(imageData);
    fclose(imageFile);
}

// sample usage of the function
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Error: Please provide the image file path as an argument.\n");
        return 1;
    }
    char *imagePath = argv[1];
    printf("Converting image to ASCII art...\n");
    convertToASCII(imagePath);
    printf("Done.\n");
    return 0;
}