//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum width and height of the image
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Define the characters used to represent different shades of gray
#define ASCII_CHARS "#@&%.*?=-+~ "

// Convert an image to ASCII art
void image_to_ascii(char *filename) {
  // Open the image file
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    exit(1);
  }

  // Read the image header
  unsigned char header[18];
  fread(header, 1, 18, file);

  // Check if the file is a valid BMP file
  if (header[0] != 'B' || header[1] != 'M') {
    fprintf(stderr, "Error: %s is not a valid BMP file\n", filename);
    exit(1);
  }

  // Get the width and height of the image
  unsigned int width = *(unsigned int *)&header[18];
  unsigned int height = *(unsigned int *)&header[22];

  // Check if the image is too large
  if (width > MAX_WIDTH || height > MAX_HEIGHT) {
    fprintf(stderr, "Error: %s is too large\n", filename);
    exit(1);
  }

  // Read the image data
  unsigned char *data = malloc(width * height * 3);
  fread(data, 1, width * height * 3, file);

  // Close the image file
  fclose(file);

  // Convert the image data to ASCII art
  char *ascii_art = malloc(width * height + 1);
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      // Calculate the average of the RGB values for the pixel
      unsigned char r = data[(y * width + x) * 3 + 2];
      unsigned char g = data[(y * width + x) * 3 + 1];
      unsigned char b = data[(y * width + x) * 3 + 0];
      unsigned char avg = (r + g + b) / 3;

      // Convert the average value to an ASCII character
      ascii_art[y * width + x] = ASCII_CHARS[avg / 16];
    }
  }

  // Add a newline character to the end of the ASCII art
  ascii_art[width * height] = '\0';

  // Print the ASCII art to the console
  printf("%s", ascii_art);

  // Free the memory allocated for the ASCII art
  free(ascii_art);
  free(data);
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the user has provided an image file name
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
    exit(1);
  }

  // Convert the image file to ASCII art
  image_to_ascii(argv[1]);

  return 0;
}