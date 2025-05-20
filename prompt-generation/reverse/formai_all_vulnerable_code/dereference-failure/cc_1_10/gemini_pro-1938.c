//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 512

int main(int argc, char *argv[]) {
  // Check for correct number of arguments
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <image file> <message file> <output file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Open the image file
  FILE *image_file = fopen(argv[1], "rb");
  if (image_file == NULL) {
    fprintf(stderr, "Error: could not open image file %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  // Get the image size
  int image_size = 0;
  fseek(image_file, 0, SEEK_END);
  image_size = ftell(image_file);
  rewind(image_file);

  // Check if the image is large enough to hold the message
  FILE *message_file = fopen(argv[2], "rb");
  if (message_file == NULL) {
    fprintf(stderr, "Error: could not open message file %s\n", argv[2]);
    return EXIT_FAILURE;
  }

  // Get the message size
  int message_size = 0;
  fseek(message_file, 0, SEEK_END);
  message_size = ftell(message_file);
  rewind(message_file);

  if (message_size > image_size) {
    fprintf(stderr, "Error: message is too large to fit in image\n");
    return EXIT_FAILURE;
  }

  // Read the image data into a buffer
  unsigned char *image_data = malloc(image_size);
  if (image_data == NULL) {
    fprintf(stderr, "Error: could not allocate memory for image data\n");
    return EXIT_FAILURE;
  }

  fread(image_data, 1, image_size, image_file);
  fclose(image_file);

  // Read the message data into a buffer
  unsigned char *message_data = malloc(message_size);
  if (message_data == NULL) {
    fprintf(stderr, "Error: could not allocate memory for message data\n");
    return EXIT_FAILURE;
  }

  fread(message_data, 1, message_size, message_file);
  fclose(message_file);

  // Embed the message in the image
  int message_index = 0;
  for (int i = 0; i < image_size; i++) {
    if (message_index < message_size) {
      image_data[i] = (image_data[i] & 0xF8) | (message_data[message_index] & 0x07);
      message_index++;
    }
  }

  // Write the steganographed image to a file
  FILE *output_file = fopen(argv[3], "wb");
  if (output_file == NULL) {
    fprintf(stderr, "Error: could not open output file %s\n", argv[3]);
    return EXIT_FAILURE;
  }

  fwrite(image_data, 1, image_size, output_file);
  fclose(output_file);

  // Free the buffers
  free(image_data);
  free(message_data);

  return EXIT_SUCCESS;
}