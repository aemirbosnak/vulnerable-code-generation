//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define watermark data
#define WATERMARK_DATA "Ye Olde Watermark"
#define WATERMARK_LENGTH (strlen(WATERMARK_DATA))

// Function to embed watermark into image
void embed_watermark(unsigned char* image_data, int image_size, unsigned char* watermark_data, int watermark_size) {
    // Calculate number of bytes to shift for each pixel
    int shift_amount = (image_size - watermark_size) / 3;
    
    // Embed watermark into image
    for (int i = 0; i < image_size; i += 3) {
        int pixel_value = *(unsigned char*)&image_data[i];
        int watermark_index = i % watermark_size;
        int watermark_bit = (watermark_data[watermark_index] >> 7) & 1;
        pixel_value ^= watermark_bit;
        *(unsigned char*)&image_data[i] = pixel_value;
    }
}

// Function to extract watermark from image
int extract_watermark(unsigned char* image_data, int image_size, unsigned char* watermark_data) {
    // Calculate number of bytes to shift for each pixel
    int shift_amount = (image_size - WATERMARK_LENGTH) / 3;
    
    // Extract watermark from image
    int watermark_index = 0;
    for (int i = 0; i < image_size; i += 3) {
        int pixel_value = *(unsigned char*)&image_data[i];
        int bit_value = pixel_value & 1;
        watermark_data[watermark_index] |= (bit_value << 7);
        watermark_index++;
    }
    
    return 0;
}

// Main function
int main() {
    // Allocate memory for image and watermark
    unsigned char* image_data = (unsigned char*)malloc(100 * 100 * 3);
    unsigned char* watermark_data = (unsigned char*)malloc(WATERMARK_LENGTH);
    
    // Initialize image with random data
    for (int i = 0; i < 100 * 100 * 3; i++) {
        *(unsigned char*)&image_data[i] = rand() % 256;
    }
    
    // Embed watermark into image
    embed_watermark(image_data, 100 * 100 * 3, watermark_data, WATERMARK_LENGTH);
    
    // Save image to file
    FILE* fp = fopen("image.bmp", "wb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    fwrite(image_data, 100 * 100 * 3, 1, fp);
    fclose(fp);
    
    // Extract watermark from image
    unsigned char extracted_watermark[WATERMARK_LENGTH];
    extract_watermark(image_data, 100 * 100 * 3, extracted_watermark);
    
    // Print extracted watermark
    printf("Extracted watermark: %s\n", extracted_watermark);
    
    free(image_data);
    free(watermark_data);
    
    return 0;
}