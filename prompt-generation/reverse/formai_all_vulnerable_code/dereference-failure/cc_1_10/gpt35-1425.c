//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the ASCII characters used to represent different shades of gray
static const char *GRAYSCALE_CHARS = " .:-=+*#%@";

// Maximum width of the ASCII art
#define MAX_WIDTH 100

// Function to load the image data from a file
int load_image(const char *filename, unsigned char **data, int *width, int *height) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        printf("Error: could not open file '%s'\n", filename);
        return 0;
    }

    // Read the image header (file format: PGM binary image)
    char magic[3];
    fgets(magic, sizeof(magic), f);
    if (strcmp(magic, "P5") != 0) {
        printf("Error: invalid image format (expected PGM binary image)\n");
        fclose(f);
        return 0;
    }
    fscanf(f, "%d %d\n", width, height);
    int maxval;
    fscanf(f, "%d\n", &maxval);
    if (maxval > 255) {
        printf("Warning: image uses more than 8 bits per pixel (some information may be lost)\n");
    }

    // Allocate memory for the image data
    *data = (unsigned char *) malloc((*width) * (*height) * sizeof(unsigned char));
    if (!(*data)) {
        printf("Error: could not allocate memory for image data\n");
        fclose(f);
        return 0;
    }

    // Read the image data
    int count = fread(*data, 1, (*width) * (*height), f);
    if (count != (*width) * (*height)) {
        printf("Error: failed to read image data from file\n");
        free(*data);
        fclose(f);
        return 0;
    }

    fclose(f);
    return 1;
}

// Function to convert a grayscale value to an ASCII character
char grayscale_to_char(unsigned char value) {
    int index = ((float) value / 255.0f) * (strlen(GRAYSCALE_CHARS) - 1);
    return GRAYSCALE_CHARS[index];
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    // Load the image data
    unsigned char *data;
    int width, height;
    if (!load_image(argv[1], &data, &width, &height)) {
        return 1;
    }

    // Scale the image down to fit within the maximum width
    int scale = width / MAX_WIDTH;
    if (scale < 1) {
        scale = 1;
    }
    int scaled_width = width / scale;

    // Convert the image data to ASCII art
    char ascii[scaled_width][height];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < scaled_width; x++) {
            unsigned char val = data[y * width + x * scale];
            ascii[x][y] = grayscale_to_char(val);
        }
    }

    // Print the ASCII art to the console
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < scaled_width; x++) {
            putchar(ascii[x][y]);
        }
        putchar('\n');
    }

    // Free memory
    free(data);

    return 0;
}