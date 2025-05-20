//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Size of the image in bytes
#define IMAGE_SIZE 1024

// Size of the watermark in bits
#define WATERMARK_SIZE 32

// Function to embed the watermark into the image
void embed_watermark(uint8_t *image, const uint8_t *watermark) {
    // Iterate over the image and the watermark
    for (int i = 0; i < IMAGE_SIZE / 8; i++) {
        // Get the current byte of the image and the watermark
        uint8_t image_byte = image[i];
        uint8_t watermark_byte = watermark[i / 8];

        // Embed the watermark into the image
        image_byte |= watermark_byte << (i % 8);

        // Update the image
        image[i] = image_byte;
    }
}

// Function to extract the watermark from the image
void extract_watermark(const uint8_t *image, uint8_t *watermark) {
    // Iterate over the image and the watermark
    for (int i = 0; i < IMAGE_SIZE / 8; i++) {
        // Get the current byte of the image and the watermark
        uint8_t image_byte = image[i];
        uint8_t watermark_byte = watermark[i / 8];

        // Extract the watermark from the image
        watermark_byte = (image_byte >> (i % 8)) & 0x01;

        // Update the watermark
        watermark[i / 8] = watermark_byte;
    }
}

int main() {
    // Create the image and the watermark
    uint8_t image[IMAGE_SIZE] = {0};
    uint8_t watermark[WATERMARK_SIZE / 8] = {0xDE, 0xAD, 0xBE, 0xEF};

    // Embed the watermark into the image
    embed_watermark(image, watermark);

    // Extract the watermark from the image
    uint8_t extracted_watermark[WATERMARK_SIZE / 8] = {0};
    extract_watermark(image, extracted_watermark);

    // Compare the original watermark with the extracted watermark
    if (memcmp(watermark, extracted_watermark, WATERMARK_SIZE / 8) == 0) {
        printf("The watermark was successfully extracted from the image.\n");
    } else {
        printf("The watermark was not successfully extracted from the image.\n");
    }

    return 0;
}