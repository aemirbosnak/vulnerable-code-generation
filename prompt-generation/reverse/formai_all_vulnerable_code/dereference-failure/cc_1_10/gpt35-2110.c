//FormAI DATASET v1.0 Category: Image Editor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIM 10000


/*
  The program takes in a PGM image file and applies a specified transformation to it.
  The user specifies the transformation to be applied in the command line arguments as follows:
  ./image_editor inputFile.pgm outputFile.pgm transformation
  where transformation can take on the values:
  1 - Invert colors
  2 - Flip image horizontally
  3 - Rotate image by 90 degrees clockwise
*/

void invert_colors(unsigned char *pixels, int num_pixels) {
  for (int i = 0; i < num_pixels; i++) {
    pixels[i] = 255 - pixels[i];
  }
}

void flip_image_horizontally(unsigned char *pixels, int width, int height) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width/2; x++) {
      int i = y*width + x;
      int j = y*width + width - x - 1;
      unsigned char temp = pixels[i];
      pixels[i] = pixels[j];
      pixels[j] = temp;
    }
  }
}

void rotate_image_90_clockwise(unsigned char *pixels, int *width, int *height) {
  unsigned char *temp = malloc((*width) * (*height) * sizeof(unsigned char));
  memcpy(temp, pixels, (*width) * (*height) * sizeof(unsigned char));
  // swap dimensions
  int temp_width = *width;
  *width = *height;
  *height = temp_width;
  // copy pixels
  for (int y = 0; y < *height; y++) {
    for (int x = 0; x < *width; x++) {
      int i = y*(*width) + x;
      int j = ((*height) - 1 - x)*(*width) + y;
      pixels[i] = temp[j];
    }
  }
  free(temp);
}

int read_pgm(char *filename, unsigned char **pixels, int *width, int *height) {
  FILE *f = fopen(filename, "rb");
  if (!f) {
    printf("Error opening file %s\n", filename);
    return -1;
  }
  char magic[2];
  fscanf(f, "%2s", magic);
  if (strcmp(magic, "P5") != 0) {
    printf("Error: File %s is not a PGM image file.\n", filename);
    fclose(f);
    return -1;
  }
  fscanf(f, "%d %d", width, height);
  int max_value;
  fscanf(f, "%d", &max_value);
  if (max_value != 255) {
    printf("Warning: Max gray value of %d is not supported.\n", max_value);
  }
  int num_pixels = (*width) * (*height);
  *pixels = malloc(num_pixels * sizeof(unsigned char));
  fread(*pixels, sizeof(unsigned char), num_pixels, f);
  fclose(f);
  return num_pixels;
}

void write_pgm(char *filename, unsigned char *pixels, int width, int height) {
  FILE *f = fopen(filename, "wb");
  if (!f) {
    printf("Error opening file %s\n", filename);
    return;
  }
  fprintf(f, "P5\n%d %d\n255\n", width, height);
  int num_pixels = width*height;
  fwrite(pixels, sizeof(unsigned char), num_pixels, f);
  fclose(f);
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s inputFile.pgm outputFile.pgm transformation\n", argv[0]);
    printf("Transformation options:\n1 - Invert colors\n2 - Flip image horizontally\n3 - Rotate image by 90 degrees clockwise\n");
    return -1;
  }
  char *input_file = argv[1];
  char *output_file = argv[2];
  int transformation = atoi(argv[3]);

  unsigned char *pixels;
  int width, height;
  int num_pixels = read_pgm(input_file, &pixels, &width, &height);
  if (num_pixels <= 0) {
    printf("Error: Could not read image file %s\n", input_file);
    return -1;
  }

  switch (transformation) {
    case 1:
      invert_colors(pixels, num_pixels);
      break;
    case 2:
      flip_image_horizontally(pixels, width, height);
      break;
    case 3:
      rotate_image_90_clockwise(pixels, &width, &height);
      break;
    default:
      printf("Error: Invalid transformation %d\n", transformation);
      free(pixels);
      return -1;
  }

  write_pgm(output_file, pixels, width, height);
  free(pixels);
  return 0;
}