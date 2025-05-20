//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert the pixel to ASCII character
char* pixelToASCII(int grayScaleValue)
{
    char* asciiChar;
    char asciiChars[11] = " .:-=+*#%@"; // ASCII characters arranged from the lightest to the darkest
    
    int charIndex = grayScaleValue/25; // Determine the index of the ASCII character for the grayscale value
    
    asciiChar = malloc(sizeof(char)); // Allocate memory to store the ASCII character
    *asciiChar = asciiChars[charIndex]; // Store the ASCII character at the allocated memory address
    
    return asciiChar; // Return the ASCII character
}

// Function to read the image file and convert it to ASCII art
void convertToASCII(char* filePath)
{
    // Open the file in binary read mode
    FILE* imageFile = fopen(filePath, "rb");
    
    // Check if file opened successfully
    if (imageFile == NULL) {
        printf("Error opening image file");
        return;
    }
    
    // Read the header information of the image
    char* header = malloc(54*sizeof(char));
    fread(header, 1, 54, imageFile);
    
    // Get the dimensions of the image
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    
    // Calculate the size of a single pixel in the image
    int pixelSize = *(int*)&header[28]/8;
    
    // Allocate memory to store the pixel values
    unsigned char* pixelData = malloc(pixelSize*width*height*sizeof(unsigned char));
    
    // Read the pixel data from the image
    fread(pixelData, 1, pixelSize*width*height, imageFile);
    
    // Close the image file
    fclose(imageFile);
    
    // Print the ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Get the grayscale value of the pixel
            int grayScaleValue = 0;
            for (int k = 0; k < pixelSize; k++) {
                grayScaleValue += *(pixelData + ((i*width + j)*pixelSize + k));
            }
            grayScaleValue /= pixelSize;
            
            // Convert the grayscale value to the ASCII character
            char* asciiChar = pixelToASCII(grayScaleValue);
            
            // Print the ASCII character
            printf("%s", asciiChar);
            
            // Free the memory allocated to the ASCII character
            free(asciiChar);
        }
        // Move to the next line
        printf("\n");
    }
    
    // Free the memory allocated to the pixel data and header
    free(pixelData);
    free(header);
}

int main()
{
    char* filePath = "test.jpg"; // Replace with the path to your image file
    
    convertToASCII(filePath); // Convert the image to ASCII art
    
    return 0; // Return 0 to indicate success
}