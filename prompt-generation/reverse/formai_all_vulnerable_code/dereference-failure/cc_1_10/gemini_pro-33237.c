//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Embed a watermark into an image.
void embed_watermark(unsigned char *image, int width, int height, unsigned char *watermark, int watermark_width, int watermark_height) {
    // Check if the watermark fits inside the image.
    if (watermark_width > width || watermark_height > height) {
        printf("Watermark is too large for image!\n");
        return;
    }

    // Embed the watermark by XORing it with the image data.
    for (int i = 0; i < watermark_width; i++) {
        for (int j = 0; j < watermark_height; j++) {
            image[(i + watermark_width/2) * width + (j + watermark_height/2)] ^= watermark[i * watermark_width + j];
        }
    }
}

// Extract a watermark from an image.
void extract_watermark(unsigned char *image, int width, int height, unsigned char *watermark, int watermark_width, int watermark_height) {
    // Extract the watermark by XORing the image data with the original watermark.
    for (int i = 0; i < watermark_width; i++) {
        for (int j = 0; j < watermark_height; j++) {
            watermark[i * watermark_width + j] ^= image[(i + watermark_width/2) * width + (j + watermark_height/2)];
        }
    }
}

int main() {
    // Load the image and watermark from files.
    FILE *image_file = fopen("image.bmp", "rb");
    if (image_file == NULL) {
        printf("Could not open image file!\n");
        return 1;
    }
    FILE *watermark_file = fopen("watermark.bmp", "rb");
    if (watermark_file == NULL) {
        printf("Could not open watermark file!\n");
        return 1;
    }

    // Read the image header.
    unsigned char image_header[54];
    fread(image_header, 54, 1, image_file);

    // Get the image dimensions.
    int width = *(int *)&image_header[18];
    int height = *(int *)&image_header[22];

    // Allocate memory for the image data.
    unsigned char *image_data = malloc(width * height * 3);
    if (image_data == NULL) {
        printf("Could not allocate memory for image data!\n");
        return 1;
    }

    // Read the image data.
    fread(image_data, width * height * 3, 1, image_file);
    fclose(image_file);

    // Read the watermark header.
    unsigned char watermark_header[54];
    fread(watermark_header, 54, 1, watermark_file);

    // Get the watermark dimensions.
    int watermark_width = *(int *)&watermark_header[18];
    int watermark_height = *(int *)&watermark_header[22];

    // Allocate memory for the watermark data.
    unsigned char *watermark_data = malloc(watermark_width * watermark_height);
    if (watermark_data == NULL) {
        printf("Could not allocate memory for watermark data!\n");
        return 1;
    }

    // Read the watermark data.
    fread(watermark_data, watermark_width * watermark_height, 1, watermark_file);
    fclose(watermark_file);

    // Embed the watermark into the image.
    embed_watermark(image_data, width, height, watermark_data, watermark_width, watermark_height);

    // Extract the watermark from the image.
    unsigned char extracted_watermark_data[watermark_width * watermark_height];
    extract_watermark(image_data, width, height, extracted_watermark_data, watermark_width, watermark_height);

    // Print the extracted watermark data.
    for (int i = 0; i < watermark_width * watermark_height; i++) {
        printf("%c", extracted_watermark_data[i]);
    }
    printf("\n");

    // Free the allocated memory.
    free(image_data);
    free(watermark_data);

    return 0;
}