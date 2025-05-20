//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the character set to use for ASCII art
const char *CHARSET = " .:-=+*#%@";

// Define the size of the character set
const int CHARSET_SIZE = 10;

// Define the width and height of the ASCII art image
const int WIDTH = 80;
const int HEIGHT = 60;

// Function to recursively convert a pixel to ASCII character
char convert_pixel(int pixel_value) {
    // Determine the index in the character set based on the pixel value
    int index = pixel_value / (256 / CHARSET_SIZE);
    
    // Return the corresponding character from the character set
    return CHARSET[index];
}

// Function to recursively convert an image to ASCII art
void convert_image(int *image, char *ascii_art, int x, int y) {
    // Base case: if x or y are out of bounds, return
    if (x >= WIDTH || y >= HEIGHT) {
        return;
    }
    
    // Get the pixel value at the current x,y position
    int pixel_value = image[(y * WIDTH) + x];
    
    // Convert the pixel to an ASCII character
    ascii_art[(y * WIDTH) + x] = convert_pixel(pixel_value);
    
    // Recursively convert the pixel to ASCII art for neighboring pixels
    convert_image(image, ascii_art, x + 1, y);
    convert_image(image, ascii_art, x, y + 1);
    convert_image(image, ascii_art, x + 1, y + 1);
}

int main() {
    // Allocate memory for the image and ASCII art arrays
    int *image = malloc(WIDTH * HEIGHT * sizeof(int));
    char *ascii_art = malloc(WIDTH * HEIGHT * sizeof(char));
    
    // Generate random pixel values for the image array
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image[i] = rand() % 256;
    }
    
    // Convert the image to ASCII art recursively
    convert_image(image, ascii_art, 0, 0);
    
    // Print the ASCII art to the console
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", ascii_art[(i * WIDTH) + j]);
        }
        printf("\n");
    }
    
    // Free the memory allocated for the image and ASCII art arrays
    free(image);
    free(ascii_art);
    
    return 0;
}