//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

// Function declarations
void embed(uint8_t *image_buffer, uint8_t *watermark_buffer, int curr_byte, int watermark_size);
void extract(uint8_t *image_buffer, uint8_t *watermark_buffer, int curr_byte, int watermark_size);

// Main function
int main() {
    // Declare necessary variables
    FILE *image_file, *watermark_file, *output_file;
    uint8_t *image_buffer, *watermark_buffer;
    int image_size, watermark_size;

    // Open the image file
    image_file = fopen("image.bmp", "rb");
    if(image_file == NULL) {
        printf("Error: Could not open image file.\n");
        exit(EXIT_FAILURE);
    }

    // Get the size of the image file
    fseek(image_file, 0L, SEEK_END);
    image_size = ftell(image_file);
    fseek(image_file, 0L, SEEK_SET);

    // Allocate memory for the image buffer
    image_buffer = (uint8_t*)malloc(image_size * sizeof(uint8_t));

    // Read the contents of the image file into the image buffer
    fread(image_buffer, sizeof(uint8_t), image_size, image_file);

    // Close the image file
    fclose(image_file);

    // Open the watermark file
    watermark_file = fopen("watermark.txt", "rb");
    if(watermark_file == NULL) {
        printf("Error: Could not open watermark file.\n");
        exit(EXIT_FAILURE);
    }

    // Get the size of the watermark file
    fseek(watermark_file, 0L, SEEK_END);
    watermark_size = ftell(watermark_file);
    fseek(watermark_file, 0L, SEEK_SET);

    // Allocate memory for the watermark buffer
    watermark_buffer = (uint8_t*)malloc(watermark_size * sizeof(uint8_t));

    // Read the contents of the watermark file into the watermark buffer
    fread(watermark_buffer, sizeof(uint8_t), watermark_size, watermark_file);

    // Close the watermark file
    fclose(watermark_file);

    // Embed the watermark into the image
    embed(image_buffer, watermark_buffer, 0, watermark_size);

    // Open the output file
    output_file = fopen("output.bmp", "wb");
    if(output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(EXIT_FAILURE);
    }

    // Write the contents of the image buffer to the output file
    fwrite(image_buffer, sizeof(uint8_t), image_size, output_file);

    // Close the output file
    fclose(output_file);

    // Extract the watermark from the image
    uint8_t *extracted_watermark_buffer;
    extracted_watermark_buffer = (uint8_t*)malloc(watermark_size * sizeof(uint8_t));
    extract(image_buffer, extracted_watermark_buffer, 0, watermark_size);

    // Print the extracted watermark
    for(int i = 0; i < watermark_size; i++) {
        printf("%c", extracted_watermark_buffer[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(image_buffer);
    free(watermark_buffer);
    free(extracted_watermark_buffer);

    return 0;
}

// Function to embed the watermark into the image
void embed(uint8_t *image_buffer, uint8_t *watermark_buffer, int curr_byte, int watermark_size) {
    // Base case
    if(curr_byte >= watermark_size) {
        return;
    }

    // Recursive case
    int bit_count = 0;
    for(int i = curr_byte * 8; i < (curr_byte + 1) * 8; i++) {
        // Extract the current bit of the watermark byte
        uint8_t watermark_bit = ((watermark_buffer[curr_byte] >> bit_count) & 1);

        // Embed the watermark bit into the least significant bit of the image byte
        image_buffer[i] &= 0xFE;    // Clear the least significant bit
        image_buffer[i] |= watermark_bit; // Embed the watermark bit

        // Increment the bit count
        bit_count++;
    }

    // Recursive call
    embed(image_buffer, watermark_buffer, curr_byte + 1, watermark_size);
}

// Function to extract the watermark from the image
void extract(uint8_t *image_buffer, uint8_t *watermark_buffer, int curr_byte, int watermark_size) {
    // Base case
    if(curr_byte >= watermark_size) {
        return;
    }

    // Recursive case
    int byte_count = 0;
    for(int i = curr_byte * 8; i < (curr_byte + 1) * 8; i++) {
        // Extract the least significant bit of the image byte
        uint8_t extracted_bit = (image_buffer[i] & 1);

        // Insert the extracted bit into the current watermark byte
        watermark_buffer[curr_byte] |= (extracted_bit << byte_count);

        // Increment the byte count
        byte_count++;
    }

    // Recursive call
    extract(image_buffer, watermark_buffer, curr_byte + 1, watermark_size);
}