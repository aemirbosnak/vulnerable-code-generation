//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Function to embed watermark into the image
void embed_watermark(const char *input_image, const char *output_image, const char *watermark, int position) {
    FILE *input = fopen(input_image, "rb");
    FILE *output = fopen(output_image, "wb");
    
    if (!input || !output) {
        fprintf(stderr, "Error opening files.\n");
        exit(1);
    }

    // Read the header (assuming a simple BMP format for demonstration)
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, input); // Read header
    fwrite(header, sizeof(unsigned char), 54, output); // Write header to output
    
    // Calculate the size of the image data
    uint32_t width = *(int*)&header[18];
    uint32_t height = *(int*)&header[22];
    uint32_t size = width * height * 3; // For RGB

    unsigned char *image_data = (unsigned char *)malloc(size);
    if (!image_data) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    
    fread(image_data, sizeof(unsigned char), size, input); // Read the image data

    // Embed watermark
    int wm_length = strlen(watermark);
    for (int i = 0; i < wm_length; ++i) {
        int idx = position + i; // Position to embed the watermark
        if (idx < size) {
            // Modify LSB to embed watermark
            image_data[idx] = (image_data[idx] & ~1) | ((watermark[i] & 1)); // LSB of the pixel
        }
    }

    fwrite(image_data, sizeof(unsigned char), size, output); // Write modified image data

    // Clean up
    free(image_data);
    fclose(input);
    fclose(output);
}

// Function to extract watermark from the image
void extract_watermark(const char *input_image, char *output_watermark, int length, int position) {
    FILE *input = fopen(input_image, "rb");
    
    if (!input) {
        fprintf(stderr, "Error opening file.\n");
        exit(1);
    }

    // Read the header (assuming a simple BMP format)
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, input); // Read header
    
    // Calculate the size of the image data
    uint32_t width = *(int*)&header[18];
    uint32_t height = *(int*)&header[22];
    uint32_t size = width * height * 3; // For RGB

    unsigned char *image_data = (unsigned char *)malloc(size);
    if (!image_data) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    
    fread(image_data, sizeof(unsigned char), size, input); // Read the image data

    // Extract watermark
    for (int i = 0; i < length; ++i) {
        int idx = position + i; // Position to extract the watermark
        if (idx < size) {
            output_watermark[i] = (image_data[idx] & 1) + '0'; // Extract LSB
        }
    }
    output_watermark[length] = '\0'; // Null-terminate the string

    // Clean up
    free(image_data);
    fclose(input);
}

int main() {
    const char *input_image = "input.bmp"; // Input image path
    const char *output_image = "output.bmp"; // Output image path
    const char *watermark = "101100"; // Simple binary watermark
    int watermark_length = strlen(watermark);
    int position = 54; // Start embedding after header

    // Embed watermark into the image
    embed_watermark(input_image, output_image, watermark, position);
    printf("Watermark embedded successfully.\n");

    // Prepare to extract the watermark
    char extracted_watermark[watermark_length + 1];
    extract_watermark(output_image, extracted_watermark, watermark_length, position);
    printf("Extracted watermark: %s\n", extracted_watermark);

    return 0;
}