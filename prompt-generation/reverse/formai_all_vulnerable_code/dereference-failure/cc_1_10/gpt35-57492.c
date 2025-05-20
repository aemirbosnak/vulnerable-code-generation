//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the size of the ASCII art image
#define WIDTH 80
#define HEIGHT 60

// Define the maximum size of the input image
#define MAX_IMAGE_SIZE 1024*1024

// Declare helper function to convert image buffer to ASCII art
char convertPixelToAscii(unsigned char pixelValue);

int main(int argc, char const *argv[]) {

  // Ensure that the user has entered a filename argument
  if (argc < 2) {
    printf("Please enter a filename as an argument.\n");
    printf("Usage: ./ascii_converter [filename]\n");
    return 1;
  }

  // Attempt to open the image file
  FILE* imageFile = fopen(argv[1], "rb");
  if (!imageFile) {
    printf("Could not open file %s\n", argv[1]);
    return 1;
  }

  // Allocate buffer for the input image
  unsigned char* inputImage = (unsigned char*) malloc(MAX_IMAGE_SIZE);
  if (!inputImage) {
    printf("Memory allocation error.\n");
    return 1;
  }

  // Read input image into buffer
  size_t bytes_read = fread(inputImage, sizeof(unsigned char), MAX_IMAGE_SIZE, imageFile);
  if (!bytes_read) {
    printf("Could not read file %s\n", argv[1]);
    free(inputImage);
    return 1;
  }

  // Close the input image file
  fclose(imageFile);

  // Calculate the dimensions of the input image
  unsigned int inputWidth = 0;
  unsigned int inputHeight = 0;
  while (inputImage[inputWidth] != '\n' && inputWidth < MAX_IMAGE_SIZE) {
    inputWidth++;
  }
  inputHeight = bytes_read / inputWidth;

  // Allocate buffer for the output ASCII art image
  char* outputAscii = (char*) malloc(WIDTH * HEIGHT);
  if (!outputAscii) {
    printf("Memory allocation error.\n");
    free(inputImage);
    return 1;
  }

  // Convert input image to ASCII art
  unsigned int x, y;
  for (y=0; y<HEIGHT; y++) {
    for (x=0; x<WIDTH; x++) {
      unsigned int inputX = x * inputWidth / WIDTH;
      unsigned int inputY = y * inputHeight / HEIGHT;
      unsigned char pixelValue = inputImage[inputY * inputWidth + inputX];
      outputAscii[y * WIDTH + x] = convertPixelToAscii(pixelValue);
    }
  }

  // Print the output ASCII art image
  printf("%s", outputAscii);

  // Clean up memory
  free(inputImage);
  free(outputAscii);

  return 0;
}

// Implement helper function to convert image buffer to ASCII art
// Maps pixel intensity values to ASCII characters based on brightness
char convertPixelToAscii(unsigned char pixelValue) {
  // The following characters are arranged from darkest to brightest
  // ASCII characters should be arranged in increasing brightness
  const char* ASCII_CHARS = " .-:=+*#%@";

  // Map the pixel intensity to an ASCII character based on brightness
  unsigned char brightness = pixelValue * strlen(ASCII_CHARS) / 256;
  return ASCII_CHARS[brightness];
}