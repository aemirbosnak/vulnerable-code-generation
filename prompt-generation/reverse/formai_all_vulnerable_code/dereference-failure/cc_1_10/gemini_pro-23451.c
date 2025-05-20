//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Embeds the watermark in the image.
void embedWatermark(unsigned char *image, unsigned char *watermark, int imageWidth, int imageHeight, int watermarkWidth, int watermarkHeight) {
    int x, y, i, j;
    double alpha = 0.05; // Watermark opacity

    // Iterate over the image.
    for (y = 0; y < imageHeight; y++) {
        for (x = 0; x < imageWidth; x++) {
            // Iterate over the watermark.
            for (i = 0; i < watermarkWidth; i++) {
                for (j = 0; j < watermarkHeight; j++) {
                    // Get the pixel value from the image and the watermark.
                    int imagePixel = image[y * imageWidth + x];
                    int watermarkPixel = watermark[j * watermarkWidth + i];

                    // Calculate the new pixel value.
                    int newPixel = (1 - alpha) * imagePixel + alpha * watermarkPixel;

                    // Set the new pixel value in the image.
                    image[y * imageWidth + x] = newPixel;
                }
            }
        }
    }
}

// Extracts the watermark from the image.
void extractWatermark(unsigned char *image, unsigned char *watermark, int imageWidth, int imageHeight, int watermarkWidth, int watermarkHeight) {
    int x, y, i, j;
    double alpha = 0.05; // Watermark opacity

    // Iterate over the image.
    for (y = 0; y < imageHeight; y++) {
        for (x = 0; x < imageWidth; x++) {
            // Iterate over the watermark.
            for (i = 0; i < watermarkWidth; i++) {
                for (j = 0; j < watermarkHeight; j++) {
                    // Get the pixel value from the image and the watermark.
                    int imagePixel = image[y * imageWidth + x];
                    int watermarkPixel = watermark[j * watermarkWidth + i];

                    // Calculate the watermark pixel value.
                    int newPixel = (imagePixel - (1 - alpha) * imagePixel) / alpha;

                    // Set the watermark pixel value in the watermark.
                    watermark[j * watermarkWidth + i] = newPixel;
                }
            }
        }
    }
}

int main() {
    // Load the image.
    unsigned char *image = malloc(1000 * 1000);
    FILE *image_file = fopen("image.bmp", "rb");
    fread(image, 1, 1000 * 1000, image_file);
    fclose(image_file);

    // Load the watermark.
    unsigned char *watermark = malloc(100 * 100);
    FILE *watermark_file = fopen("watermark.bmp", "rb");
    fread(watermark, 1, 100 * 100, watermark_file);
    fclose(watermark_file);

    // Embed the watermark in the image.
    embedWatermark(image, watermark, 1000, 1000, 100, 100);

    // Save the watermarked image.
    FILE *watermarked_image_file = fopen("watermarked_image.bmp", "wb");
    fwrite(image, 1, 1000 * 1000, watermarked_image_file);
    fclose(watermarked_image_file);

    // Extract the watermark from the image.
    extractWatermark(image, watermark, 1000, 1000, 100, 100);

    // Save the extracted watermark.
    FILE *extracted_watermark_file = fopen("extracted_watermark.bmp", "wb");
    fwrite(watermark, 1, 100 * 100, extracted_watermark_file);
    fclose(extracted_watermark_file);

    return 0;
}