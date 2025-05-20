//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WIDTH 80

// Function to convert image to ASCII art
void convertToAsciiArt(char *img_path, char *ascii_path) {
  int pixel_count = 0, ascii_char_cnt = 0;
  int width, height, pixel, grayscale;
  char ascii_char;
  char *ascii_img;

  FILE *img_file, *ascii_file;

  // Open the image file in read-binary mode
  img_file = fopen(img_path, "rb");

  // Check if file exists and was opened correctly
  if (img_file == NULL) {
    printf("Could not open the image file.\n");
    exit(EXIT_FAILURE);
  }

  // Open the ASCII art file in write mode
  ascii_file = fopen(ascii_path, "w");

  // Check if file exists and was opened correctly
  if (ascii_file == NULL) {
    printf("Could not create the ASCII art file.\n");
    exit(EXIT_FAILURE);
  }

  // Read the header of the image file to get the width and height
  char header[20];
  fgets(header, sizeof(header), img_file);
  sscanf(header, "%d %d", &width, &height);
  printf("Image size: %dx%d\n\n", width, height);

  // Allocate memory for the ASCII art string
  ascii_img = (char *)malloc(width * height * sizeof(char) + height * sizeof(char));

  // Loop through each pixel in the image
  for (int i = 0; i < width * height; i++) {

    // Read the gray scale value of the pixel
    fscanf(img_file, "%d", &pixel);

    // Calculate the "grayscale" of the pixel on a scale of 0 to 1
    // by dividing the gray scale value by the maximum value (255)
    grayscale = round((double)pixel / 255.0);

    // Map the value to an ASCII character using a grayscale to ASCII table
    if (grayscale <= 0.1) {
      ascii_char = ' ';
    } else if (grayscale <= 0.2) {
      ascii_char = '.';
    } else if (grayscale <= 0.3) {
      ascii_char = ':';
    } else if (grayscale <= 0.4) {
      ascii_char = 'o';
    } else if (grayscale <= 0.5) {
      ascii_char = '&';
    } else if (grayscale <= 0.6) {
      ascii_char = '8';
    } else if (grayscale <= 0.7) {
      ascii_char = 'X';
    } else if (grayscale <= 0.8) {
      ascii_char = '%';
    } else if (grayscale <= 0.9) {
      ascii_char = '#';
    } else {
      ascii_char = '@';
    }

    // Add the ASCII character to the ASCII art string
    ascii_img[ascii_char_cnt++] = ascii_char;

    // If the end of the row has been reached, add a newline character
    if ( (++pixel_count) == width ) {
      pixel_count = 0;
      ascii_img[ascii_char_cnt++] = '\n';
    }
  }

  // Write the ASCII art string to the ASCII art file
  fprintf(ascii_file, "%s", ascii_img);

  // Free the memory used by the ASCII art string
  free(ascii_img);

  // Close the image and ASCII art files
  fclose(img_file);
  fclose(ascii_file);
}

int main() {
  // Test the ASCII art conversion on a sample image
  char img_path[] = "sample.jpg";
  char ascii_path[] = "sample_ascii.txt";
  convertToAsciiArt(img_path, ascii_path);

  return 0;
}