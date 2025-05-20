//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constants
#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512
#define NUM_CHARACTERS 70

// Function prototypes
char* getPixelValue(unsigned char* image, int x, int y);
void printImage(char* image);

int main() {
  // Read image from file
  FILE *imageFile = fopen("image.jpg", "rb");
  if (imageFile == NULL) {
    printf("Error opening image file.\n");
    return 1;
  }

  unsigned char imageData[IMAGE_WIDTH * IMAGE_HEIGHT * 3];
  fread(imageData, sizeof(unsigned char), IMAGE_WIDTH * IMAGE_HEIGHT * 3, imageFile);
  fclose(imageFile);

  // Convert image to ASCII art
  char* image = malloc(IMAGE_WIDTH * IMAGE_HEIGHT);
  for (int y = 0; y < IMAGE_HEIGHT; y++) {
    for (int x = 0; x < IMAGE_WIDTH; x++) {
      image[y * IMAGE_WIDTH + x] = getPixelValue(imageData, x, y);
    }
  }

  // Print ASCII art image to console
  printImage(image);

  // Free memory
  free(image);

  return 0;
}

// Get the pixel value of the image at the given coordinates
char* getPixelValue(unsigned char* image, int x, int y) {
  // Calculate the average of the RGB values of the pixel
  int r = image[3 * (y * IMAGE_WIDTH + x)];
  int g = image[3 * (y * IMAGE_WIDTH + x) + 1];
  int b = image[3 * (y * IMAGE_WIDTH + x) + 2];
  int average = (r + g + b) / 3;

  // Map the average value to a character
  double brightness = (double)average / 255.0;
  double characterIndex = brightness * (NUM_CHARACTERS - 1);
  char* characters = " .,:;i1tfLCG08@";
  return &characters[(int)characterIndex];
}

// Print the ASCII art image to the console
void printImage(char* image) {
  for (int y = 0; y < IMAGE_HEIGHT; y++) {
    for (int x = 0; x < IMAGE_WIDTH; x++) {
      printf("%c", image[y * IMAGE_WIDTH + x]);
    }
    printf("\n");
  }
}