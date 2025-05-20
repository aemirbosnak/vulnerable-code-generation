//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define the ASCII characters that will be used for the art
char *ascii_chars[] = {
    " ", ".", ":", "-", "=", "+", "*", "#", "%", "@"
};

// Define the size of the ascii_chars array
int ascii_chars_size = sizeof(ascii_chars) / sizeof(char *);

// Define the function that will convert the image to ASCII art
void image_to_ascii(char *filename, int width, int height) {
    // Open the file
    FILE *fp = fopen(filename, "rb");

    // Allocate memory for the image data
    unsigned char *image_data = (unsigned char *) malloc(width * height);

    // Read the image data from the file
    fread(image_data, 1, width * height, fp);

    // Close the file
    fclose(fp);

    // Print the ASCII art to the console
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Calculate the index of the current pixel in the image data
            int pixel_index = y * width + x;

            // Calculate the value of the current pixel
            unsigned char pixel_value = image_data[pixel_index];

            // Calculate the index of the ASCII character to use for the pixel
            int ascii_char_index = (pixel_value * ascii_chars_size) / 256;

            // Print the ASCII character to the console
            printf("%s", ascii_chars[ascii_char_index]);
        }

        // Print a newline character after each row of ASCII art
        printf("\n");
    }

    // Free the memory allocated for the image data
    free(image_data);
}

// The main function
int main() {
    // Define the filename, width, and height of the image
    char *filename = "example-image.bin";
    int width = 64;
    int height = 64;

    // Convert the image to ASCII art and print it to the console
    image_to_ascii(filename, width, height);

    // Return 0 to indicate success
    return 0;
}