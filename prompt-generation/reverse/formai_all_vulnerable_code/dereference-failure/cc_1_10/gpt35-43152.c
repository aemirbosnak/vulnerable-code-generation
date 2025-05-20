//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

// Define ASCII character set for shading purposes
const char char_set[] = {' ', '.', ':', 'o', '&', '8', '#', '@'};

// Function to determine the shading of each pixel
int get_intensity(int r, int g, int b) {
    // Convert RGB values to grayscale intensity
    int intensity = 0.21*r + 0.72*g + 0.07*b;
    
    // Determine the appropriate ASCII character based on intensity
    int char_index = (intensity / 32);
    return char_set[char_index];
}

// Main function to read image data and convert to ASCII art
int main(int argc, char *argv[]) {
    // Read image file path from command line argument
    char *file_path = argv[1];
    FILE *fptr = fopen(file_path, "rb");
    
    // Check if file was successfully opened
    if(!fptr) {
        printf("Error: Unable to open file\n");
        return -1;
    }
    
    // Read image header information
    char magic_num[3];
    int width, height;
    fscanf(fptr, "%s\n%d %d\n255\n", magic_num, &width, &height);
    
    // Print ASCII art header
    printf("ASCII art created from image file '%s'\n", file_path);
    printf("Width: %d\nHeight: %d\n\n", width, height);
    
    // Allocate memory for array of RGB pixel values
    int *pixels = malloc(width * height * sizeof(int));
    
    // Read pixel values from image file
    fread(pixels, sizeof(int), width*height, fptr);
    fclose(fptr);
    
    // Iterate over each pixel and print corresponding ASCII character
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            // Get RGB values for current pixel
            int r = (pixels[y*width + x] >> 16) & 0xFF;
            int g = (pixels[y*width + x] >> 8) & 0xFF;
            int b = pixels[y*width + x] & 0xFF;
            
            // Determine ASCII character for shading
            int intensity = get_intensity(r, g, b);
            printf("%c", intensity);
        }
        printf("\n");
    }
    
    // Free allocated memory
    free(pixels);
    
    return 0;
}