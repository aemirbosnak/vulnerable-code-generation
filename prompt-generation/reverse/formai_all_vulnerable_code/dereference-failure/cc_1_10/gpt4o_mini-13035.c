//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the ASCII characters to use for the output
const char *ascii_chars = "@%#*+=-:. ";

void convert_image_to_ascii(const char *filename, int width, int height) {
    FILE *image = fopen(filename, "rb");
    if (!image) {
        fprintf(stderr, "Could not open image file: %s\n", filename);
        return;
    }
    
    // Allocate memory for the image data
    unsigned char *img_data = (unsigned char *)malloc(width * height * 3);
    if (!img_data) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(image);
        return;
    }

    // Read the image data
    fread(img_data, 1, width * height * 3, image);
    fclose(image);

    // Resize the image data to ASCII representation
    for (int y = 0; y < height; y += 2) {
        for (int x = 0; x < width; x += 2) {
            int r = img_data[(y * width + x) * 3 + 0];
            int g = img_data[(y * width + x) * 3 + 1];
            int b = img_data[(y * width + x) * 3 + 2];
            // Convert RGB to grayscale
            int gray = (r + g + b) / 3;

            // Mapping grayscale values to ASCII characters
            int ascii_index = gray * (strlen(ascii_chars) - 1) / 255;
            putchar(ascii_chars[ascii_index]);
        }
        putchar('\n');
    }

    // Free the allocated memory
    free(img_data);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <image_file> <width> <height>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *image_file = argv[1];
    int width = atoi(argv[2]);
    int height = atoi(argv[3]);

    convert_image_to_ascii(image_file, width, height);

    return EXIT_SUCCESS;
}