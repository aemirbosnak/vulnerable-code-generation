//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: sophisticated
#include <stdio.h>

// Function to convert pixel values to ASCII characters
char* pixelToASCII(int pixelValue)
{
    char ASCII_CHARS[] = "$@B%8&WM#*oahkbdpqbzo0OQCJY?" \
                          "7>~:-;,.'^`'. ";
    int asciiCount = sizeof(ASCII_CHARS) - 1;
    int range = 255 / asciiCount;
    int index = (pixelValue + range/2) / range;
    return &ASCII_CHARS[index];
}

// Main function to convert image to ASCII art
int main()
{
    // Open image file
    FILE* pFile = fopen("image.bmp", "rb");
    if (pFile == NULL) {
        printf("Error: Unable to open image file!");
        return 1;
    }
    
    // Read BMP header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, pFile);
    
    // Get image dimensions
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int rowSize = (width*3 + 3) & (~3);
    
    // Allocate memory for image data
    unsigned char* image = (unsigned char*)malloc(rowSize*height);
    if (image == NULL) {
        printf("Error: Unable to allocate memory for image data!");
        return 1;
    }
    
    // Read image data
    fread(image, sizeof(unsigned char), rowSize*height, pFile);
    
    // Close image file
    fclose(pFile);
    
    // Print ASCII art
    for (int i=height-1; i>=0; i--) {
        for (int j=0; j<width; j++) {
            int index = (i*rowSize) + j*3;
            int pixelValue = (image[index] + image[index+1] + image[index+2]) / 3;
            char* ASCIIChar = pixelToASCII(pixelValue);
            printf("%s", ASCIIChar);
        }
        printf("\n");
    }
    
    // Free memory
    free(image);
    
    return 0;
}