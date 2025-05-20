//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

unsigned char *image;
unsigned char *message;

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <image> <message>\n", argv[0]);
    return 1;
  }

  // Read the image file
  FILE *image_file = fopen(argv[1], "rb");
  if (image_file == NULL) {
    printf("Error opening image file %s\n", argv[1]);
    return 1;
  }

  fseek(image_file, 0, SEEK_END);
  long image_size = ftell(image_file);
  rewind(image_file);

  image = malloc(image_size);
  if (image == NULL) {
    printf("Error allocating memory for image\n");
    return 1;
  }

  fread(image, image_size, 1, image_file);
  fclose(image_file);

  // Read the message file
  FILE *message_file = fopen(argv[2], "rb");
  if (message_file == NULL) {
    printf("Error opening message file %s\n", argv[2]);
    return 1;
  }

  fseek(message_file, 0, SEEK_END);
  long message_size = ftell(message_file);
  rewind(message_file);

  message = malloc(message_size);
  if (message == NULL) {
    printf("Error allocating memory for message\n");
    return 1;
  }

  fread(message, message_size, 1, message_file);
  fclose(message_file);

  // Embed the message in the image
  int i = 0;
  int j = 0;
  while (i < message_size) {
    // Get the next byte of the message
    unsigned char byte = message[i];

    // Embed the byte in the image
    for (int k = 0; k < 8; k++) {
      // Get the bit from the byte
      unsigned char bit = (byte >> k) & 1;

      // Embed the bit in the image
      image[j++] |= bit;
    }

    i++;
  }

  // Write the image file
  image_file = fopen(argv[1], "wb");
  if (image_file == NULL) {
    printf("Error opening image file %s\n", argv[1]);
    return 1;
  }

  fwrite(image, image_size, 1, image_file);
  fclose(image_file);

  printf("Message embedded in image\n");

  return 0;
}