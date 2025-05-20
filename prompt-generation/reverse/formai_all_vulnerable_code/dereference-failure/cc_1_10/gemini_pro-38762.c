//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum width of the ASCII art
#define MAX_WIDTH 80

// Define the characters to use for the ASCII art
char *chars = " .,;:=+-*#%@";

// Convert an image to ASCII art
void image_to_ascii(char *filename) {
  // Open the image file
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Read the image header
  unsigned int width, height;
  fread(&width, sizeof(unsigned int), 1, fp);
  fread(&height, sizeof(unsigned int), 1, fp);

  // Check if the image is too wide
  if (width > MAX_WIDTH) {
    printf("Error: Image is too wide. Maximum width is %d.\n", MAX_WIDTH);
    exit(1);
  }

  // Create a buffer to store the image data
  unsigned char *data = malloc(width * height * 3);
  fread(data, sizeof(unsigned char), width * height * 3, fp);

  // Convert the image data to ASCII art
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      // Calculate the average intensity of the pixel
      int intensity = (data[(y * width + x) * 3] + data[(y * width + x) * 3 + 1] + data[(y * width + x) * 3 + 2]) / 3;

      // Convert the intensity to a character
      char c = chars[intensity / 25];

      // Print the character
      printf("%c", c);
    }

    // Newline
    printf("\n");
  }

  // Free the memory
  free(data);
  fclose(fp);
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the user specified an image file
  if (argc < 2) {
    printf("Usage: %s <image file>\n", argv[0]);
    exit(1);
  }

  // Convert the image to ASCII art
  image_to_ascii(argv[1]);

  return 0;
}