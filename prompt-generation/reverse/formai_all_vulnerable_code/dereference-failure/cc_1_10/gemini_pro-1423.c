//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the watermark data
typedef struct {
    char *watermark;
    int length;
} Watermark;

// Function to embed the watermark into the image
void embedWatermark(unsigned char *image, int imageSize, Watermark watermark) {
    // Check if the watermark is too large for the image
    if (watermark.length > imageSize) {
        printf("Error: Watermark is too large for the image.\n");
        return;
    }

    // Embed the watermark into the image by modifying the least significant bits of the pixels
    for (int i = 0; i < watermark.length; i++) {
        image[i] = (image[i] & 0x7F) | ((watermark.watermark[i] & 0x01) << 7);
    }

    printf("Watermark embedded successfully.\n");
}

// Function to extract the watermark from the image
void extractWatermark(unsigned char *image, int imageSize, Watermark *watermark) {
    // Allocate memory for the watermark
    watermark->watermark = malloc(imageSize);
    watermark->length = 0;

    // Extract the watermark from the image by extracting the least significant bits of the pixels
    for (int i = 0; i < imageSize; i++) {
        watermark->watermark[watermark->length++] = (image[i] & 0x80) >> 7;
    }

    printf("Watermark extracted successfully.\n");
}

// Main function
int main() {
    // Create the watermark
    Watermark watermark;
    watermark.watermark = "Thank you for using this program!";
    watermark.length = strlen(watermark.watermark);

    // Read the image from a file
    FILE *imageFile;
    imageFile = fopen("image.bmp", "rb");
    if (imageFile == NULL) {
        printf("Error: Could not open the image file.\n");
        return 1;
    }

    // Get the size of the image
    fseek(imageFile, 0, SEEK_END);
    int imageSize = ftell(imageFile);
    rewind(imageFile);

    // Allocate memory for the image
    unsigned char *image = malloc(imageSize);

    // Read the image data into memory
    fread(image, 1, imageSize, imageFile);
    fclose(imageFile);

    // Embed the watermark into the image
    embedWatermark(image, imageSize, watermark);

    // Write the watermarked image to a file
    FILE *watermarkedImageFile;
    watermarkedImageFile = fopen("watermarked_image.bmp", "wb");
    if (watermarkedImageFile == NULL) {
        printf("Error: Could not open the watermarked image file.\n");
        return 1;
    }

    // Write the watermarked image data to the file
    fwrite(image, 1, imageSize, watermarkedImageFile);
    fclose(watermarkedImageFile);

    // Extract the watermark from the watermarked image
    Watermark extractedWatermark;
    extractWatermark(image, imageSize, &extractedWatermark);

    // Print the extracted watermark
    printf("Extracted watermark: %s\n", extractedWatermark.watermark);

    // Free the memory allocated for the image and the watermark
    free(image);
    free(extractedWatermark.watermark);

    return 0;
}