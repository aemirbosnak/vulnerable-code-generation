//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: Linus Torvalds
// Linus Torvalds-style C Image to ASCII art converter

// "If it's not broken, don't fix it!"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the ASCII character set
static const char *ascii_chars = " .:-=+*#%@";

// Convert an image to ASCII art
static void image_to_ascii(unsigned char *image, int width, int height) {
    // Allocate memory for the ASCII art
    char *ascii_art = malloc(width * height + 1);

    // Iterate over each pixel in the image
    for (int i = 0; i < width * height; i++) {
        // Get the pixel value
        unsigned char pixel_value = image[i];

        // Find the closest ASCII character
        int closest_char_index = 0;
        double closest_distance = 255;
        for (int j = 0; j < strlen(ascii_chars); j++) {
            double distance = abs(ascii_chars[j] - pixel_value);
            if (distance < closest_distance) {
                closest_char_index = j;
                closest_distance = distance;
            }
        }

        // Add the ASCII character to the ASCII art
        ascii_art[i] = ascii_chars[closest_char_index];
    }

    // Add a newline character to the end of the ASCII art
    ascii_art[width * height] = '\0';

    // Print the ASCII art
    printf("%s", ascii_art);

    // Free the memory allocated for the ASCII art
    free(ascii_art);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided an image file
    if (argc != 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    // Load the image file
    FILE *image_file = fopen(argv[1], "rb");
    if (image_file == NULL) {
        printf("Error: could not open image file %s\n", argv[1]);
        return 1;
    }

    // Get the image width and height
    int width, height;
    fscanf(image_file, "%d %d", &width, &height);

    // Allocate memory for the image data
    unsigned char *image = malloc(width * height);

    // Read the image data from the file
    fread(image, 1, width * height, image_file);

    // Close the image file
    fclose(image_file);

    // Convert the image to ASCII art
    image_to_ascii(image, width, height);

    // Free the memory allocated for the image data
    free(image);

    return 0;
}