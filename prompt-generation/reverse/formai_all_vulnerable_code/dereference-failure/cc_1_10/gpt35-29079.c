//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXELS 100000

char ascii_chars[] = {' ', '.', '\'', ':', 'o', '&', '8', '#', '@'};

int get_ascii_index(int pixel_value, int max_pixel_value, int num_chars)
{
    float pixels_per_char = (float) max_pixel_value / (float) num_chars;
    return (int) (pixel_value / pixels_per_char);
}

void convert_to_ascii(char* image_filename, int image_width, int image_height)
{
    // Open the image file for reading
    FILE *image_file = fopen(image_filename, "rb");
    if (!image_file) {
        fprintf(stderr, "Error: Couldn't open file %s\n", image_filename);
        exit(1);
    }

    // Allocate memory for pixel data
    int* pixels = (int*) malloc(sizeof(int) * image_width * image_height);
    if (!pixels) {
        fprintf(stderr, "Error: Couldn't allocate memory for pixel data\n");
        exit(1);
    }

    // Read pixel data from image file
    fread(pixels, sizeof(int), image_width * image_height, image_file);

    // Close the image file
    fclose(image_file);

    // Find the maximum pixel value
    int max_pixel_value = 0;
    for (int i = 0; i < image_width * image_height; i++) {
        if (pixels[i] > max_pixel_value) {
            max_pixel_value = pixels[i];
        }
    }

    // Set the number of ASCII characters to be used
    int num_chars = strlen(ascii_chars);

    // Generate ASCII art from the pixel data
    for (int y = 0; y < image_height; y++) {
        for (int x = 0; x < image_width; x++) {
            int pixel_value = pixels[y * image_width + x];
            int ascii_index = get_ascii_index(pixel_value, max_pixel_value, num_chars);

            // Print the ASCII character
            putchar(ascii_chars[ascii_index]);
        }

        // Move onto the next line
        putchar('\n');
    }

    // Free the allocated memory
    free(pixels);
}

int main(int argc, char* argv[])
{
    if (argc != 4) {
        fprintf(stderr, "Usage: %s IMAGE_FILE WIDTH HEIGHT\n", argv[0]);
        exit(1);
    }

    char* image_filename = argv[1];
    int image_width = atoi(argv[2]);
    int image_height = atoi(argv[3]);

    convert_to_ascii(image_filename, image_width, image_height);

    return 0;
}