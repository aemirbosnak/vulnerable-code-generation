//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512

int main() {
    // Read the original image
    FILE *original_image_file = fopen("original_image.bmp", "rb");
    if (original_image_file == NULL) {
        printf("Error opening the original image file.\n");
        return EXIT_FAILURE;
    }

    unsigned char original_image_header[54];
    fread(original_image_header, sizeof(unsigned char), 54, original_image_file);

    unsigned char *original_image_data = malloc(WIDTH * HEIGHT * 3);
    fread(original_image_data, sizeof(unsigned char), WIDTH * HEIGHT * 3, original_image_file);
    fclose(original_image_file);

    // Read the watermark image
    FILE *watermark_image_file = fopen("watermark_image.bmp", "rb");
    if (watermark_image_file == NULL) {
        printf("Error opening the watermark image file.\n");
        return EXIT_FAILURE;
    }

    unsigned char watermark_image_header[54];
    fread(watermark_image_header, sizeof(unsigned char), 54, watermark_image_file);

    unsigned char *watermark_image_data = malloc(WIDTH * HEIGHT);
    fread(watermark_image_data, sizeof(unsigned char), WIDTH * HEIGHT, watermark_image_file);
    fclose(watermark_image_file);

    // Embed the watermark into the original image
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        original_image_data[i] = (original_image_data[i] & 0xF8) | (watermark_image_data[i] >> 3);
    }

    // Write the watermarked image to a file
    FILE *watermarked_image_file = fopen("watermarked_image.bmp", "wb");
    if (watermarked_image_file == NULL) {
        printf("Error opening the watermarked image file.\n");
        return EXIT_FAILURE;
    }

    fwrite(original_image_header, sizeof(unsigned char), 54, watermarked_image_file);
    fwrite(original_image_data, sizeof(unsigned char), WIDTH * HEIGHT * 3, watermarked_image_file);
    fclose(watermarked_image_file);

    // Free the allocated memory
    free(original_image_data);
    free(watermark_image_data);

    return EXIT_SUCCESS;
}