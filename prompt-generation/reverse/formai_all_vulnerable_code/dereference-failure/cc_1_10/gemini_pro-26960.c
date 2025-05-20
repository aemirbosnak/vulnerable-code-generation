//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to convert an image to ASCII art
void image_to_ascii(char *filename) {
  // Open the image file
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    perror("Error opening file");
    return;
  }

  // Read the image header
  unsigned char header[14];
  fread(header, sizeof(header), 1, fp);

  // Check if the image is a BMP file
  if (header[0] != 'B' || header[1] != 'M') {
    fprintf(stderr, "Error: not a BMP file\n");
    fclose(fp);
    return;
  }

  // Get the image dimensions
  unsigned int width = *(unsigned int *)&header[18];
  unsigned int height = *(unsigned int *)&header[22];

  // Allocate memory for the image data
  unsigned char *data = malloc(width * height * 3);
  if (data == NULL) {
    fprintf(stderr, "Error allocating memory\n");
    fclose(fp);
    return;
  }

  // Read the image data
  fread(data, width * height * 3, 1, fp);

  // Close the image file
  fclose(fp);

  // Convert the image data to ASCII art
  char *ascii_art = malloc(width * height + 1);
  if (ascii_art == NULL) {
    fprintf(stderr, "Error allocating memory\n");
    free(data);
    return;
  }

  for (int i = 0; i < width * height; i++) {
    // Get the RGB values of the pixel
    unsigned char r = data[i * 3];
    unsigned char g = data[i * 3 + 1];
    unsigned char b = data[i * 3 + 2];

    // Convert the RGB values to a grayscale value
    double grayscale = 0.2126 * r + 0.7152 * g + 0.0722 * b;

    // Convert the grayscale value to an ASCII character
    char c;
    if (grayscale < 32) {
      c = '@';
    } else if (grayscale < 64) {
      c = '%';
    } else if (grayscale < 96) {
      c = '#';
    } else if (grayscale < 128) {
      c = '+';
    } else if (grayscale < 160) {
      c = '=';
    } else if (grayscale < 192) {
      c = '-';
    } else if (grayscale < 224) {
      c = ':';
    } else {
      c = ' ';
    }

    // Add the ASCII character to the ASCII art string
    ascii_art[i] = c;
  }

  // Add a newline character to the end of the ASCII art string
  ascii_art[width * height] = '\0';

  // Print the ASCII art to the console
  printf("%s", ascii_art);

  // Free the memory allocated for the image data and the ASCII art string
  free(data);
  free(ascii_art);
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the user has provided an image filename
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <image filename>\n", argv[0]);
    return 1;
  }

  // Convert the image to ASCII art
  image_to_ascii(argv[1]);

  return 0;
}