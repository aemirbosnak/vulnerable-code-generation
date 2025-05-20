//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Function to embed the watermark in the image
void embedWatermark(unsigned char *imageData, unsigned char *watermarkData, int imageSize, int watermarkSize) {
  // Loop through the image data and embed the watermark data
  for (int i = 0; i < imageSize; i++) {
    // Get the least significant bit of the image data
    unsigned char lsb = imageData[i] & 0x01;

    // Set the least significant bit of the image data to the watermark data
    imageData[i] = (imageData[i] & ~0x01) | (watermarkData[i] & 0x01);

    // Shift the watermark data by 1 bit to the right
    watermarkData[i] >>= 1;
  }
}

// Function to extract the watermark from the image
void extractWatermark(unsigned char *imageData, unsigned char *watermarkData, int imageSize, int watermarkSize) {
  // Loop through the image data and extract the watermark data
  for (int i = 0; i < imageSize; i++) {
    // Get the least significant bit of the image data
    unsigned char lsb = imageData[i] & 0x01;

    // Set the least significant bit of the watermark data to the least significant bit of the image data
    watermarkData[i] = (watermarkData[i] & ~0x01) | lsb;

    // Shift the watermark data by 1 bit to the right
    watermarkData[i] >>= 1;
  }
}

int main() {
  // Read the image data from a file
  FILE *imageFile = fopen("image.bmp", "rb");
  if (imageFile == NULL) {
    printf("Error opening the image file.\n");
    return 1;
  }
  fseek(imageFile, 0, SEEK_END);
  int imageSize = ftell(imageFile);
  fseek(imageFile, 0, SEEK_SET);
  unsigned char *imageData = malloc(imageSize);
  fread(imageData, 1, imageSize, imageFile);
  fclose(imageFile);

  // Read the watermark data from a file
  FILE *watermarkFile = fopen("watermark.bmp", "rb");
  if (watermarkFile == NULL) {
    printf("Error opening the watermark file.\n");
    free(imageData);
    return 1;
  }
  fseek(watermarkFile, 0, SEEK_END);
  int watermarkSize = ftell(watermarkFile);
  fseek(watermarkFile, 0, SEEK_SET);
  unsigned char *watermarkData = malloc(watermarkSize);
  fread(watermarkData, 1, watermarkSize, watermarkFile);
  fclose(watermarkFile);

  // Embed the watermark in the image
  embedWatermark(imageData, watermarkData, imageSize, watermarkSize);

  // Write the watermarked image to a file
  FILE *watermarkedImageFile = fopen("watermarkedImage.bmp", "wb");
  if (watermarkedImageFile == NULL) {
    printf("Error opening the watermarked image file.\n");
    free(imageData);
    free(watermarkData);
    return 1;
  }
  fwrite(imageData, 1, imageSize, watermarkedImageFile);
  fclose(watermarkedImageFile);

  // Extract the watermark from the image
  unsigned char *extractedWatermarkData = malloc(watermarkSize);
  extractWatermark(imageData, extractedWatermarkData, imageSize, watermarkSize);

  // Write the extracted watermark to a file
  FILE *extractedWatermarkFile = fopen("extractedWatermark.bmp", "wb");
  if (extractedWatermarkFile == NULL) {
    printf("Error opening the extracted watermark file.\n");
    free(imageData);
    free(watermarkData);
    free(extractedWatermarkData);
    return 1;
  }
  fwrite(extractedWatermarkData, 1, watermarkSize, extractedWatermarkFile);
  fclose(extractedWatermarkFile);

  // Free the allocated memory
  free(imageData);
  free(watermarkData);
  free(extractedWatermarkData);

  return 0;
}