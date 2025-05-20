//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <png.h>

#define WIDTH 512
#define HEIGHT 512

// The surrealist function that will hide the data in the image.
void hideData(png_bytep image, char *data, int dataSize) {
  int i, j, k;
  for (i = 0; i < WIDTH; i++) {
    for (j = 0; j < HEIGHT; j++) {
      for (k = 0; k < 3; k++) { // RGB channels

        // The surrealist logic that determines how to hide the data.
        image[j * WIDTH * 3 + i * 3 + k] ^= data[j * WIDTH * 3 + i * 3 + k];
      }
    }
  }
}

// The surrealist function that will retrieve the data from the image.
void retrieveData(png_bytep image, char *data, int dataSize) {
  int i, j, k;
  for (i = 0; i < WIDTH; i++) {
    for (j = 0; j < HEIGHT; j++) {
      for (k = 0; k < 3; k++) { // RGB channels

        // The surrealist logic that determines how to retrieve the data.
        data[j * WIDTH * 3 + i * 3 + k] ^= image[j * WIDTH * 3 + i * 3 + k];
      }
    }
  }
}

// The main function that drives the surrealist image steganography program.
int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <input_image> <output_image> <data_file>\n", argv[0]);
    return 1;
  }

  // Open the input image file.
  FILE *input_file = fopen(argv[1], "rb");
  if (input_file == NULL) {
    fprintf(stderr, "Error opening input image file.\n");
    return 1;
  }

  // Read the input image into a buffer.
  png_bytep image;
  png_size_t image_size;
  fseek(input_file, 0, SEEK_END);
  image_size = ftell(input_file);
  fseek(input_file, 0, SEEK_SET);
  image = malloc(image_size);
  fread(image, 1, image_size, input_file);
  fclose(input_file);

  // Open the data file.
  FILE *data_file = fopen(argv[3], "rb");
  if (data_file == NULL) {
    fprintf(stderr, "Error opening data file.\n");
    return 1;
  }

  // Read the data into a buffer.
  char *data;
  int data_size;
  fseek(data_file, 0, SEEK_END);
  data_size = ftell(data_file);
  fseek(data_file, 0, SEEK_SET);
  data = malloc(data_size);
  fread(data, 1, data_size, data_file);
  fclose(data_file);

  // Hide the data in the image.
  hideData(image, data, data_size);

  // Open the output image file.
  FILE *output_file = fopen(argv[2], "wb");
  if (output_file == NULL) {
    fprintf(stderr, "Error opening output image file.\n");
    return 1;
  }

  // Write the image to the output file.
  fwrite(image, 1, image_size, output_file);
  fclose(output_file);

  // Free the image and data buffers.
  free(image);
  free(data);

  return 0;
}