//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Image data structure
typedef struct {
    int width;
    int height;
    unsigned char *pixels;
} Image;

// Load an image from a file
Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    // Read the header
    unsigned char header[18];
    fread(header, 1, 18, fp);

    // Check if the file is a BMP image
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: %s is not a BMP image\n", filename);
        fclose(fp);
        return NULL;
    }

    // Read the image dimensions
    int width = *(int *)(header + 18);
    int height = *(int *)(header + 22);

    // Read the image data
    unsigned char *pixels = malloc(width * height * sizeof(unsigned char));
    fread(pixels, 1, width * height * sizeof(unsigned char), fp);

    fclose(fp);

    // Create and return the image
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = pixels;
    return image;
}

// Save an image to a file
void save_image(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    // Write the header
    unsigned char header[18];
    header[0] = 'B';
    header[1] = 'M';
    *(int *)(header + 2) = 54 + image->width * image->height * sizeof(unsigned char);
    *(int *)(header + 10) = 54;
    *(int *)(header + 14) = image->width;
    *(int *)(header + 18) = image->height;
    *(int *)(header + 28) = 24;
    fwrite(header, 1, 18, fp);

    // Write the image data
    fwrite(image->pixels, 1, image->width * image->height * sizeof(unsigned char), fp);

    fclose(fp);
}

// Invert the colors of an image
void invert_image(Image *image) {
    int i;
    for (i = 0; i < image->width * image->height; i++) {
        image->pixels[i] = 255 - image->pixels[i];
    }
}

// Main function
int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    // Load the input image
    Image *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Invert the colors of the image
    invert_image(image);

    // Save the output image
    save_image(image, argv[2]);

    // Free the image data
    free(image->pixels);
    free(image);

    return 0;
}