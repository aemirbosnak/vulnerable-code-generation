//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
#define CHANNELS 3

// Embed a watermark in an image
void embed_watermark(unsigned char *image, unsigned char *watermark, int watermark_width, int watermark_height) {
    // Iterate over the pixels in the image
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // Get the pixel value
            int r = image[(i * WIDTH + j) * CHANNELS];
            int g = image[(i * WIDTH + j) * CHANNELS + 1];
            int b = image[(i * WIDTH + j) * CHANNELS + 2];

            // Get the watermark value
            int w = watermark[(i * watermark_width + j) % (watermark_width * watermark_height)];

            // Embed the watermark in the least significant bit of the pixel value
            r = (r & 0xfe) | (w & 0x01);
            g = (g & 0xfe) | ((w >> 1) & 0x01);
            b = (b & 0xfe) | ((w >> 2) & 0x01);

            // Set the pixel value
            image[(i * WIDTH + j) * CHANNELS] = r;
            image[(i * WIDTH + j) * CHANNELS + 1] = g;
            image[(i * WIDTH + j) * CHANNELS + 2] = b;
        }
    }
}

// Extract a watermark from an image
void extract_watermark(unsigned char *image, unsigned char *watermark, int watermark_width, int watermark_height) {
    // Iterate over the pixels in the image
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // Get the pixel value
            int r = image[(i * WIDTH + j) * CHANNELS];
            int g = image[(i * WIDTH + j) * CHANNELS + 1];
            int b = image[(i * WIDTH + j) * CHANNELS + 2];

            // Extract the watermark value from the least significant bit of the pixel value
            int w = (r & 0x01) | ((g & 0x01) << 1) | ((b & 0x01) << 2);

            // Set the watermark value
            watermark[(i * watermark_width + j) % (watermark_width * watermark_height)] = w;
        }
    }
}

int main() {
    // Load the image
    FILE *image_file = fopen("image.bmp", "rb");
    if (image_file == NULL) {
        fprintf(stderr, "Error loading image file\n");
        return 1;
    }
    unsigned char *image = malloc(WIDTH * HEIGHT * CHANNELS);
    fread(image, WIDTH * HEIGHT * CHANNELS, 1, image_file);
    fclose(image_file);

    // Load the watermark
    FILE *watermark_file = fopen("watermark.bmp", "rb");
    if (watermark_file == NULL) {
        fprintf(stderr, "Error loading watermark file\n");
        return 1;
    }
    unsigned char *watermark = malloc(WIDTH * HEIGHT);
    fread(watermark, WIDTH * HEIGHT, 1, watermark_file);
    fclose(watermark_file);

    // Embed the watermark in the image
    embed_watermark(image, watermark, WIDTH, HEIGHT);

    // Save the watermarked image
    FILE *watermarked_image_file = fopen("watermarked_image.bmp", "wb");
    if (watermarked_image_file == NULL) {
        fprintf(stderr, "Error saving watermarked image file\n");
        return 1;
    }
    fwrite(image, WIDTH * HEIGHT * CHANNELS, 1, watermarked_image_file);
    fclose(watermarked_image_file);

    // Extract the watermark from the image
    unsigned char *extracted_watermark = malloc(WIDTH * HEIGHT);
    extract_watermark(image, extracted_watermark, WIDTH, HEIGHT);

    // Save the extracted watermark
    FILE *extracted_watermark_file = fopen("extracted_watermark.bmp", "wb");
    if (extracted_watermark_file == NULL) {
        fprintf(stderr, "Error saving extracted watermark file\n");
        return 1;
    }
    fwrite(extracted_watermark, WIDTH * HEIGHT, 1, extracted_watermark_file);
    fclose(extracted_watermark_file);

    // Free the allocated memory
    free(image);
    free(watermark);
    free(extracted_watermark);

    return 0;
}