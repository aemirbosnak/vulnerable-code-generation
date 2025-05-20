//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool validFileExtension(char *fileName, char *extension) {
    // Get file extension from fileName string
    char *fileExtension = strrchr(fileName, '.');
    
    // Compare fileExtension to extension parameter
    if (fileExtension == NULL || strcmp(fileExtension, extension) != 0) {
        return false;
    }
    
    return true;
}

void convertImageToAscii(char *fileName) {
    // Open image file
    FILE *imageFile = fopen(fileName, "rb");
    if (imageFile == NULL) {
        printf("Error: Could not open image file '%s'.\n", fileName);
        return;
    }
    
    // Get image dimensions
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, imageFile);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    
    // Allocate memory for pixel data
    unsigned char *pixels = (unsigned char*)malloc(width * height * 3 * sizeof(unsigned char));
    
    // Read pixel data from image file
    fread(pixels, sizeof(unsigned char), width * height * 3, imageFile);
    fclose(imageFile);
    
    // Iterate through pixel data and convert to ASCII art
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Get RGB values for current pixel
            int red = pixels[(y * width + x) * 3];
            int green = pixels[(y * width + x) * 3 + 1];
            int blue = pixels[(y * width + x) * 3 + 2];
            
            // Convert RGB values to ASCII character
            if ((red + green + blue) / 3 < 50) {
                printf("#");
            } else if ((red + green + blue) / 3 < 100) {
                printf("X");
            } else if ((red + green + blue) / 3 < 150) {
                printf("=");
            } else if ((red + green + blue) / 3 < 200) {
                printf("+");
            } else if ((red + green + blue) / 3 < 250) {
                printf("-");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    
    // Free allocated memory
    free(pixels);
}

int main(int argc, char *argv[]) {
    // Check if fileName argument was passed
    if (argc != 2) {
        printf("Error: Invalid number of arguments.\n");
        return 1;
    }
    
    // Check if file is a BMP image
    if (!validFileExtension(argv[1], ".bmp")) {
        printf("Error: Invalid file type. Must be a BMP image.\n");
        return 1;
    }
    
    // Convert image to ASCII art
    convertImageToAscii(argv[1]);
    
    return 0;
}