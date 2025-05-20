//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Constants for mapping grayscale pixel values to ASCII characters
const int NUM_CHARS = 69;
const char CHAR_MAP[] = " .,'\"^`:;Il!i><~+_-?][}{1)(|/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";

// Function to convert a grayscale pixel value to an ASCII character
char pixel_to_ascii(int pixel) {
    // Map the pixel value to an index in the character map
    int char_index = (int) floor(pixel * (NUM_CHARS - 1) / 255.0);
    // Return the corresponding character
    return CHAR_MAP[char_index];
}

// Function to convert an image to ASCII art
void convert_image(char* img_path, int width, int height) {
    // Open the input image file for reading
    FILE* input_file = fopen(img_path, "rb");
    if (input_file == NULL) {
        printf("Error: could not open input image file '%s'\n", img_path);
        exit(1);
    }
  
    // Allocate memory for the pixel data
    int num_pixels = width * height;
    unsigned char* pixel_data = (unsigned char*) malloc(num_pixels);
  
    // Read the pixel data from the file
    if (fread(pixel_data, sizeof(unsigned char), num_pixels, input_file) != num_pixels) {
        printf("Error: could not read pixel data from input image file '%s'\n", img_path);
        exit(1);
    }
  
    // Close the input file
    fclose(input_file);
  
    // Create a string to hold the ASCII art
    char ascii_buffer[num_pixels * 2];
    int ascii_index = 0;
  
    // Loop through the pixels in the image and convert each one to an ASCII character
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Get the grayscale pixel value at the current position
            int pixel_index = y * width + x;
            int pixel_value = pixel_data[pixel_index];
            // Convert the pixel value to an ASCII character and add it to the ASCII buffer
            char ascii_char = pixel_to_ascii(pixel_value);
            ascii_buffer[ascii_index++] = ascii_char;
            ascii_buffer[ascii_index] = '\0'; // Terminate the string
        }
        // Add a newline character at the end of each row of ASCII art
        ascii_buffer[ascii_index++] = '\n';
        ascii_buffer[ascii_index] = '\0'; // Terminate the string
    }
  
    // Print the ASCII art to the console
    printf("%s", ascii_buffer);
  
    // Free the memory used for the pixel data
    free(pixel_data);
}

int main(int argc, char** argv) {
    // Check that the correct number of command-line arguments were provided
    if (argc != 4) {
        printf("Usage: %s [input image file] [width] [height]\n", argv[0]);
        exit(1);
    }
  
    // Get the input image file path, width, and height from the command-line arguments
    char* img_path = argv[1];
    int width = atoi(argv[2]);
    int height = atoi(argv[3]);
  
    // Call the convert_image function to generate the ASCII art
    convert_image(img_path, width, height);
  
    return 0;
}