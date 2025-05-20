//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: creative
/*
  This program converts an input image to ASCII art,
  displaying the output in the console.
  
  The image must be a .pgm format file. The program
  reads in the image pixel values and converts them
  to ASCII characters based on their intensity.
  
  Author: Chatbot
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 1000

int main(int argc, char *argv[]) {

  // Check if image file path is provided
  if (argc < 2) {
    printf("Error: Image file path not provided.\n");
    exit(1);
  }

  // Open image file
  FILE *fp = fopen(argv[1], "r");
  if (!fp) {
    printf("Error: Could not open image file.\n");
    exit(1);
  }

  // Read image file header
  char buff[MAX_IMAGE_SIZE];
  fgets(buff, sizeof(buff), fp);
  fgets(buff, sizeof(buff), fp);
  fgets(buff, sizeof(buff), fp);
  fgets(buff, sizeof(buff), fp);
  int width, height;
  fscanf(fp, "%d %d", &width, &height);
  fgets(buff, sizeof(buff), fp);

  // Create 2D array to store pixel values
  int **pixels = (int **) malloc(height*sizeof(int *));
  for (int i=0; i<height; i++) {
    pixels[i] = (int *) malloc(width*sizeof(int));
  }

  // Store pixel values in array
  for (int i=0; i<height; i++) {
    for (int j=0; j<width; j++) {
      fscanf(fp, "%d", &pixels[i][j]);
    }
  }

  // Close image file
  fclose(fp);

  // Define ASCII characters for each pixel intensity range
  char ascii_chars[] = " .,-~:;=!*#$@";
  int num_ascii_chars = sizeof(ascii_chars)/sizeof(char);
  int intensity_range_size = 255/(num_ascii_chars-1);

  // Generate ASCII art
  printf("\n");
  for (int i=0; i<height; i++) {
    for (int j=0; j<width; j++) {
      int intensity = pixels[i][j]/intensity_range_size;
      if (intensity >= num_ascii_chars) {
        intensity = num_ascii_chars - 1;
      }
      printf("%c", ascii_chars[intensity]);
    }
    printf("\n");
  }

  // Free memory allocated for pixel array
  for (int i=0; i<height; i++) {
    free(pixels[i]);
  }
  free(pixels);

  return 0;
}