//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096 // Maximum file size (4 MB)

char* convertToASCII(char* imageData, size_t fileSize) {
    char* ascii = malloc(sizeof(char) * fileSize * 2); // Allocate memory for ASCII art
    int asciiIndex = 0;

    for (int i = 0; i < fileSize; i += 3) { // "i" is incremented by 3 to account for RGB values
        int r = imageData[i]; // Get red value
        int g = imageData[i + 1]; // Get green value
        int b = imageData[i + 2]; // Get blue value

        // Convert RGB values to grayscale value
        int grayValue = (int)(0.21 * r + 0.72 * g + 0.07 * b);

        // Map grayscale value to ASCII character
        char asciiChar;
        if (grayValue >= 230) {
            asciiChar = ' ';
        }
        else if (grayValue >= 200) {
            asciiChar = '.';
        }
        else if (grayValue >= 180) {
            asciiChar = '-';
        }
        else if (grayValue >= 160) {
            asciiChar = '=';
        }
        else if (grayValue >= 130) {
            asciiChar = '+';
        }
        else if (grayValue >= 100) {
            asciiChar = '*';
        }
        else if (grayValue >= 70) {
            asciiChar = '#';
        }
        else {
            asciiChar = '@';
        }

        ascii[asciiIndex++] = asciiChar;
    }

    ascii[asciiIndex] = '\0'; // Add null character at the end of the string

    return ascii;
}

int main() {
    char fileName[100];
    printf("Enter the path to the image: ");
    scanf("%s", fileName);

    FILE* imageFile = fopen(fileName, "rb"); // Open image file in binary mode
    if (imageFile == NULL) { // Check if file was opened successfully
        printf("Error opening file.\n");
        return 1;
    }

    fseek(imageFile, 0L, SEEK_END); // Go to the end of the file to get file size
    size_t fileSize = ftell(imageFile); // Get file size
    fseek(imageFile, 0L, SEEK_SET); // Go back to the beginning of the file

    if (fileSize > BUFFER_SIZE) { // Check if file exceeds buffer size
        printf("File size too large.\n");
        return 1;
    }

    char* imageData = malloc(sizeof(char) * fileSize); // Allocate memory for image data
    fread(imageData, fileSize, 1, imageFile); // Read image data into buffer
    fclose(imageFile); // Close image file

    char* ascii = convertToASCII(imageData, fileSize); // Convert image data to ASCII art
    printf("%s", ascii); // Print ASCII art

    // Free allocated memory
    free(imageData);
    free(ascii);

    return 0;
}