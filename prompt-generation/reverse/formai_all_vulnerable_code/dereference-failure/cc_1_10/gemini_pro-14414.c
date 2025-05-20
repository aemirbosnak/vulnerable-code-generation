//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert an image to ASCII art
char *imageToASCII(char *filename) {
  // Open the image file
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // Get the image dimensions
  int width, height;
  fread(&width, sizeof(int), 1, fp);
  fread(&height, sizeof(int), 1, fp);

  // Create a 2D array to store the pixel values
  int **pixels = malloc(sizeof(int *) * height);
  for (int i = 0; i < height; i++) {
    pixels[i] = malloc(sizeof(int) * width);
  }

  // Read the pixel values from the file
  fread(pixels[0], sizeof(int), width * height, fp);

  // Close the image file
  fclose(fp);

  // Convert the pixel values to ASCII characters
  char *ascii = malloc(sizeof(char) * width * height);
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int pixel = pixels[i][j];
      ascii[i * width + j] = (pixel < 128) ? '.' : '*';
    }
  }

  // Free the memory allocated for the pixel array
  for (int i = 0; i < height; i++) {
    free(pixels[i]);
  }
  free(pixels);

  // Return the ASCII art
  return ascii;
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the user has provided an image file
  if (argc < 2) {
    printf("Usage: %s <image file>\n", argv[0]);
    return 1;
  }

  // Convert the image to ASCII art
  char *ascii = imageToASCII(argv[1]);

  // Print the ASCII art to the console
  printf("%s", ascii);

  // Free the memory allocated for the ASCII art
  free(ascii);

  return 0;
}