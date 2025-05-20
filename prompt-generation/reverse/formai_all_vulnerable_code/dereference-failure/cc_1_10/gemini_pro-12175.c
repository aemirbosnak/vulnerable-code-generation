//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: calm
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUM_SYMBOLS 10

char* symbols = " .,-=+*#%@";

int main(int argc, char** argv) {
  // Check if the user has provided an image file name
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
    return 1;
  }

  // Open the image file
  FILE* image_file = fopen(argv[1], "rb");
  if (!image_file) {
    fprintf(stderr, "Could not open image file '%s'\n", argv[1]);
    return 1;
  }

  // Read the image header
  unsigned int width, height;
  fread(&width, sizeof(unsigned int), 1, image_file);
  fread(&height, sizeof(unsigned int), 1, image_file);

  // Allocate memory for the image data
  unsigned char* image_data = malloc(width * height * 3);
  if (!image_data) {
    fprintf(stderr, "Could not allocate memory for image data\n");
    fclose(image_file);
    return 1;
  }

  // Read the image data
  fread(image_data, sizeof(unsigned char), width * height * 3, image_file);
  fclose(image_file);

  // Convert the image data to ASCII art
  char* ascii_art = malloc(width * height + 1);
  if (!ascii_art) {
    fprintf(stderr, "Could not allocate memory for ASCII art\n");
    free(image_data);
    return 1;
  }

  int i, j, k;
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      // Calculate the average color value
      int color_value = 0;
      for (k = 0; k < 3; k++) {
        color_value += image_data[(i * width + j) * 3 + k];
      }
      color_value /= 3;

      // Convert the average color value to an ASCII symbol
      char symbol = symbols[color_value * NUM_SYMBOLS / 256];

      // Append the symbol to the ASCII art string
      ascii_art[i * width + j] = symbol;
    }
  }

  // Add a newline character to the end of the ASCII art string
  ascii_art[width * height] = '\n';

  // Print the ASCII art to the console
  printf("%s", ascii_art);

  // Free the allocated memory
  free(image_data);
  free(ascii_art);

  return 0;
}