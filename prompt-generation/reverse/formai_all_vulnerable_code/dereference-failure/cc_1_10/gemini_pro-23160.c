//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

typedef unsigned char byte;

byte *image;
int width, height;

char *ascii_chars = " .:-=+*#%@";

void load_image(char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    perror("fopen");
    exit(1);
  }

  // Read the image header
  fread(&width, sizeof(int), 1, fp);
  fread(&height, sizeof(int), 1, fp);

  // Allocate memory for the image data
  image = malloc(width * height * sizeof(byte));
  if (image == NULL) {
    perror("malloc");
    exit(1);
  }

  // Read the image data
  fread(image, sizeof(byte), width * height, fp);

  // Close the file
  fclose(fp);
}

void convert_to_ascii() {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      // Get the brightness of the pixel
      byte brightness = image[y * width + x];

      // Convert the brightness to an ASCII character
      int index = (int)round((double)brightness / 255 * (strlen(ascii_chars) - 1));
      char c = ascii_chars[index];

      // Print the ASCII character
      printf("%c", c);
    }
    printf("\n");
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
    exit(1);
  }

  // Load the image from the file
  load_image(argv[1]);

  // Convert the image to ASCII art
  convert_to_ascii();

  // Free the memory allocated for the image data
  free(image);

  return 0;
}