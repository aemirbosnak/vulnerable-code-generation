//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform digital watermarking on an image
void watermark(char* image_data, int size, char* watermark_text, int text_len) {
    int watermark_index = 0;

    // Loop through the image data and apply the watermark text
    for (int i = 0; i < size; i++) {
        // Check if we've reached the end of the watermark text
        if (watermark_index == text_len) {
            // Reset the watermark index to start over
            watermark_index = 0;
        }

        // XOR the current image data byte with the corresponding watermark text byte
        image_data[i] ^= watermark_text[watermark_index];
        
        // Increment the watermark index
        watermark_index++;
    }
}

int main() {
    // Read the image data from a file
    FILE* image_file = fopen("image.bmp", "rb");
    if (!image_file) {
        printf("Error: Could not open image file!\n");
        return 1;
    }

    // Get the file size
    fseek(image_file, 0L, SEEK_END);
    int size = ftell(image_file);
    fseek(image_file, 0L, SEEK_SET);

    // Allocate memory for the image data
    char* image_data = (char*) malloc(size);
    if (!image_data) {
        printf("Error: Could not allocate memory for image data!\n");
        return 1;
    }

    // Read the image data into memory
    fread(image_data, size, 1, image_file);

    // Close the image file
    fclose(image_file);

    // Define the watermark text to apply to the image
    char* watermark_text = "This is my watermark text!";

    // Get the length of the watermark text
    int text_len = strlen(watermark_text);

    // Apply the watermark to the image data
    watermark(image_data, size, watermark_text, text_len);

    // Write the watermarked image to a file
    FILE* watermarked_file = fopen("watermarked_image.bmp", "wb");
    if (!watermarked_file) {
        printf("Error: Could not create watermarked image file!\n");
        return 1;
    }

    // Write the watermarked image data to the file
    fwrite(image_data, size, 1, watermarked_file);

    // Close the watermarked image file
    fclose(watermarked_file);

    // Free the memory for the image data
    free(image_data);

    return 0;
}