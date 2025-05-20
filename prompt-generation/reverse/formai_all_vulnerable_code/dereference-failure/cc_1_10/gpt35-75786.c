//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WATERMARK_SIZE 1000

char* watermark = "The sky is a canvas painted with the colors of our dreams.";

int main() {

  // Load image file
  FILE* imageFile = fopen("input.bmp", "rb");
  if (imageFile == NULL) {
    printf("Error: Failed to load image.");
    return 1;
  }

  // Retrieve image metadata
  unsigned char header[54];
  fread(header, sizeof(unsigned char), 54, imageFile);
  int width = *(int*)&header[18];
  int height = *(int*)&header[22];
  int imageSize = *(int*)&header[34];

  // Check if image is within acceptable size range to add watermark
  if (imageSize <= MAX_WATERMARK_SIZE) {
    printf("Error: Image size too small to add watermark. Please choose a larger image.\n");
    return 1;
  }

  // Allocate memory for image and watermark data
  unsigned char* imageData = (unsigned char*)malloc(sizeof(unsigned char) * imageSize);
  char* watermarkData = (char*)malloc(sizeof(char) * MAX_WATERMARK_SIZE);

  // Read image data into memory
  fread(imageData, sizeof(unsigned char), imageSize, imageFile);
  fclose(imageFile);

  // Append watermark to image data
  strcat(watermarkData, watermark);
  memcpy(&imageData[imageSize - strlen(watermarkData)], watermarkData, strlen(watermarkData));

  // Save watermarked image to file
  FILE* outputImage = fopen("output.bmp", "wb+");
  fwrite(header, sizeof(unsigned char), 54, outputImage);
  fwrite(imageData, sizeof(unsigned char), imageSize, outputImage);
  fclose(outputImage);

  free(imageData);
  free(watermarkData);

  printf("Watermark added!\n");

  return 0;
}