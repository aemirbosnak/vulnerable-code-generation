//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
Image to ASCII Art Converter
 - by (insert your name here)
*/

// Define the characters to be used for the ASCII art
char ascii_chars[] = { '@', '#', '$', '%', '?', '*', '+', ';', ':', ',', '.' };

// Function to calculate the grayscale value of a pixel
int grayscale(int r, int g, int b) {
    return round((0.299 * r) + (0.587 * g) + (0.114 * b));
}

// Function to map the grayscale value to an ASCII character
char to_ascii(int grayscale_value) {
    int ascii_range = sizeof(ascii_chars) / sizeof(char);
    int range = 256 / ascii_range;
    int index = round(grayscale_value / range);
    if (index >= ascii_range) {
        index = ascii_range - 1;
    }
    return ascii_chars[index];
}

// Function to load an image file
unsigned char* load_image(char* filename, int* width, int* height) {
    FILE* file;
    unsigned char* image_data;
    unsigned char header[54];
    
    // Open the file for reading
    file = fopen(filename, "rb");
    if (!file) {
        printf("Error: could not open image file\n");
        return NULL;
    }
    
    // Read the header information (54 bytes)
    fread(header, sizeof(unsigned char), 54, file);
    
    // Extract the width and height of the image from the header
    *width = *(int*)(header + 18);
    *height = *(int*)(header + 22);
    
    // Allocate memory for the image data
    image_data = (unsigned char*)malloc(*width * *height * 3 * sizeof(unsigned char));
    
    // Read the image data
    fread(image_data, sizeof(unsigned char), (*width) * (*height) * 3, file);
    
    // Close the file
    fclose(file);
    
    return image_data;
}

// Function to save the ASCII art to a text file
void save_ascii_art(char* filename, char* ascii_data, int width, int height) {
    FILE* file;
    
    // Open the file for writing
    file = fopen(filename, "w");
    if (!file) {
        printf("Error: could not save ASCII art\n");
        return;
    }
    
    // Write the ASCII art to the file
    int i;
    for (i = 0; i < width * height; i++) {
        fprintf(file, "%c", ascii_data[i]);
        if (i % width == width - 1) {
            fprintf(file, "\n");
        }
    }
    
    // Close the file
    fclose(file);
}

// Main function
int main(int argc, char* argv[]) {
    char* image_filename;
    char* ascii_filename;
    
    // Check that the correct number of command line arguments have been supplied
    if (argc != 3) {
        printf("Usage: %s <image_file> <ascii_file>\n", argv[0]);
        return 1;
    }
    
    // Get the image filename and ASCII filename from the command line arguments
    image_filename = argv[1];
    ascii_filename = argv[2];
    
    int width, height;
    unsigned char* image_data;
    char* ascii_data;
    int i, j;
    
    // Load the image data from the image file
    image_data = load_image(image_filename, &width, &height);
    if (!image_data) {
        return 1;
    }
    
    // Allocate memory for the ASCII art data
    ascii_data = (char*)malloc(width * height * sizeof(char));
    
    // Convert each pixel to an ASCII character
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int index = (i * width + j) * 3;
            int r = image_data[index];
            int g = image_data[index + 1];
            int b = image_data[index + 2];
            int grayscale_value = grayscale(r, g, b);
            char ascii_char = to_ascii(grayscale_value);
            ascii_data[i * width + j] = ascii_char;
        }
    }
    
    // Save the ASCII art to a text file
    save_ascii_art(ascii_filename, ascii_data, width, height);
    
    // Free the image and ASCII data
    free(image_data);
    free(ascii_data);
    
    return 0;
}