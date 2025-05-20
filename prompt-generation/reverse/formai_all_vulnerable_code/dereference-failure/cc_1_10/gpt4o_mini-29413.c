//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void embedWatermark(const char *inputImage, const char *watermarkText);
void extractWatermark(const char *inputImage);

void embedWatermark(const char *inputImage, const char *watermarkText) {
    FILE *file = fopen(inputImage, "rb");
    if (!file) {
        printf("Error: Could not open image file %s\n", inputImage);
        return;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    unsigned char *imageData = (unsigned char *)malloc(fileSize);
    fread(imageData, fileSize, 1, file);
    fclose(file);

    // Simple watermark embedding: modify the last byte
    size_t watermarkLength = strlen(watermarkText);
    if (watermarkLength > 1) {
        watermarkLength = 1; // Only embed one character in the example
    }

    // Embed watermark character into the last byte of the image
    imageData[fileSize - 1] = watermarkText[0];

    // Save the watermarked image
    file = fopen("watermarked_image.bmp", "wb");
    if (!file) {
        printf("Error: Could not open output file watermarked_image.bmp\n");
        free(imageData);
        return;
    }

    fwrite(imageData, fileSize, 1, file);
    fclose(file);
    free(imageData);

    printf("Watermark '%s' embedded successfully into %s!\n", watermarkText, inputImage);
}

void extractWatermark(const char *inputImage) {
    FILE *file = fopen(inputImage, "rb");
    if (!file) {
        printf("Error: Could not open image file %s\n", inputImage);
        return;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    fseek(file, fileSize - 1, SEEK_SET); // Move to the last byte
    unsigned char watermarkCharacter;
    fread(&watermarkCharacter, 1, 1, file);
    fclose(file);

    printf("Extracted watermark: '%c'\n", watermarkCharacter);
}

int main() {
    printf("Digital Watermarking Example Program\n");
    printf("=====================================\n");

    char inputImage[256];
    char watermarkText[256];

    // Get the image file from the user
    printf("Enter the path to the image file (e.g., image.bmp): ");
    scanf("%s", inputImage);

    // Get the watermark text from the user
    printf("Enter the watermark text (single character): ");
    scanf("%s", watermarkText);

    // Embed the watermark into the image
    embedWatermark(inputImage, watermarkText);

    // Extract the watermark from the watermarked image
    printf("Now extracting the watermark from the watermarked image...\n");
    extractWatermark("watermarked_image.bmp");

    printf("Program completed successfully!\n");
    return 0;
}