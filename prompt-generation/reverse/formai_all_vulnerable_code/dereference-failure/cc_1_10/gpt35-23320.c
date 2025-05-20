//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add the watermark to the image data
void addWatermark(unsigned char* imgData, int imgSize, char* watermark) {
  // Get the length of the watermark
  int wmLength = strlen(watermark);
  int numChars = wmLength * 8;
  
  // Loop through each byte of the image data
  for(int i=0; i<imgSize; i++) {
    // Check if we've reached the end of the watermark
    if(i*8 >= numChars) {
      return;
    }
    
    // Get the value of the current byte
    unsigned char val = imgData[i];
    // Loop through each bit of the byte
    for(int j=0; j<8; j++) {
      // Check if we've reached the end of the watermark
      if(i*8+j >= numChars) {
        return;
      }
      // Get the value of the current bit
      unsigned char bitVal = (watermark[(i*8+j)/8] >> ((i*8+j)%8)) & 1;
      // Set the least significant bit of the current byte to the current bit of the watermark
      val = val & ~(1 << j) | (bitVal << j);
    }
    // Set the new value of the current byte
    imgData[i] = val;
  }
}

// Function to extract the watermark from the image data
void extractWatermark(unsigned char* imgData, int imgSize, char* watermark, int wmSize) {
  // Loop through each byte of the image data
  for(int i=0; i<imgSize; i++) {
    // Check if we've extracted enough characters
    if(i*8 >= wmSize) {
      return;
    }
    
    // Get the value of the current byte
    unsigned char val = imgData[i];
    // Loop through each bit of the byte
    for(int j=0; j<8; j++) {
      // Check if we've extracted enough characters
      if(i*8+j >= wmSize) {
        return;
      }
      // Get the value of the current bit
      unsigned char bitVal = (val >> j) & 1;
      // Set the bit in the watermark
      watermark[(i*8+j)/8] = watermark[(i*8+j)/8] & ~(1 << ((i*8+j)%8)) | (bitVal << ((i*8+j)%8));
    }
  }
}

int main() {
  // Load the image data from a file
  FILE* file = fopen("image.bmp", "rb");
  if(!file) {
    printf("Unable to open image file\n");
    return 1;
  }
  fseek(file, 0, SEEK_END);
  int imgSize = ftell(file);
  fseek(file, 0, SEEK_SET);
  unsigned char* imgData = (unsigned char*) malloc(imgSize);
  if(fread(imgData, 1, imgSize, file) != imgSize) {
    printf("Unable to read image file\n");
    return 1;
  }
  fclose(file);
  
  // Add the watermark to the image data
  char* watermark = "This is a digital watermark!";
  addWatermark(imgData, imgSize, watermark);
  
  // Extract the watermark from the image data
  char* extractedWatermark = (char*) malloc(strlen(watermark));
  memset(extractedWatermark, 0, strlen(watermark));
  extractWatermark(imgData, imgSize, extractedWatermark, strlen(watermark)*8);
  
  // Print the original and extracted watermarks
  printf("Original Watermark: %s\n", watermark);
  printf("Extracted Watermark: %s\n", extractedWatermark);

  free(imgData);
  free(extractedWatermark);
  
  return 0;
}