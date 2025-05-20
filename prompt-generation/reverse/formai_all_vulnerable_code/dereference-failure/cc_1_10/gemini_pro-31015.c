//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ASCII characters used for the conversion
char *chars = "  .:-=+*#%@";

// Recursively convert an image to ASCII art
void image_to_ascii(unsigned char *data, int width, int height, int stride, int depth, int x, int y, int max_width, int max_height, char **art) {
    // Check if the current pixel is within the image bounds
    if (x >= 0 && x < width && y >= 0 && y < height) {
        // Get the pixel value
        unsigned char pixel = data[y * stride + x * depth];

        // Convert the pixel value to ASCII
        int index = (int) (pixel * (strlen(chars) - 1) / 255.0);
        *art[y]++ = chars[index];
    } else {
        // Fill the empty space with a space character
        *art[y]++ = ' ';
    }

    // Recursively convert the remaining pixels
    if (x < max_width - 1) {
        image_to_ascii(data, width, height, stride, depth, x + 1, y, max_width, max_height, art);
    } else if (y < max_height - 1) {
        image_to_ascii(data, width, height, stride, depth, 0, y + 1, max_width, max_height, art);
    }
}

int main(int argc, char **argv) {
    // Check if the user provided an image file
    if (argc < 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    // Open the image file
    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        printf("Could not open the image file.\n");
        return 1;
    }

    // Read the image header
    unsigned char header[54];
    if (fread(header, 1, 54, fp) != 54) {
        printf("Could not read the image header.\n");
        return 1;
    }

    // Check if the image is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        printf("Invalid BMP file.\n");
        return 1;
    }

    // Get the image width and height
    int width = *(int *) &header[18];
    int height = *(int *) &header[22];

    // Get the image stride and depth
    int stride = *(int *) &header[38];
    int depth = *(int *) &header[28];

    // Allocate memory for the image data
    unsigned char *data = malloc(height * stride);
    if (!data) {
        printf("Could not allocate memory for the image data.\n");
        return 1;
    }

    // Read the image data
    if (fread(data, 1, height * stride, fp) != height * stride) {
        printf("Could not read the image data.\n");
        return 1;
    }

    // Close the image file
    fclose(fp);

    // Calculate the maximum width and height of the ASCII art
    int max_width = width * 2;
    int max_height = height;

    // Allocate memory for the ASCII art
    char **art = malloc(sizeof(char *) * max_height);
    for (int i = 0; i < max_height; i++) {
        art[i] = malloc(sizeof(char) * max_width);
    }

    // Convert the image to ASCII art
    image_to_ascii(data, width, height, stride, depth, 0, 0, max_width, max_height, art);

    // Print the ASCII art
    for (int i = 0; i < max_height; i++) {
        printf("%s\n", art[i]);
    }

    // Free the memory allocated for the ASCII art
    for (int i = 0; i < max_height; i++) {
        free(art[i]);
    }
    free(art);

    // Free the memory allocated for the image data
    free(data);

    return 0;
}