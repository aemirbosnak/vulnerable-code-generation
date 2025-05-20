//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100

// Function to convert image to ASCII art
void image_to_ascii(char* image_file, char* output_file) {
    FILE *image_fp, *output_fp;
    int width, height, i, j, pixel, ascii_value;
    unsigned char *pixels;

    // Open image file
    image_fp = fopen(image_file, "rb");
    if (image_fp == NULL) {
        printf("Error opening image file.\n");
        exit(1);
    }

    // Get image dimensions
    fseek(image_fp, 18, SEEK_SET);
    fread(&width, 4, 1, image_fp);
    fread(&height, 4, 1, image_fp);

    // Allocate memory for pixels
    pixels = (unsigned char*) malloc(width * height * 3);
    if (pixels == NULL) {
        printf("Error allocating memory for pixels.\n");
        exit(1);
    }

    // Read image data
    fseek(image_fp, 54, SEEK_SET);
    fread(pixels, 3, width * height, image_fp);

    // Convert image to ASCII art
    output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            // Get pixel value
            pixel = pixels[(i * width + j) * 3];

            // Convert pixel value to ASCII value
            ascii_value = pixel / 16;
            if (ascii_value > MAX_WIDTH) {
                ascii_value = MAX_WIDTH;
            }

            fprintf(output_fp, "%c", ascii_value + 33);
        }
        fprintf(output_fp, "\n");
    }

    fclose(image_fp);
    fclose(output_fp);
    free(pixels);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_image_file> <output_ascii_art_file>\n", argv[0]);
        exit(1);
    }

    image_to_ascii(argv[1], argv[2]);

    printf("Image converted to ASCII art successfully.\n");

    return 0;
}