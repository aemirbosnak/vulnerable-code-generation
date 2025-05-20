//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define IMAGE_SIZE 256*256 // Assuming a grayscale image of this size
#define WATERMARK_SIZE 32   // Watermark size (in bits)

// Function to embed watermark into the image
void embed_watermark(uint8_t *image, const uint8_t *watermark, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        image[i] = (image[i] & 0xFE) | (watermark[i] & 0x01); // Modify LSB
    }
}

// Function to extract watermark from the image
void extract_watermark(const uint8_t *image, uint8_t *watermark, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        watermark[i] = image[i] & 0x01; // Get LSB
    }
}

// Function to save the image
void save_image(const char *filename, const uint8_t *image, size_t size) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Unable to open file %s for writing\n", filename);
        exit(EXIT_FAILURE);
    }
    fwrite(image, sizeof(uint8_t), size, file);
    fclose(file);
}

// Function to load an image
void load_image(const char *filename, uint8_t *image, size_t size) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Unable to open file %s for reading\n", filename);
        exit(EXIT_FAILURE);
    }
    fread(image, sizeof(uint8_t), size, file);
    fclose(file);
}

// Function to generate a watermark
void generate_watermark(uint8_t *watermark, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        watermark[i] = rand() % 2; // Randomly set watermark bits to 0 or 1
    }
}

int main() {
    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Allocate memory for image and watermark
    uint8_t *image = (uint8_t *)malloc(IMAGE_SIZE * sizeof(uint8_t));
    uint8_t *watermark = (uint8_t *)malloc(WATERMARK_SIZE * sizeof(uint8_t));
    uint8_t *extracted_watermark = (uint8_t *)malloc(WATERMARK_SIZE * sizeof(uint8_t));

    // Load image (dummy data for demo purposes)
    for (size_t i = 0; i < IMAGE_SIZE; ++i) {
        image[i] = rand() % 256; // Filling image with random grayscale values
    }

    // Generate watermark
    generate_watermark(watermark, WATERMARK_SIZE);
    
    // Embed watermark into the image
    embed_watermark(image, watermark, WATERMARK_SIZE);

    // Save the watermarked image
    save_image("watermarked_image.raw", image, IMAGE_SIZE);

    // Extract watermark from the image
    extract_watermark(image, extracted_watermark, WATERMARK_SIZE);

    // Display original and extracted watermark bits
    printf("Original Watermark: ");
    for (size_t i = 0; i < WATERMARK_SIZE; ++i) {
        printf("%d ", watermark[i]);
    }
    printf("\n");

    printf("Extracted Watermark: ");
    for (size_t i = 0; i < WATERMARK_SIZE; ++i) {
        printf("%d ", extracted_watermark[i]);
    }
    printf("\n");

    // Free allocated memory
    free(image);
    free(watermark);
    free(extracted_watermark);

    return 0;
}