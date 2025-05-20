//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum image size
#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

// Define the ASCII characters used for the image
char ascii_chars[] = " .,-~:;=*#%@";

// Convert an image to ASCII art
void image_to_ascii(char *image_file, char *output_file) {
  // Open the image file
  FILE *image = fopen(image_file, "rb");
  if (image == NULL) {
    perror("Error opening image file");
    return;
  }

  // Read the image header
  unsigned int width, height;
  fread(&width, sizeof(unsigned int), 1, image);
  fread(&height, sizeof(unsigned int), 1, image);

  // Allocate memory for the image data
  unsigned char *data = malloc(width * height * 3);
  if (data == NULL) {
    perror("Error allocating memory for image data");
    fclose(image);
    return;
  }

  // Read the image data
  fread(data, width * height * 3, 1, image);

  // Close the image file
  fclose(image);

  // Open the output file
  FILE *output = fopen(output_file, "w");
  if (output == NULL) {
    perror("Error opening output file");
    free(data);
    return;
  }

  // Convert the image data to ASCII art
  for (unsigned int y = 0; y < height; y++) {
    for (unsigned int x = 0; x < width; x++) {
      // Get the RGB values of the pixel
      unsigned char r = data[(y * width + x) * 3 + 0];
      unsigned char g = data[(y * width + x) * 3 + 1];
      unsigned char b = data[(y * width + x) * 3 + 2];

      // Calculate the average RGB value
      unsigned char avg = (r + g + b) / 3;

      // Find the closest ASCII character
      char ascii_char = ascii_chars[avg / 32];

      // Write the ASCII character to the output file
      fprintf(output, "%c", ascii_char);
    }

    // Write a newline character to the output file
    fprintf(output, "\n");
  }

  // Close the output file
  fclose(output);

  // Free the memory allocated for the image data
  free(data);
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the user has provided enough arguments
  if (argc < 3) {
    printf("Usage: %s <image_file> <output_file>\n", argv[0]);
    return 1;
  }

  // Convert the image to ASCII art
  image_to_ascii(argv[1], argv[2]);

  // Return 0 to indicate success
  return 0;
}