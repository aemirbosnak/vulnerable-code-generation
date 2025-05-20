//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Image struct
typedef struct image {
  int width;
  int height;
  unsigned char *data;
} image;

// ASCII art characters
char *ascii_chars = " .,-:;+=#%@";

// Convert an image to ASCII art
char *image_to_ascii(image *img) {
  // Allocate memory for the ASCII art string
  char *ascii_art = (char *)malloc(img->width * img->height + 1);
  if (ascii_art == NULL) {
    perror("malloc");
    exit(1);
  }

  // Convert each pixel to an ASCII character
  int i, j;
  for (i = 0; i < img->height; i++) {
    for (j = 0; j < img->width; j++) {
      // Calculate the brightness of the pixel
      int brightness = img->data[i * img->width + j];

      // Find the corresponding ASCII character
      int index = (int)(brightness / 255.0 * (strlen(ascii_chars) - 1));
      ascii_art[i * img->width + j] = ascii_chars[index];
    }
  }

  // Add a newline character at the end of the string
  ascii_art[img->width * img->height] = '\0';

  // Return the ASCII art string
  return ascii_art;
}

// Load an image from a file
image *load_image(const char *filename) {
  // Open the file
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    perror("fopen");
    exit(1);
  }

  // Read the header
  unsigned char header[18];
  if (fread(header, 18, 1, file) != 1) {
    perror("fread");
    exit(1);
  }

  // Check if the file is a BMP file
  if (header[0] != 'B' || header[1] != 'M') {
    fprintf(stderr, "Error: Not a BMP file\n");
    exit(1);
  }

  // Get the image width and height
  int width = *(int *)&header[18];
  int height = *(int *)&header[22];

  // Allocate memory for the image data
  unsigned char *data = (unsigned char *)malloc(width * height);
  if (data == NULL) {
    perror("malloc");
    exit(1);
  }

  // Read the image data
  if (fread(data, width * height, 1, file) != 1) {
    perror("fread");
    exit(1);
  }

  // Close the file
  fclose(file);

  // Create an image struct
  image *img = (image *)malloc(sizeof(image));
  if (img == NULL) {
    perror("malloc");
    exit(1);
  }

  img->width = width;
  img->height = height;
  img->data = data;

  // Return the image struct
  return img;
}

// Save an image to a file
void save_image(image *img, const char *filename) {
  // Open the file
  FILE *file = fopen(filename, "wb");
  if (file == NULL) {
    perror("fopen");
    exit(1);
  }

  // Write the header
  unsigned char header[18] = {
    'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0, 40, 0, 0, 0};
  *(int *)&header[18] = img->width;
  *(int *)&header[22] = img->height;
  if (fwrite(header, 18, 1, file) != 1) {
    perror("fwrite");
    exit(1);
  }

  // Write the image data
  if (fwrite(img->data, img->width * img->height, 1, file) != 1) {
    perror("fwrite");
    exit(1);
  }

  // Close the file
  fclose(file);
}

// Main function
int main(int argc, char **argv) {
  // Check if the user specified an input and output file
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
    exit(1);
  }

  // Load the input image
  image *img = load_image(argv[1]);

  // Convert the image to ASCII art
  char *ascii_art = image_to_ascii(img);

  // Save the ASCII art to the output file
  save_image(ascii_art, argv[2]);

  // Free the memory allocated for the image and ASCII art string
  free(img->data);
  free(img);
  free(ascii_art);

  return 0;
}