//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to embed watermark into image
void embedWatermark(unsigned char *image, int imageSize, unsigned char *watermark, int watermarkSize) {
    // Initialize the bit counter
    int bitCounter = 0;

    // Loop through the image data
    for (int i = 0; i < imageSize; i++) {
        // Check if the current bit of the watermark has been processed
        if (bitCounter < watermarkSize) {
            // Get the current bit of the watermark
            unsigned char bit = (watermark[bitCounter / 8] >> (7 - bitCounter % 8)) & 1;

            // Embed the bit into the least significant bit of the current byte of the image
            image[i] = (image[i] & 0xFE) | bit;

            // Increment the bit counter
            bitCounter++;
        }
    }
}

// Function to extract watermark from image
void extractWatermark(unsigned char *image, int imageSize, unsigned char *watermark, int watermarkSize) {
    // Initialize the bit counter
    int bitCounter = 0;

    // Loop through the image data
    for (int i = 0; i < imageSize; i++) {
        // Check if the current bit of the watermark has been processed
        if (bitCounter < watermarkSize) {
            // Get the least significant bit of the current byte of the image
            unsigned char bit = image[i] & 1;

            // Store the bit in the watermark
            watermark[bitCounter / 8] |= (bit << (7 - bitCounter % 8));

            // Increment the bit counter
            bitCounter++;
        }
    }
}

// Main function
int main() {
    // Read the image data from a file
    FILE *image_file = fopen("image.bmp", "rb");
    if (image_file == NULL) {
        printf("Error opening image file.\n");
        return 1;
    }

    // Get the size of the image file
    fseek(image_file, 0, SEEK_END);
    int imageSize = ftell(image_file);
    rewind(image_file);

    // Read the image data into a buffer
    unsigned char *image = malloc(imageSize);
    if (image == NULL) {
        printf("Error allocating memory for image.\n");
        return 1;
    }
    fread(image, 1, imageSize, image_file);
    fclose(image_file);

    // Read the watermark data from a file
    FILE *watermark_file = fopen("watermark.txt", "rb");
    if (watermark_file == NULL) {
        printf("Error opening watermark file.\n");
        return 1;
    }

    // Get the size of the watermark file
    fseek(watermark_file, 0, SEEK_END);
    int watermarkSize = ftell(watermark_file);
    rewind(watermark_file);

    // Read the watermark data into a buffer
    unsigned char *watermark = malloc(watermarkSize);
    if (watermark == NULL) {
        printf("Error allocating memory for watermark.\n");
        return 1;
    }
    fread(watermark, 1, watermarkSize, watermark_file);
    fclose(watermark_file);

    // Embed the watermark into the image
    embedWatermark(image, imageSize, watermark, watermarkSize);

    // Write the watermarked image to a file
    FILE *watermarked_image_file = fopen("watermarked_image.bmp", "wb");
    if (watermarked_image_file == NULL) {
        printf("Error opening watermarked image file.\n");
        return 1;
    }
    fwrite(image, 1, imageSize, watermarked_image_file);
    fclose(watermarked_image_file);

    // Extract the watermark from the image
    unsigned char *extractedWatermark = malloc(watermarkSize);
    extractWatermark(image, imageSize, extractedWatermark, watermarkSize);

    // Compare the extracted watermark with the original watermark
    if (memcmp(watermark, extractedWatermark, watermarkSize) == 0) {
        printf("Watermark successfully extracted.\n");
    } else {
        printf("Watermark extraction failed.\n");
    }

    // Free the allocated memory
    free(image);
    free(watermark);
    free(extractedWatermark);

    return 0;
}