//FormAI DATASET v1.0 Category: Image Steganography ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 1000000

void hideData(unsigned char* image, int imageSize, char* data, int dataSize){
  int i, j, k, bitIndex;
  char currentBit;
  
  // Loop through the data and hide it in the image
  for(i=0;i<dataSize;i++){
    // Get the current byte of data
    char currentByte = data[i];
    
    // Loop through the bits of the data byte
    for(j=0;j<8;j++){
      // Get the current bit of the data byte
      currentBit = (currentByte >> j) & 1;
      
      // Get the bit index in the image where this bit will be hidden
      bitIndex = i*8 + j;
      
      // Get the byte index in the image where the target bit is located
      k = bitIndex/8;
      
      // If the target bit is in the range of image size, hide the current bit in it
      if(k < imageSize){
        // Set the target bit to the current bit
        int bitShift = 7 - (bitIndex % 8);
        image[k] = (image[k] & ~(1 << bitShift)) | (currentBit << bitShift);
      }
    }
  }
}

void extractData(unsigned char* image, int imageSize, char* data, int dataSize){
  int i, j, k, bitIndex;
  char currentBit, currentByte;
  
  // Loop through the data and extract it from the image
  for(i=0;i<dataSize;i++){
    // Reset the current byte to 0
    currentByte = 0;
    
    // Loop through the bits of the data byte
    for(j=0;j<8;j++){
      // Get the bit index in the image where this bit is hidden
      bitIndex = i*8 + j;
      
      // Get the byte index in the image where the source bit is located
      k = bitIndex/8;
      
      // If the source bit is in the range of image size, extract the current bit from it
      if(k < imageSize){
        // Get the current bit from the image
        int bitShift = 7 - (bitIndex % 8);
        currentBit = (image[k] >> bitShift) & 1;
        
        // Add the current bit to the current byte
        currentByte = (currentByte << 1) | currentBit;
      }
    }
    
    // Add the current byte to the data array
    data[i] = currentByte;
  }
}

int main(){
  FILE* inputFile;
  unsigned char* image;
  char* data;
  int imageSize, dataSize;
  
  // Open the input file
  inputFile = fopen("input.bmp", "rb");
  if(inputFile == NULL){
    printf("Error opening input file");
    return 0;
  }
  
  // Allocate memory for the image buffer
  image = (unsigned char*)malloc(MAX_FILE_SIZE);
  
  // Read the image data from the file
  imageSize = fread(image, 1, MAX_FILE_SIZE, inputFile);
  
  // Close the input file
  fclose(inputFile);
  
  // Allocate memory for the data buffer
  data = (char*)malloc(MAX_FILE_SIZE);
  
  // Hide the message "Hello, world!" in the image
  dataSize = sprintf(data, "Hello, world!");
  hideData(image, imageSize, data, dataSize);
  
  // Extract the hidden data from the image
  extractData(image, imageSize, data, dataSize);
  
  // Print the extracted data
  printf("Extracted data: %s\n", data);
  
  // Free the memory
  free(image);
  free(data);
  
  return 0;
}