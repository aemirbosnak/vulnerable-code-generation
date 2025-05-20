//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80 // max width of ASCII art
#define HEIGHT 50 // max height of ASCII art
#define MAX_PIXEL 255 // max possible pixel value

// function to convert image to ASCII art
void convertImageToASCII(char* filename) {
  FILE *fp = fopen(filename, "rb");

  if(fp == NULL) {
    printf("Error: Unable to open file.\n");
    exit(1);
  }

  unsigned char buf[54];
  fread(buf, sizeof(unsigned char), 54, fp);

  // get image dimensions
  int width = *(int*)&buf[18];
  int height = *(int*)&buf[22];

  // calculate padding for each row of pixels
  int padding = (4 - (width * 3) % 4) % 4;

  unsigned char img[height][width][3]; // 3D array to hold RGB values

  // read image data into array
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      fread(img[i][j], sizeof(unsigned char), 3, fp);
    }
    fseek(fp, padding, SEEK_CUR); // skip padding bytes
  }

  fclose(fp);

  // convert RGB values to grayscale values
  int grayscale[height][width];
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      grayscale[i][j] = 0.299 * img[i][j][0] + 0.587 * img[i][j][1] + 0.114 * img[i][j][2];
    }
  }

  // calculate scaling factor to map grayscale values to ASCII symbols
  float scale = (float)MAX_PIXEL / 256;

  // ASCII symbols to use for the conversion
  char ascii[] = {' ', '.', '*', ':', 'o', '&', '8', '#', '@'};

  // convert grayscale values to ASCII symbols
  char asciiArt[HEIGHT][WIDTH];
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      int index = (int)(grayscale[i][j] / scale);
      asciiArt[i][j] = ascii[index];
    }
  }

  // print ASCII art to console
  for(int i = 0; i < HEIGHT; i++) {
    for(int j = 0; j < WIDTH; j++) {
      printf("%c", asciiArt[i][j]);
    }
    printf("\n");
  }
}

int main(int argc, char* argv[]) {
  if(argc != 2) {
    printf("Error: Invalid arguments.\n");
    printf("Usage: ./imageToASCII <filename>\n");
    exit(1);
  }

  convertImageToASCII(argv[1]);

  return 0;
}