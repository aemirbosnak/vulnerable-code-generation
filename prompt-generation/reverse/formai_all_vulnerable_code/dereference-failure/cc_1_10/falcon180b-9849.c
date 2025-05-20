//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80 // Width of ASCII art
#define HEIGHT 25 // Height of ASCII art

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    // Open input image file
    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Read input image file header
    unsigned char header[54];
    fread(header, 1, 54, fp);

    // Check if input file is a valid BMP image
    if (header[0]!= 'B' || header[1]!= 'M') {
        printf("Error: Input file is not a valid BMP image.\n");
        fclose(fp);
        return 1;
    }

    // Get image width and height from header
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Calculate number of pixels in image
    int num_pixels = width * height;

    // Allocate memory for pixel data
    unsigned char *pixels = (unsigned char *)malloc(num_pixels * 3);
    if (pixels == NULL) {
        printf("Error: Could not allocate memory for pixel data.\n");
        fclose(fp);
        return 1;
    }

    // Read pixel data from input image file
    fseek(fp, 54, SEEK_SET);
    fread(pixels, 3, num_pixels, fp);
    fclose(fp);

    // Open output ASCII art file
    FILE *out_fp = fopen(argv[2], "w");
    if (out_fp == NULL) {
        printf("Error: Could not open output file.\n");
        free(pixels);
        return 1;
    }

    // Calculate grayscale value for each pixel
    for (int i = 0; i < num_pixels; i++) {
        int grayscale = (int)round((pixels[i] + pixels[i+1] + pixels[i+2]) / 3.0);

        // Convert grayscale value to ASCII character
        char ascii_char = (char)('@' + (grayscale / 6));

        // Write ASCII character to output file
        fprintf(out_fp, "%c", ascii_char);
    }

    // Close output file
    fclose(out_fp);
    free(pixels);

    return 0;
}