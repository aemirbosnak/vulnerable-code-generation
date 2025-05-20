//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Function to embed the watermark
void embedWatermark(unsigned char *image, int imageSize, unsigned char *watermark, int watermarkSize) {
    // Check if the watermark size is less than the image size
    if (watermarkSize > imageSize) {
        printf("Watermark size cannot be greater than image size.\n");
        return;
    }

    // Embed the watermark in the image
    for (int i = 0; i < watermarkSize; i++) {
        // Get the least significant bit of the image pixel
        unsigned char lsb = image[i] & 1;

        // Replace the least significant bit with the watermark bit
        image[i] = (image[i] & ~1) | (watermark[i] & 1);

        // Shift the watermark bit to the right
        watermark[i] >>= 1;
    }
}

// Function to extract the watermark
void extractWatermark(unsigned char *image, int imageSize, unsigned char *watermark, int watermarkSize) {
    // Extract the watermark from the image
    for (int i = 0; i < watermarkSize; i++) {
        // Get the least significant bit of the image pixel
        unsigned char lsb = image[i] & 1;

        // Set the watermark bit to the least significant bit of the image pixel
        watermark[i] = lsb;

        // Shift the watermark bit to the left
        watermark[i] <<= 1;
    }
}

int main() {
    // Load the image and watermark from files
    FILE *image_file = fopen("image.bmp", "rb");
    if (image_file == NULL) {
        printf("Error opening image file.\n");
        return 1;
    }

    fseek(image_file, 0, SEEK_END);
    int imageSize = ftell(image_file);
    rewind(image_file);

    unsigned char *image = malloc(imageSize);
    if (image == NULL) {
        printf("Error allocating memory for image.\n");
        fclose(image_file);
        return 1;
    }

    fread(image, 1, imageSize, image_file);
    fclose(image_file);

    FILE *watermark_file = fopen("watermark.bmp", "rb");
    if (watermark_file == NULL) {
        printf("Error opening watermark file.\n");
        free(image);
        return 1;
    }

    fseek(watermark_file, 0, SEEK_END);
    int watermarkSize = ftell(watermark_file);
    rewind(watermark_file);

    unsigned char *watermark = malloc(watermarkSize);
    if (watermark == NULL) {
        printf("Error allocating memory for watermark.\n");
        fclose(watermark_file);
        free(image);
        return 1;
    }

    fread(watermark, 1, watermarkSize, watermark_file);
    fclose(watermark_file);

    // Embed the watermark in the image
    embedWatermark(image, imageSize, watermark, watermarkSize);

    // Save the watermarked image to a file
    FILE *watermarked_image_file = fopen("watermarked_image.bmp", "wb");
    if (watermarked_image_file == NULL) {
        printf("Error opening watermarked image file.\n");
        free(image);
        free(watermark);
        return 1;
    }

    fwrite(image, 1, imageSize, watermarked_image_file);
    fclose(watermarked_image_file);

    // Extract the watermark from the watermarked image
    unsigned char *extracted_watermark = malloc(watermarkSize);
    if (extracted_watermark == NULL) {
        printf("Error allocating memory for extracted watermark.\n");
        free(image);
        free(watermark);
        return 1;
    }

    extractWatermark(image, imageSize, extracted_watermark, watermarkSize);

    // Compare the extracted watermark with the original watermark
    int same = 1;
    for (int i = 0; i < watermarkSize; i++) {
        if (watermark[i] != extracted_watermark[i]) {
            same = 0;
            break;
        }
    }

    if (same) {
        printf("Watermark extracted successfully.\n");
    } else {
        printf("Watermark extraction failed.\n");
    }

    // Free the allocated memory
    free(image);
    free(watermark);
    free(extracted_watermark);

    return 0;
}