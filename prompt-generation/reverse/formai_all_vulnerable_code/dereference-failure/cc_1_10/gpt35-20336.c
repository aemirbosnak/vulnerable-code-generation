//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: invasive
#include <stdio.h>

// Function to convert image to ascii art
void imageToAscii(FILE *imgPtr, FILE *asciiPtr) {
    int x, y;
    char ASCII_CHARS[] = {'@', '#', 'S', '%', '?', '*', '+', ':', ',', '.', ' '};
    int NUM_CHARS = sizeof(ASCII_CHARS) / sizeof(char);
    
    // Read image file header
    char header[54];
    fread(header, sizeof(char), 54, imgPtr);
    
    // Get image properties
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int pixelSize = *(int*)&header[28] / 8;
    
    // Allocate memory for pixel data
    unsigned char* imageData = (unsigned char*) malloc(width * height * pixelSize);
    
    // Read pixel data from image file
    fread(imageData, sizeof(unsigned char), width * height * pixelSize, imgPtr);
    
    // Loop through pixel data and convert to ascii art
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int index = (y * width + x) * pixelSize;
            unsigned char r = imageData[index];
            unsigned char g = imageData[index + 1];
            unsigned char b = imageData[index + 2];
            
            // Convert RGB to grayscale
            float gray = 0.2989 * r + 0.5870 * g + 0.1140 * b;
            
            // Choose appropriate ASCII character based on grayscale value
            int charIndex = (int) ((gray / 255) * (NUM_CHARS - 1));
            fputc(ASCII_CHARS[charIndex], asciiPtr);
        }
        fputc('\n', asciiPtr);
    }
    
    // Free memory and close file pointers
    free(imageData);
    fclose(imgPtr);
    fclose(asciiPtr);
}

int main() {
    // Open image and ascii output files
    FILE *imgPtr, *asciiPtr;
    imgPtr = fopen("image.bmp", "rb");
    asciiPtr = fopen("ascii.txt", "w");
    
    // Call imageToAscii function
    imageToAscii(imgPtr, asciiPtr);
    
    printf("Image converted to ASCII art and saved to ascii.txt\n");
    
    return 0;
}