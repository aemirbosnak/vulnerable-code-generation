//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Converts an image to grayscale
void to_grayscale(unsigned char *image, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        unsigned char r = image[i * 3];
        unsigned char g = image[i * 3 + 1];
        unsigned char b = image[i * 3 + 2];
        unsigned char gray = (r + g + b) / 3;
        image[i * 3] = gray;
        image[i * 3 + 1] = gray;
        image[i * 3 + 2] = gray;
    }
}

// Embeds a binary watermark into an image
void embed_watermark(unsigned char *image, int width, int height, unsigned char *watermark, int watermark_size) {
    int watermark_index = 0;
    for (int i = 0; i < width * height; i++) {
        // Get the least significant bit of the pixel
        unsigned char lsb = image[i] & 1;
        // If the watermark bit is 1, set the LSB to 1
        if (watermark_index < watermark_size && watermark[watermark_index] == 1) {
            image[i] |= 1;
        }
        // If the watermark bit is 0, clear the LSB to 0
        else if (watermark_index < watermark_size) {
            image[i] &= ~1;
        }
        // Increment the watermark index
        watermark_index++;
    }
}

// Extracts the binary watermark from an image
unsigned char *extract_watermark(unsigned char *image, int width, int height, int watermark_size) {
    unsigned char *watermark = malloc(watermark_size);
    int watermark_index = 0;
    for (int i = 0; i < width * height; i++) {
        // Get the least significant bit of the pixel
        unsigned char lsb = image[i] & 1;
        // Set the corresponding bit in the watermark
        watermark[watermark_index] = lsb;
        // Increment the watermark index
        watermark_index++;
        // If the watermark is fully extracted, break
        if (watermark_index >= watermark_size) {
            break;
        }
    }
    return watermark;
}

int main() {
    // Load the image
    unsigned char *image = malloc(3 * 256 * 256);
    FILE *image_file = fopen("image.bmp", "rb");
    fread(image, 1, 3 * 256 * 256, image_file);
    fclose(image_file);

    // Convert the image to grayscale
    to_grayscale(image, 256, 256);

    // Load the binary watermark
    unsigned char *watermark = malloc(1024);
    FILE *watermark_file = fopen("watermark.bin", "rb");
    fread(watermark, 1, 1024, watermark_file);
    fclose(watermark_file);

    // Embed the watermark
    embed_watermark(image, 256, 256, watermark, 1024);

    // Save the watermarked image
    FILE *watermarked_image_file = fopen("watermarked_image.bmp", "wb");
    fwrite(image, 1, 3 * 256 * 256, watermarked_image_file);
    fclose(watermarked_image_file);

    // Extract the watermark
    unsigned char *extracted_watermark = extract_watermark(image, 256, 256, 1024);

    // Save the extracted watermark
    FILE *extracted_watermark_file = fopen("extracted_watermark.bin", "wb");
    fwrite(extracted_watermark, 1, 1024, extracted_watermark_file);
    fclose(extracted_watermark_file);

    // Free the allocated memory
    free(image);
    free(watermark);
    free(extracted_watermark);
    return 0;
}