//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert image to grayscale
void grayScaleConversion(unsigned char *pixels, int width, int height) {
    int grayScaleValue;
    
    for(int y=0; y<height; y++) {
        for(int x=0; x<width; x++) {
            int rgbValue = ((y * width) + x) * 3; // Calculate RGB value at (x, y) position
            
            grayScaleValue = (pixels[rgbValue] + pixels[rgbValue+1] + pixels[rgbValue+2]) / 3; // Calculate average of R, G and B values
            
            pixels[rgbValue] = grayScaleValue; // Assign gray value to R
            pixels[rgbValue+1] = grayScaleValue; // Assign gray value to G
            pixels[rgbValue+2] = grayScaleValue; // Assign gray value to B
        }
    }
}

// Function to convert grayscale image to ASCII art
void convertToASCII(unsigned char *pixels, int width, int height) {
    char ASCII_CHARS[] = "@#S%?*+;:-,. "; // List of ASCII characters in order of increasing brightness
    int charCount = strlen(ASCII_CHARS);
    int pixelBrightness;
    char ASCII_GALLERY[height][width];
    
    // Loop through each pixel in the image and assign corresponding ASCII character
    for(int y=0; y<height; y++) {
        for(int x=0; x<width; x++) {
            int pixelIndex = (y * width) + x;
            
            // Calculate brightness of the pixel (scaled to values between 0 and charCount)
            pixelBrightness = ((int)pixels[pixelIndex] * charCount) / 256;
            
            // Assign corresponding ASCII character based on pixel brightness
            ASCII_GALLERY[y][x] = ASCII_CHARS[pixelBrightness];
        }
    }
    
    // Print the ASCII art representation of the image
    for(int y=0; y<height; y++) {
        for(int x=0; x<width; x++) {
            printf("%c", ASCII_GALLERY[y][x]);
        }
        printf("\n");
    }
}

int main() {
    FILE *imageFile;
    char fileName[100];
    unsigned char *pixels;
    int width, height;
    
    printf("Enter the name of the image file: ");
    scanf("%s", fileName);
    
    // Open the image file in binary mode
    imageFile = fopen(fileName, "rb");
    
    // Check if file was opened successfully
    if(imageFile == NULL) {
        printf("Error: Unable to open image file.");
        return 1;
    }
    
    // Read the image header to get image dimensions
    fseek(imageFile, 18, SEEK_SET);
    fread(&width, 4, 1, imageFile); // Read width from bytes 19-22
    fread(&height, 4, 1, imageFile); // Read height from bytes 23-26
    
    printf("Image dimensions: %d x %d\n", width, height);
    
    // Allocate memory to store pixel data
    pixels = (unsigned char*) malloc(width * height * 3);
    
    // Read the pixel data from the file
    fseek(imageFile, 54, SEEK_SET);
    fread(pixels, 3, width * height, imageFile);
    
    // Close the file
    fclose(imageFile);
    
    // Convert the image to grayscale
    grayScaleConversion(pixels, width, height);
    
    // Convert the grayscale image to ASCII art
    convertToASCII(pixels, width, height);
    
    return 0;
}