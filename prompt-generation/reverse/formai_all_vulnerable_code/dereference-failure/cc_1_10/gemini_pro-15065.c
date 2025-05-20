//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define COLUMNS 80
#define ROWS 25

// ASCII characters used for the conversion
char *ascii_chars = " .:-=+*#%@";

// Function to convert an image to ASCII art
void image_to_ascii(char *image_path) {
  // Open the image file
  FILE *image_file = fopen(image_path, "rb");
  if (image_file == NULL) {
    printf("Error opening image file: %s\n", image_path);
    return;
  }

  // Read the image header
  unsigned char header[14];
  fread(header, sizeof(unsigned char), 14, image_file);

  // Check if the image is a valid BMP file
  if (header[0] != 'B' || header[1] != 'M') {
    printf("Error: Invalid BMP file\n");
    fclose(image_file);
    return;
  }

  // Read the image dimensions
  unsigned int width = *(unsigned int *)&header[18];
  unsigned int height = *(unsigned int *)&header[22];

  // Read the image data
  unsigned char *image_data = (unsigned char *)malloc(width * height * 3);
  fread(image_data, sizeof(unsigned char), width * height * 3, image_file);

  // Close the image file
  fclose(image_file);

  // Convert the image data to ASCII art
  char *ascii_art = (char *)malloc(width * height);
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      // Calculate the average color value of the pixel
      unsigned char avg_color = (image_data[(y * width + x) * 3] + image_data[(y * width + x) * 3 + 1] + image_data[(y * width + x) * 3 + 2]) / 3;

      // Find the closest ASCII character to the average color value
      int index = (int)floor((double)avg_color / 255 * (strlen(ascii_chars) - 1));

      // Store the ASCII character in the output buffer
      ascii_art[y * width + x] = ascii_chars[index];
    }
  }

  // Print the ASCII art to the console
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      printf("%c", ascii_art[y * width + x]);
    }
    printf("\n");
  }

  // Free the allocated memory
  free(image_data);
  free(ascii_art);
}

// Main function
int main(int argc, char *argv[]) {
  // Check if a filename was provided
  if (argc < 2) {
    printf("Usage: %s <image_path>\n", argv[0]);
    return 1;
  }

  // Convert the image to ASCII art
  image_to_ascii(argv[1]);

  return 0;
}