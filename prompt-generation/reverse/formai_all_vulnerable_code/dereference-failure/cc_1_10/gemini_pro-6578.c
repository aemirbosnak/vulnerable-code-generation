//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the image and the message
#define MAX_IMAGE_SIZE 1000000
#define MAX_MESSAGE_SIZE 1000

// Define the bitmask for extracting the least significant bit
#define LSB_MASK 0x01

// Main function
int main(int argc, char *argv[]) {
  // Check if the command line arguments are valid
  if (argc < 4) {
    printf("Usage: %s <input image> <output image> <message>\n", argv[0]);
    return 1;
  }

  // Open the input and output image files
  FILE *input_image_file = fopen(argv[1], "rb");
  if (input_image_file == NULL) {
    printf("Error opening input image file\n");
    return 1;
  }

  FILE *output_image_file = fopen(argv[2], "wb");
  if (output_image_file == NULL) {
    printf("Error opening output image file\n");
    return 1;
  }

  // Read the input image into memory
  unsigned char *input_image_data = malloc(MAX_IMAGE_SIZE);
  if (input_image_data == NULL) {
    printf("Error allocating memory for input image data\n");
    return 1;
  }

  size_t input_image_size = fread(input_image_data, 1, MAX_IMAGE_SIZE, input_image_file);
  if (input_image_size == 0) {
    printf("Error reading input image data\n");
    return 1;
  }

  // Convert the message to a bitstream
  unsigned char *message_bitstream = malloc(MAX_MESSAGE_SIZE);
  if (message_bitstream == NULL) {
    printf("Error allocating memory for message bitstream\n");
    return 1;
  }

  size_t message_size = strlen(argv[3]);
  for (size_t i = 0; i < message_size; i++) {
    for (int j = 0; j < 8; j++) {
      message_bitstream[i * 8 + j] = (argv[3][i] >> j) & LSB_MASK;
    }
  }

  // Embed the message bitstream in the least significant bits of the image data
  for (size_t i = 0; i < input_image_size; i++) {
    input_image_data[i] = (input_image_data[i] & ~LSB_MASK) | message_bitstream[i];
  }

  // Write the output image to disk
  fwrite(input_image_data, 1, input_image_size, output_image_file);

  // Free the allocated memory
  free(input_image_data);
  free(message_bitstream);

  // Close the input and output image files
  fclose(input_image_file);
  fclose(output_image_file);

  // Return success
  return 0;
}