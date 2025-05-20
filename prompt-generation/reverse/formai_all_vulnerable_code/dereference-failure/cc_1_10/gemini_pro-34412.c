//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: happy
#include <stdlib.h>
#include <stdio.h>

// Keep it simple, only embed a single bit
#define EMBEDDED_BIT 1

// Embed a single bit in the least significant bit of each pixel
void embed_watermark(unsigned char *image, int width, int height, int bit) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            image[i * width + j] &= ~1; // Clear the least significant bit
            image[i * width + j] |= bit; // Set the least significant bit to the watermark bit
        }
    }
}

// Extract the embedded watermark bit from the least significant bit of each pixel
int extract_watermark(unsigned char *image, int width, int height) {
    int watermark_bit = 0;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            watermark_bit |= (image[i * width + j] & 1); // Get the least significant bit
        }
    }
    return watermark_bit;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <image_file> <watermark_bit>\n");
        return 1;
    }

    // Read the image from a file
    FILE *image_file = fopen(argv[1], "rb");
    if (image_file == NULL) {
        printf("Error opening image file: %s\n", argv[1]);
        return 1;
    }

    // Get the image dimensions
    int width, height;
    fread(&width, sizeof(int), 1, image_file);
    fread(&height, sizeof(int), 1, image_file);

    // Allocate memory for the image data
    unsigned char *image = malloc(width * height);
    if (image == NULL) {
        printf("Error allocating memory for image data\n");
        fclose(image_file);
        return 1;
    }

    // Read the image data from the file
    fread(image, sizeof(unsigned char), width * height, image_file);
    fclose(image_file);

    // Embed the watermark bit in the image
    int watermark_bit = atoi(argv[2]);
    embed_watermark(image, width, height, watermark_bit);

    // Print a happy message
    printf("Watermarked image with bit %d!\n", watermark_bit);

    // Write the watermarked image to a file
    FILE *output_file = fopen("output.bmp", "wb");
    if (output_file == NULL) {
        printf("Error opening output file: output.bmp\n");
        free(image);
        return 1;
    }

    // Write the image dimensions to the file
    fwrite(&width, sizeof(int), 1, output_file);
    fwrite(&height, sizeof(int), 1, output_file);

    // Write the watermarked image data to the file
    fwrite(image, sizeof(unsigned char), width * height, output_file);
    fclose(output_file);

    // Free the allocated memory
    free(image);

    return 0;
}