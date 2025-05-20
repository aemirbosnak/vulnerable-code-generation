//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Pixel structure
typedef struct pixel {
    unsigned char r, g, b;
} pixel;

// Image structure
typedef struct image {
    int width, height;
    pixel *pixels;
} image;

// Load an image from a file
image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read the header
    unsigned char header[14];
    if (fread(header, 1, 14, fp) != 14) {
        fprintf(stderr, "Error: could not read header from file %s\n", filename);
        fclose(fp);
        return NULL;
    }

    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: file %s is not a valid BMP file\n", filename);
        fclose(fp);
        return NULL;
    }

    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Allocate memory for the image pixels
    pixel *pixels = malloc(width * height * sizeof(pixel));
    if (!pixels) {
        fprintf(stderr, "Error: could not allocate memory for image pixels\n");
        fclose(fp);
        return NULL;
    }

    // Read the image pixels
    if (fread(pixels, sizeof(pixel), width * height, fp) != width * height) {
        fprintf(stderr, "Error: could not read image pixels from file %s\n", filename);
        fclose(fp);
        free(pixels);
        return NULL;
    }

    // Close the file
    fclose(fp);

    // Return the image
    image *img = malloc(sizeof(image));
    if (!img) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        free(pixels);
        return NULL;
    }

    img->width = width;
    img->height = height;
    img->pixels = pixels;

    return img;
}

// Free an image
void free_image(image *img) {
    free(img->pixels);
    free(img);
}

// Convert an image to ASCII art
char *image_to_ascii(image *img) {
    // Allocate memory for the ASCII art
    char *ascii = malloc(img->width * img->height + 1);
    if (!ascii) {
        fprintf(stderr, "Error: could not allocate memory for ASCII art\n");
        return NULL;
    }

    // Convert the image to ASCII art
    for (int i = 0; i < img->width * img->height; i++) {
        // Get the pixel value
        pixel p = img->pixels[i];

        // Convert the pixel value to a character
        char c;
        if (p.r + p.g + p.b < 128) {
            c = '#';
        } else {
            c = ' ';
        }

        // Add the character to the ASCII art
        ascii[i] = c;
    }

    // Add a newline character to the end of the ASCII art
    ascii[img->width * img->height] = '\0';

    // Return the ASCII art
    return ascii;
}

// Print an image to the console
void print_image(image *img) {
    // Convert the image to ASCII art
    char *ascii = image_to_ascii(img);
    if (!ascii) {
        fprintf(stderr, "Error: could not convert image to ASCII art\n");
        return;
    }

    // Print the ASCII art to the console
    printf("%s", ascii);

    // Free the ASCII art
    free(ascii);
}

// Main function
int main(int argc, char **argv) {
    // Check if the user specified an input file
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return 1;
    }

    // Load the image from the file
    image *img = load_image(argv[1]);
    if (!img) {
        fprintf(stderr, "Error: could not load image from file %s\n", argv[1]);
        return 1;
    }

    // Print the image to the console
    print_image(img);

    // Free the image
    free_image(img);

    return 0;
}