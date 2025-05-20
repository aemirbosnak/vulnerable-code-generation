//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the image
#define MAX_SIZE 1024

// Define the maximum size of the watermark
#define MAX_WATERMARK 128

// Define the number of bits to use for the watermark
#define NUM_BITS 8

// Define the location of the watermark in the image
#define WATERMARK_X 0
#define WATERMARK_Y 0

// Function to embed the watermark in the image
void embed_watermark(unsigned char *image, int width, int height, unsigned char *watermark, int watermark_width, int watermark_height) {
    // Check if the image is large enough to hold the watermark
    if (width < watermark_width || height < watermark_height) {
        printf("Error: The image is not large enough to hold the watermark.\n");
        exit(1);
    }

    // Loop through the watermark and embed each bit in the image
    for (int i = 0; i < watermark_width; i++) {
        for (int j = 0; j < watermark_height; j++) {
            // Get the bit from the watermark
            unsigned char bit = watermark[i * watermark_width + j] & 0x01;

            // Get the pixel from the image
            unsigned char pixel = image[(WATERMARK_X + i) * width + (WATERMARK_Y + j)];

            // Embed the bit in the pixel
            pixel = (pixel & 0xFE) | bit;

            // Set the pixel in the image
            image[(WATERMARK_X + i) * width + (WATERMARK_Y + j)] = pixel;
        }
    }
}

// Function to extract the watermark from the image
void extract_watermark(unsigned char *image, int width, int height, unsigned char *watermark, int watermark_width, int watermark_height) {
    // Check if the image is large enough to hold the watermark
    if (width < watermark_width || height < watermark_height) {
        printf("Error: The image is not large enough to hold the watermark.\n");
        exit(1);
    }

    // Loop through the watermark and extract each bit from the image
    for (int i = 0; i < watermark_width; i++) {
        for (int j = 0; j < watermark_height; j++) {
            // Get the pixel from the image
            unsigned char pixel = image[(WATERMARK_X + i) * width + (WATERMARK_Y + j)];

            // Extract the bit from the pixel
            unsigned char bit = pixel & 0x01;

            // Set the bit in the watermark
            watermark[i * watermark_width + j] = bit;
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided enough arguments
    if (argc != 3) {
        printf("Usage: %s <image> <watermark>\n", argv[0]);
        exit(1);
    }

    // Read the image from the file
    FILE *image_file = fopen(argv[1], "rb");
    if (image_file == NULL) {
        printf("Error: Could not open the image file.\n");
        exit(1);
    }
    unsigned char *image = malloc(MAX_SIZE * MAX_SIZE * 3);
    fread(image, MAX_SIZE * MAX_SIZE * 3, 1, image_file);
    fclose(image_file);

    // Read the watermark from the file
    FILE *watermark_file = fopen(argv[2], "rb");
    if (watermark_file == NULL) {
        printf("Error: Could not open the watermark file.\n");
        exit(1);
    }
    unsigned char *watermark = malloc(MAX_WATERMARK * MAX_WATERMARK);
    fread(watermark, MAX_WATERMARK * MAX_WATERMARK, 1, watermark_file);
    fclose(watermark_file);

    // Get the width and height of the image
    int width = 0;
    int height = 0;
    sscanf((char *)image, "P6 %d %d 255", &width, &height);

    // Get the width and height of the watermark
    int watermark_width = 0;
    int watermark_height = 0;
    sscanf((char *)watermark, "P6 %d %d 255", &watermark_width, &watermark_height);

    // Embed the watermark in the image
    embed_watermark(image, width, height, watermark, watermark_width, watermark_height);

    // Write the watermarked image to a file
    FILE *watermarked_image_file = fopen("watermarked_image.ppm", "wb");
    fprintf(watermarked_image_file, "P6 %d %d 255\n", width, height);
    fwrite(image, MAX_SIZE * MAX_SIZE * 3, 1, watermarked_image_file);
    fclose(watermarked_image_file);

    // Free the memory
    free(image);
    free(watermark);

    return 0;
}