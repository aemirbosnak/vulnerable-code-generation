//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 60

// Define the ASCII characters to be used
char *asciiChars = " .-~:;=+*#%@"
;

// Load the image data from a file
unsigned char *loadImage(char *filename, int *width, int *height) {
  // Open the image file
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    fprintf(stderr, "Error opening image file %s\n", filename);
    return NULL;
  }

  // Read the image header
  unsigned char header[18];
  fread(header, 1, 18, file);

  // Check if the image is a PPM file
  if (header[0] != 'P' || header[1] != '6') {
    fprintf(stderr, "Error: image file is not a PPM file\n");
    fclose(file);
    return NULL;
  }

  // Get the image width and height
  *width = atoi((char *)&header[8]);
  *height = atoi((char *)&header[12]);

  // Allocate memory for the image data
  unsigned char *data = (unsigned char *)malloc(*width * *height * 3);
  if (data == NULL) {
    fprintf(stderr, "Error allocating memory for image data\n");
    fclose(file);
    return NULL;
  }

  // Read the image data
  fread(data, 1, *width * *height * 3, file);

  // Close the image file
  fclose(file);

  return data;
}

// Convert the image data to ASCII art
char *convertImageToAscii(unsigned char *data, int width, int height) {
  // Allocate memory for the ASCII art
  char *asciiArt = (char *)malloc(width * height);
  if (asciiArt == NULL) {
    fprintf(stderr, "Error allocating memory for ASCII art\n");
    return NULL;
  }

  // Convert each pixel to an ASCII character
  for (int i = 0; i < width * height; i++) {
    // Get the pixel color
    unsigned char r = data[i * 3];
    unsigned char g = data[i * 3 + 1];
    unsigned char b = data[i * 3 + 2];

    // Calculate the average color
    unsigned char avg = (r + g + b) / 3;

    // Get the ASCII character that corresponds to the average color
    asciiArt[i] = asciiChars[avg / 16];
  }

  return asciiArt;
}

// Print the ASCII art to the console
void printAsciiArt(char *asciiArt, int width, int height) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", asciiArt[i * width + j]);
    }
    printf("\n");
  }
}

// Free the memory allocated for the image data and the ASCII art
void freeMemory(unsigned char *data, char *asciiArt) {
  free(data);
  free(asciiArt);
}

// Main function
int main(int argc, char **argv) {
  // Check if the user has specified an image file
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
    return 1;
  }

  // Load the image data
  int width, height;
  unsigned char *data = loadImage(argv[1], &width, &height);
  if (data == NULL) {
    return 1;
  }

  // Convert the image data to ASCII art
  char *asciiArt = convertImageToAscii(data, width, height);
  if (asciiArt == NULL) {
    freeMemory(data, NULL);
    return 1;
  }

  // Print the ASCII art to the console
  printAsciiArt(asciiArt, width, height);

  // Free the memory allocated for the image data and the ASCII art
  freeMemory(data, asciiArt);

  return 0;
}