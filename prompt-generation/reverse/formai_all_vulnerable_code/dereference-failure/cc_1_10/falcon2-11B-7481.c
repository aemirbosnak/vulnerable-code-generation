//Falcon2-11B DATASET v1.0 Category: Image to ASCII art converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert an image into ASCII art
void convertImageToAscii(const char *imagePath, char *asciiArt) {
    // Open the image file
    FILE *file = fopen(imagePath, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", imagePath);
        return;
    }

    // Get the size of the image
    fseek(file, 0L, SEEK_END);
    long size = ftell(file);
    fseek(file, 0L, SEEK_SET);

    // Allocate memory for the ASCII art
    char *ascii = (char*)malloc(size);
    if (ascii == NULL) {
        printf("Memory allocation error\n");
        return;
    }

    // Read the image data
    fread(ascii, 1, size, file);
    fclose(file);

    // Convert the image to ASCII art
    for (int i = 0; i < size; i++) {
        if (ascii[i] == '\n') {
            ascii[i] = '\0';
        }
    }

    // Print the ASCII art
    printf("%s\n", ascii);

    // Free the memory
    free(ascii);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    char *imagePath = argv[1];
    char *asciiArt = (char*)malloc(strlen(imagePath) + 1);
    if (asciiArt == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }

    strcpy(asciiArt, imagePath);
    strcat(asciiArt, ".ascii");

    convertImageToAscii(imagePath, asciiArt);

    return 0;
}