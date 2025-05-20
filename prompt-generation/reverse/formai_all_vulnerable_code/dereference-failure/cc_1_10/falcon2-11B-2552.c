//Falcon2-11B DATASET v1.0 Category: Image to ASCII art converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a function to convert a pixel value to an ASCII character
char* convertPixelToASCII(int pixelValue) {
    // Create an array of ASCII characters corresponding to the RGB values of a pixel
    static char asciiCharacters[] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
    };
    
    // Convert the pixel value to its corresponding ASCII character
    int index = pixelValue / 16;
    int remainder = pixelValue % 16;
    char* asciiChar = asciiCharacters + index;
    asciiChar = &asciiChar[remainder];
    
    // Return the ASCII character
    return asciiChar;
}

// Define a function to convert an image to ASCII art
void convertImageToASCII(FILE* imageFile, FILE* outputFile) {
    // Open the image file for reading
    FILE* image = fopen(imageFile, "r");
    if (image == NULL) {
        fprintf(stderr, "Error: Unable to open image file\n");
        return;
    }
    
    // Open the output file for writing
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Error: Unable to open output file\n");
        return;
    }
    
    // Read the image file byte by byte and convert each pixel to ASCII art
    int pixelValue;
    while (fread(&pixelValue, sizeof(int), 1, image)) {
        char* asciiChar = convertPixelToASCII(pixelValue);
        fprintf(outputFile, "%s", asciiChar);
    }
    
    // Close the files
    fclose(image);
    fclose(outputFile);
}

int main(int argc, char* argv[]) {
    // Check if the user provided the correct number of arguments
    if (argc!= 3) {
        fprintf(stderr, "Error: Incorrect number of arguments\n");
        return 1;
    }
    
    // Convert the image to ASCII art
    convertImageToASCII(argv[1], stdout);
    
    return 0;
}