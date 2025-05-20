//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum image size
#define MAX_IMAGE_SIZE 1024

// Define the number of ASCII characters to use
#define NUM_ASCII_CHARS 128

// Define the minimum ASCII value
#define MIN_ASCII_VALUE 32

// Define the maximum ASCII value
#define MAX_ASCII_VALUE 126

// Define the ASCII character map
const char *ASCII_MAP = "`^\",:;Il!i~+_-?][}{1)(|\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";

// Function to convert an image to ASCII art
void image_to_ascii_art(const char *filename) {
  // Open the image file
  FILE *image_file = fopen(filename, "rb");
  if (image_file == NULL) {
    fprintf(stderr, "Error opening image file: %s\n", filename);
    exit(1);
  }

  // Read the image header
  unsigned char header[14];
  if (fread(header, sizeof(unsigned char), 14, image_file) != 14) {
    fprintf(stderr, "Error reading image header: %s\n", filename);
    exit(1);
  }

  // Check if the image is a valid BMP file
  if (header[0] != 'B' || header[1] != 'M') {
    fprintf(stderr, "Error: %s is not a valid BMP file\n", filename);
    exit(1);
  }

  // Get the image dimensions
  int width = *(int *)&header[18];
  int height = *(int *)&header[22];

  // Check if the image is too large
  if (width > MAX_IMAGE_SIZE || height > MAX_IMAGE_SIZE) {
    fprintf(stderr, "Error: Image is too large: %dx%d\n", width, height);
    exit(1);
  }

  // Allocate memory for the image data
  unsigned char *image_data = (unsigned char *)malloc(width * height * 3);
  if (image_data == NULL) {
    fprintf(stderr, "Error allocating memory for image data\n");
    exit(1);
  }

  // Read the image data
  if (fread(image_data, sizeof(unsigned char), width * height * 3, image_file) != width * height * 3) {
    fprintf(stderr, "Error reading image data: %s\n", filename);
    exit(1);
  }

  // Close the image file
  fclose(image_file);

  // Convert the image data to ASCII art
  char *ascii_art = (char *)malloc(width * height + 1);
  if (ascii_art == NULL) {
    fprintf(stderr, "Error allocating memory for ASCII art\n");
    exit(1);
  }

  for (int i = 0; i < width * height; i++) {
    // Get the average of the RGB values
    unsigned char avg = (image_data[i * 3] + image_data[i * 3 + 1] + image_data[i * 3 + 2]) / 3;

    // Map the average value to an ASCII character
    char c = ASCII_MAP[avg - MIN_ASCII_VALUE];

    // Store the ASCII character in the ASCII art string
    ascii_art[i] = c;
  }

  // Add a newline character to the end of the ASCII art string
  ascii_art[width * height] = '\0';

  // Print the ASCII art
  printf("%s\n", ascii_art);

  // Free the memory allocated for the image data and the ASCII art string
  free(image_data);
  free(ascii_art);
}

// Main function
int main(int argc, char *argv[]) {
  // Check if a filename was specified
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // Convert the image to ASCII art
  image_to_ascii_art(argv[1]);

  return 0;
}