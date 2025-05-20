//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

// Define the watermark pattern
const uint64_t WATERMARK_PATTERN = 0x5555555555555555;

// Embed the watermark into the image
void embed_watermark(uint8_t *image, uint32_t width, uint32_t height) {
    // Calculate the number of bits in the watermark
    uint32_t watermark_bits = 64;

    // Calculate the number of pixels in the image
    uint32_t num_pixels = width * height;

    // Loop through the pixels in the image
    for (uint32_t i = 0; i < num_pixels; i++) {
        // Get the least significant bit of the current pixel
        uint8_t lsb = image[i] & 0x1;

        // Replace the least significant bit of the current pixel with the watermark bit
        image[i] = (image[i] & ~0x1) | ((WATERMARK_PATTERN >> watermark_bits) & 0x1);

        // Decrement the watermark bit counter
        watermark_bits--;

        // If all the watermark bits have been embedded, break out of the loop
        if (watermark_bits == 0) {
            break;
        }
    }
}

// Extract the watermark from the image
uint64_t extract_watermark(uint8_t *image, uint32_t width, uint32_t height) {
    // Calculate the number of bits in the watermark
    uint32_t watermark_bits = 64;

    // Calculate the number of pixels in the image
    uint32_t num_pixels = width * height;

    // Initialize the watermark to 0
    uint64_t watermark = 0;

    // Loop through the pixels in the image
    for (uint32_t i = 0; i < num_pixels; i++) {
        // Get the least significant bit of the current pixel
        uint8_t lsb = image[i] & 0x1;

        // Shift the watermark to the left by 1 bit
        watermark = watermark << 1;

        // Set the least significant bit of the watermark to the least significant bit of the current pixel
        watermark = watermark | lsb;

        // Decrement the watermark bit counter
        watermark_bits--;

        // If all the watermark bits have been extracted, break out of the loop
        if (watermark_bits == 0) {
            break;
        }
    }

    // Return the watermark
    return watermark;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided the correct number of arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_image> <output_image> <watermark>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the input image file
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input image file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Read the input image into memory
    uint8_t *image;
    uint32_t width, height;
    fread(&width, sizeof(uint32_t), 1, input_file);
    fread(&height, sizeof(uint32_t), 1, input_file);
    image = malloc(width * height);
    fread(image, 1, width * height, input_file);

    // Close the input image file
    fclose(input_file);

    // Embed the watermark into the image
    embed_watermark(image, width, height);

    // Open the output image file
    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output image file: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    // Write the watermarked image to the output file
    fwrite(&width, sizeof(uint32_t), 1, output_file);
    fwrite(&height, sizeof(uint32_t), 1, output_file);
    fwrite(image, 1, width * height, output_file);

    // Close the output image file
    fclose(output_file);

    // Print a message to the console indicating that the watermark has been embedded
    printf("Watermark embedded successfully.\n");

    // Extract the watermark from the image
    uint64_t watermark = extract_watermark(image, width, height);

    // Print the extracted watermark to the console
    printf("Watermark extracted successfully: 0x%016llx\n", watermark);

    // Check if the extracted watermark matches the original watermark
    if (watermark == WATERMARK_PATTERN) {
        printf("Watermark verified successfully.\n");
    } else {
        printf("Watermark verification failed.\n");
    }

    // Free the memory allocated for the image
    free(image);

    return EXIT_SUCCESS;
}