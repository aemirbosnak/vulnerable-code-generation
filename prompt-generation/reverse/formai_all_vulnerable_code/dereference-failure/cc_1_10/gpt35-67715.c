//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 60
#define MAX_PIXEL_VALUE 255
#define ASCII_RANGE 69

/* Declarations */
void printAsciiArt(unsigned char* img);

/* Main */
int main() {
  /* Read image */
  char fileName[] = "image.pgm";
  FILE* fp;
  fp = fopen(fileName,"rb");
  if (!fp) {
    printf("Error opening file\n");
    return 1;
  }

  char c;
  char buffer[100];

  do {
    fgets(buffer,100,fp); /* Get next line */
    c = buffer[0];
  } while (c == '#');

  /* Check magic number */
  if (c != 'P' || buffer[1] != '5') {
    printf("Invalid image format (must be PGM)\n");
    return 1;
  }

  /* Get image width and height */
  int width, height;
  sscanf(buffer+2, "%d %d", &width, &height);
  fgets(buffer,100,fp); /* Get max pixel value */

  /* Allocate memory (1 byte/pixel) */
  unsigned char* img;
  img = (unsigned char*) malloc(sizeof(unsigned char) * width * height);
  fread(img, sizeof(unsigned char), width*height, fp);

  /* Print ASCII art */
  printAsciiArt(img);

  /* Free memory */
  free(img);

  return 0;
}


/* Functions */

void printAsciiArt(unsigned char* img) {
  /* Character lookup table */
  char ascii[ASCII_RANGE] = {' ', '.', '\'', '`', '^', '\"', ',', ':', ';', 'I', 'l', '!', 'i', '>', '<', '~', '+', '_', '-', '?', ']', '[', '}', '{', '1', ')', '(', '|', '\\', '/', 't', 'f', 'j', 'r', 'x', 'n', 'u', 'v', 'c', 'z', 'X', 'Y', 'U', 'J', 'C', 'L', 'Q', '0', 'O', 'Z', 'm', 'w', 'q', 'p', 'd', 'b', 'k', 'h', 'a', 'o', '*', '#', 'M', '$', '8', '&', 'W', 'B', '@'};

  /* Loop through each pixel */
  int row, col, index;
  for (row = 0; row < HEIGHT; row++) {
    for (col = 0; col < WIDTH; col++) {
      /* Get pixel index */
      index = row * WIDTH + col;

      /* Map pixel value to ASCII character */
      int asciiIndex = img[index] / (MAX_PIXEL_VALUE / ASCII_RANGE);
      printf("%c", ascii[asciiIndex]);
    }
    printf("\n");
  }
}