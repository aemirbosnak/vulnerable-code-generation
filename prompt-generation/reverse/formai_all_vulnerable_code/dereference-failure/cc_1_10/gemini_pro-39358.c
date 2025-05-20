//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512

// Function to embed a watermark into an image
void embed_watermark(unsigned char *image, unsigned char *watermark, int w_width, int w_height) {
    int i, j;
    double alpha = 0.5;  // Watermark strength

    // Iterate over the image and embed the watermark
    for (i = 0; i < IMAGE_HEIGHT; i++) {
        for (j = 0; j < IMAGE_WIDTH; j++) {
            // If the pixel is within the watermark area, blend the watermark color
            if (i < w_height && j < w_width) {
                image[i * IMAGE_WIDTH + j] = (1 - alpha) * image[i * IMAGE_WIDTH + j] + alpha * watermark[i * w_width + j];
            }
        }
    }
}

// Function to extract a watermark from an image
void extract_watermark(unsigned char *image, unsigned char *watermark, int w_width, int w_height) {
    int i, j;
    double beta = 0.5;   // Watermark strength

    // Iterate over the image and extract the watermark
    for (i = 0; i < IMAGE_HEIGHT; i++) {
        for (j = 0; j < IMAGE_WIDTH; j++) {
            // If the pixel is within the watermark area, extract the watermark color
            if (i < w_height && j < w_width) {
                watermark[i * w_width + j] = (image[i * IMAGE_WIDTH + j] - beta * image[i * IMAGE_WIDTH + j]) / (1 - beta);
            }
        }
    }
}

// Main function
int main() {
    // Load the original image
    unsigned char *image = (unsigned char *)malloc(IMAGE_WIDTH * IMAGE_HEIGHT);
    FILE *image_file = fopen("image.bmp", "rb");
    fread(image, IMAGE_WIDTH * IMAGE_HEIGHT, 1, image_file);
    fclose(image_file);

    // Load the watermark
    unsigned char *watermark = (unsigned char *)malloc(50 * 50);
    FILE *watermark_file = fopen("watermark.bmp", "rb");
    fread(watermark, 50 * 50, 1, watermark_file);
    fclose(watermark_file);

    // Embed the watermark into the image
    embed_watermark(image, watermark, 50, 50);

    // Save the watermarked image
    FILE *output_file = fopen("watermarked_image.bmp", "wb");
    fwrite(image, IMAGE_WIDTH * IMAGE_HEIGHT, 1, output_file);
    fclose(output_file);

    // Extract the watermark from the watermarked image
    unsigned char *extracted_watermark = (unsigned char *)malloc(50 * 50);
    extract_watermark(image, extracted_watermark, 50, 50);

    // Save the extracted watermark
    FILE *extracted_watermark_file = fopen("extracted_watermark.bmp", "wb");
    fwrite(extracted_watermark, 50 * 50, 1, extracted_watermark_file);
    fclose(extracted_watermark_file);

    // Free the allocated memory
    free(image);
    free(watermark);
    free(extracted_watermark);

    return 0;
}