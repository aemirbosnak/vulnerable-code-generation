//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <png.h>

#define MAX_WATERMARK_SIZE 256

void embed_watermark(const char* image_path, const char* watermark_path, const char* output_path) {
    FILE *fp = fopen(image_path, "rb");
    if (!fp) {
        perror("Failed to open image file");
        return;
    }
    
    uint8_t *image_data;
    size_t image_size;
    
    // Read the PNG image into image_data
    // Note: You would normally use a library to read PNG files; this is a simplification.
    
    fclose(fp);
    
    fp = fopen(watermark_path, "rb");
    if (!fp) {
        perror("Failed to open watermark file");
        return;
    }
    
    uint8_t watermark[MAX_WATERMARK_SIZE] = {0};
    size_t watermark_size = fread(watermark, sizeof(uint8_t), MAX_WATERMARK_SIZE, fp);
    fclose(fp);
    
    // Embed watermark into image_data using LSB method
    for (size_t i = 0; i < watermark_size; i++) {
        image_data[i] = (image_data[i] & 0xFE) | (watermark[i] & 0x01);
    }
    
    // Write the watermarked image data to output_path
    fp = fopen(output_path, "wb");
    if (!fp) {
        perror("Failed to open output file");
        return;
    }
    
    fwrite(image_data, sizeof(uint8_t), image_size, fp);
    fclose(fp);
    free(image_data);
}

void extract_watermark(const char* image_path, const char* output_watermark_path) {
    FILE *fp = fopen(image_path, "rb");
    if (!fp) {
        perror("Failed to open image file");
        return;
    }
    
    uint8_t *image_data;
    size_t image_size;
    
    // Read the PNG image into image_data
    // Again, a simplified approach; typically use proper image loading libraries.
    
    fclose(fp);
    
    uint8_t extracted_watermark[MAX_WATERMARK_SIZE] = {0};
    
    // Extract watermark using LSB method
    for (size_t i = 0; i < MAX_WATERMARK_SIZE; i++) {
        extracted_watermark[i] = (image_data[i] & 0x01);
    }
    
    // Write the extracted watermark
    fp = fopen(output_watermark_path, "wb");
    if (!fp) {
        perror("Failed to open output watermark file");
        return;
    }
    
    fwrite(extracted_watermark, sizeof(uint8_t), MAX_WATERMARK_SIZE, fp);
    fclose(fp);
    free(image_data);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <image> <watermark> <output>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    // Embed watermark
    embed_watermark(argv[1], argv[2], argv[3]);
    
    // Extract watermark for verification (optional)
    extract_watermark(argv[3], "extracted_watermark.bin");
    
    printf("Watermarking completed successfully.\n");
    
    return EXIT_SUCCESS;
}