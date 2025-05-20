//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// This program embeds a secret message into an image file.
// The secret message is stored in the least significant bits of the image's pixels.

// The maximum size of the secret message is 255 characters.
#define MAX_MESSAGE_SIZE 255

// The maximum size of the image file is 10 MB.
#define MAX_IMAGE_SIZE 10 * 1024 * 1024

// The header of the secret message.
#define MESSAGE_HEADER "STEGO"

int main(int argc, char *argv[]) {
  // Check the command line arguments.
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <input image> <output image> <secret message>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Open the input image file.
  FILE *inputImageFile = fopen(argv[1], "rb");
  if (inputImageFile == NULL) {
    perror("fopen() failed");
    return EXIT_FAILURE;
  }

  // Get the size of the input image file.
  fseek(inputImageFile, 0, SEEK_END);
  long inputImageSize = ftell(inputImageFile);
  rewind(inputImageFile);

  // Check the size of the input image file.
  if (inputImageSize > MAX_IMAGE_SIZE) {
    fprintf(stderr, "Error: The input image file is too large.\n");
    return EXIT_FAILURE;
  }

  // Read the input image file into memory.
  uint8_t *inputImage = malloc(inputImageSize);
  if (inputImage == NULL) {
    perror("malloc() failed");
    return EXIT_FAILURE;
  }
  fread(inputImage, 1, inputImageSize, inputImageFile);
  fclose(inputImageFile);

  // Get the size of the secret message.
  int messageSize = strlen(argv[3]);

  // Check the size of the secret message.
  if (messageSize > MAX_MESSAGE_SIZE) {
    fprintf(stderr, "Error: The secret message is too long.\n");
    return EXIT_FAILURE;
  }

  // Embed the secret message header into the input image.
  for (int i = 0; i < 4; i++) {
    inputImage[i] = (inputImage[i] & 0xF0) | (MESSAGE_HEADER[i] & 0x0F);
  }

  // Embed the secret message into the input image.
  for (int i = 0; i < messageSize; i++) {
    inputImage[4 + i] = (inputImage[4 + i] & 0xF0) | (argv[3][i] & 0x0F);
  }

  // Open the output image file.
  FILE *outputImageFile = fopen(argv[2], "wb");
  if (outputImageFile == NULL) {
    perror("fopen() failed");
    return EXIT_FAILURE;
  }

  // Write the output image file.
  fwrite(inputImage, 1, inputImageSize, outputImageFile);
  fclose(outputImageFile);

  // Free the allocated memory.
  free(inputImage);

  return EXIT_SUCCESS;
}