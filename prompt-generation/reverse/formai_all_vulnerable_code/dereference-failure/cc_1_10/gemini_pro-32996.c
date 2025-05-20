//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
  uint8_t blue;
  uint8_t green;
  uint8_t red;
  uint8_t alpha;
} pixel_t;

int main() {
  // Open the image file.
  FILE *image_file = fopen("image.png", "rb");
  if (image_file == NULL) {
    printf("Error opening image file.\n");
    return 1;
  }

  // Read the header of the image file.
  uint32_t header[13];
  fread(header, sizeof(uint32_t), 13, image_file);

  // Check if the image file is a PNG file.
  if (header[0] != 0x89504E47 || header[1] != 0x0D0A1A0A) {
    printf("Error: Not a PNG file.\n");
    return 1;
  }

  // Get the width and height of the image.
  uint32_t width = header[6];
  uint32_t height = header[7];

  // Calculate the size of the image data.
  uint32_t image_size = width * height * 4;

  // Read the image data.
  unsigned char *image_data = malloc(image_size);
  fread(image_data, 1, image_size, image_file);

  // Close the image file.
  fclose(image_file);

  // Read the message file.
  FILE *message_file = fopen("message.txt", "rb");
  if (message_file == NULL) {
    printf("Error opening message file.\n");
    return 1;
  }

  // Get the size of the message file.
  fseek(message_file, 0, SEEK_END);
  uint32_t message_size = ftell(message_file);
  fseek(message_file, 0, SEEK_SET);

  // Read the message data.
  unsigned char *message_data = malloc(message_size);
  fread(message_data, 1, message_size, message_file);

  // Close the message file.
  fclose(message_file);

  // Encode the message data into the image data.
  for (uint32_t i = 0; i < message_size; i++) {
    for (uint32_t j = 0; j < 8; j++) {
      // Get the bit from the message data.
      uint8_t bit = (message_data[i] >> j) & 1;

      // Set the bit in the image data.
      pixel_t *pixel = (pixel_t *)&image_data[i * 4];
      if (bit) {
        pixel->blue |= 1;
      } else {
        pixel->blue &= ~1;
      }
    }
  }

  // Open the output image file.
  FILE *output_file = fopen("output.png", "wb");
  if (output_file == NULL) {
    printf("Error opening output image file.\n");
    return 1;
  }

  // Write the header of the output image file.
  fwrite(header, sizeof(uint32_t), 13, output_file);

  // Write the image data to the output image file.
  fwrite(image_data, 1, image_size, output_file);

  // Close the output image file.
  fclose(output_file);

  // Free the memory allocated for the image data and message data.
  free(image_data);
  free(message_data);

  return 0;
}