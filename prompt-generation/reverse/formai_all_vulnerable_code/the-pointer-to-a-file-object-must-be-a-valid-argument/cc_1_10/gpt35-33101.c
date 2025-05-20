//FormAI DATASET v1.0 Category: Image Editor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define image size max width and height
#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

// Define pixel structure
typedef struct Pixel {
  unsigned char red;
  unsigned char green;
  unsigned char blue;
} Pixel;

// Define image structure
typedef struct Image {
  int width;
  int height;
  Pixel pixel[MAX_HEIGHT][MAX_WIDTH];
} Image;

// Define function to read image from file
void read_image(Image *img, char *filename) {
  FILE *file;
  char c;
  int i, j;

  // Open file for reading
  file = fopen(filename, "rb");

  // Read magic number (P6)
  fgets(&c, 2, file);

  // Read width, height and maxvalue
  fscanf(file, "%d %d\n", &img->width, &img->height);

  // Read pixel data
  for(i=0; i<img->height; i++) {
    for(j=0; j<img->width; j++) {
      // Read red, green and blue values
      img->pixel[i][j].red = fgetc(file);
      img->pixel[i][j].green = fgetc(file);
      img->pixel[i][j].blue = fgetc(file);
    }
  }

  // Close file
  fclose(file);
}

// Define function to save image to file
void save_image(Image *img, char *filename) {
  FILE *file;
  int i, j;

  // Open file for writing
  file = fopen(filename, "wb");

  // Write magic number (P6)
  fputs("P6\n", file);

  // Write width, height and maxvalue
  fprintf(file, "%d %d\n", img->width, img->height);

  // Write pixel data
  for(i=0; i<img->height; i++) {
    for(j=0; j<img->width; j++) {
      // Write red, green and blue values
      fputc(img->pixel[i][j].red, file);
      fputc(img->pixel[i][j].green, file);
      fputc(img->pixel[i][j].blue, file);
    }
  }

  // Close file
  fclose(file);
}

// Define function to flip image horizontally
void flip_horizontal(Image *img) {
  Pixel temp;
  int i, j, k;

  for(i=0; i<img->height; i++) {
    for(j=0, k=img->width-1; j<k; j++, k--) {
      // Swap pixel at (i,j) with pixel at (i,k)
      temp = img->pixel[i][j];
      img->pixel[i][j] = img->pixel[i][k];
      img->pixel[i][k] = temp;
    }
  }
}

int main(int argc, char *argv[]) {
  if(argc != 3) {
    printf("Usage: %s [input_file] [output_file]\n", argv[0]);
    return 1;
  }

  Image img;

  // Read image from file
  read_image(&img, argv[1]);

  // Flip image horizontally
  flip_horizontal(&img);

  // Save image to file
  save_image(&img, argv[2]);

  return 0;
}