//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define the maximum width and height of the image
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Define the character map
char *character_map = ".#**()-+=<>:?abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Read an image from a file
void read_image(char *filename, int *width, int *height, unsigned char *data) {
  // Open the file
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Read the header
  unsigned char header[18];
  if (fread(header, 1, 18, fp) != 18) {
    perror("Error reading header");
    exit(1);
  }

  // Check if the file is a BMP image
  if (header[0] != 'B' || header[1] != 'M') {
    fprintf(stderr, "Error: File is not a BMP image\n");
    exit(1);
  }

  // Get the width and height of the image
  *width = header[18] + (header[19] << 8);
  *height = header[22] + (header[23] << 8);

  // Check if the image is too large
  if (*width > MAX_WIDTH || *height > MAX_HEIGHT) {
    fprintf(stderr, "Error: Image is too large\n");
    exit(1);
  }

  // Get the data from the image
  if (fread(data, 1, *width * *height, fp) != *width * *height) {
    perror("Error reading data");
    exit(1);
  }

  // Close the file
  fclose(fp);
}

// Convert an image to ASCII art
void convert_image(int width, int height, unsigned char *data) {
  // Create a new image
  char *image = malloc(width * height);
  if (image == NULL) {
    perror("Error allocating memory");
    exit(1);
  }

  // Convert each pixel to a character
  for (int i = 0; i < width * height; i++) {
    image[i] = character_map[data[i] / 16];
  }

  // Print the image to the console
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", image[i * width + j]);
    }
    printf("\n");
  }

  // Free the memory
  free(image);
}

// Main function
int main(int argc, char **argv) {
  // Check if the user has provided a filename
  if (argc != 2) {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    exit(1);
  }

  // Read the image from a file
  int width, height;
  unsigned char *data = malloc(MAX_WIDTH * MAX_HEIGHT);
  if (data == NULL) {
    perror("Error allocating memory");
    exit(1);
  }
  read_image(argv[1], &width, &height, data);

  // Convert the image to ASCII art
  convert_image(width, height, data);

  // Free the memory
  free(data);

  return 0;
}