//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an image
unsigned char* read_image(const char* filename, int* width, int* height) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return NULL;
    }
    
    fscanf(file, "P5\n%d %d\n255\n", width, height);
    unsigned char* image = (unsigned char*)malloc((*width) * (*height));
    fread(image, sizeof(unsigned char), (*width) * (*height), file);
    fclose(file);
    
    return image;
}

// Function to write an image
void write_image(const char* filename, unsigned char* image, int width, int height) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return;
    }
    
    fprintf(file, "P5\n%d %d\n255\n", width, height);
    fwrite(image, sizeof(unsigned char), width * height, file);
    fclose(file);
}

// Function to embed watermark
void embed_watermark(unsigned char* image, const char* watermark, int width, int height) {
    int watermark_length = strlen(watermark);
    int pixel_count = width * height;

    for (int i = 0; i < watermark_length && i < pixel_count; i++) {
        unsigned char pixel_value = image[i];
        // Embed LSB of watermark into the image pixel
        unsigned char watermark_bit = (watermark[i] & 1);
        image[i] = (pixel_value & ~1) | watermark_bit;  // replace LSB with watermark bit
    }
}

// Function to extract watermark
void extract_watermark(unsigned char* image, char* watermark, int length, int width, int height) {
    int pixel_count = width * height;

    for (int i = 0; i < length && i < pixel_count; i++) {
        unsigned char pixel_value = image[i];
        unsigned char watermark_bit = pixel_value & 1;  // get LSB
        watermark[i] = (watermark_bit ? '1' : '0');     // '1' for LSB=1, '0' for LSB=0
    }
    watermark[length] = '\0'; // Null-terminate the watermark string
}

int main() {
    int width, height;
    const char* input_filename = "input_image.pgm";
    const char* output_filename = "watermarked_image.pgm";
    const char* watermark = "Watermark"; // Watermark to be embedded
    int watermark_length = strlen(watermark);
    
    // Step 1: Read the input image
    unsigned char* image = read_image(input_filename, &width, &height);
    if (!image) {
        return 1;
    }

    // Step 2: Embed the watermark
    embed_watermark(image, watermark, width, height);

    // Step 3: Write the watermarked image
    write_image(output_filename, image, width, height);

    // Print success message
    printf("Watermarked image has been created: %s\n", output_filename);

    // Step 4: Extract the watermark from the watermarked image
    char extracted_watermark[100]; // Buffer to hold the extracted watermark
    extract_watermark(image, extracted_watermark, watermark_length, width, height);
    printf("Extracted watermark: %s\n", extracted_watermark);

    // Clean up
    free(image);
    return 0;
}