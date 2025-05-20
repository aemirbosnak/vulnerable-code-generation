//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: random
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Embed watermark in image data
void embed_watermark(unsigned char *image, int width, int height, unsigned char *watermark, int watermark_width, int watermark_height) {
    // Iterate over image pixels
    for (int i = 0; i < width * height; i++) {
        // Get watermark pixel value
        int watermark_x = i % watermark_width;
        int watermark_y = (i / watermark_width) % watermark_height;
        unsigned char watermark_value = watermark[watermark_y * watermark_width + watermark_x];

        // Embed watermark in image pixel
        image[i] = (image[i] & ~1) | (watermark_value & 1);
    }
}

// Extract watermark from image data
void extract_watermark(unsigned char *image, int width, int height, unsigned char *watermark, int watermark_width, int watermark_height) {
    // Iterate over image pixels
    for (int i = 0; i < width * height; i++) {
        // Get watermark pixel value
        int watermark_x = i % watermark_width;
        int watermark_y = (i / watermark_width) % watermark_height;
        watermark[watermark_y * watermark_width + watermark_x] = (image[i] & 1);
    }
}

int main() {
    // Define image and watermark data
    int image_width = 100, image_height = 100;
    unsigned char *image = (unsigned char *)malloc(image_width * image_height * sizeof(unsigned char));
    int watermark_width = 10, watermark_height = 10;
    unsigned char watermark[watermark_width * watermark_height];

    // Generate random image data
    for (int i = 0; i < image_width * image_height; i++) {
        image[i] = (unsigned char)rand() % 256;
    }

    // Generate random watermark data
    for (int i = 0; i < watermark_width * watermark_height; i++) {
        watermark[i] = (unsigned char)rand() % 256;
    }

    // Embed watermark in image data
    embed_watermark(image, image_width, image_height, watermark, watermark_width, watermark_height);

    // Extract watermark from image data
    unsigned char extracted_watermark[watermark_width * watermark_height];
    extract_watermark(image, image_width, image_height, extracted_watermark, watermark_width, watermark_height);

    // Compare extracted watermark to original watermark
    int errors = 0;
    for (int i = 0; i < watermark_width * watermark_height; i++) {
        errors += (extracted_watermark[i] != watermark[i]);
    }

    // Print results
    printf("Number of errors: %d\n", errors);

    // Free allocated memory
    free(image);
    free(extracted_watermark);

    return 0;
}