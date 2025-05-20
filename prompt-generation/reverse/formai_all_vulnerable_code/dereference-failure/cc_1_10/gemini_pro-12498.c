//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef unsigned char byte;

void hide(const char *filename, const char *message) {
  FILE *image = fopen(filename, "rb");
  if (!image) {
    fprintf(stderr, "Error: Unable to open image file.\n");
    exit(EXIT_FAILURE);
  }

  fseek(image, 0, SEEK_END);
  long length = ftell(image);
  fseek(image, 0, SEEK_SET);

  byte *data = malloc(length);
  if (!data) {
    fprintf(stderr, "Error: Unable to allocate memory.\n");
    fclose(image);
    exit(EXIT_FAILURE);
  }

  fread(data, 1, length, image);
  fclose(image);

  // Embed the message length in the least significant bits of the first 32 pixels.
  int message_length = strlen(message);
  for (int i = 0; i < 32; i++) {
    data[i] &= 0xFE;
    data[i] |= message_length & 1;
    message_length >>= 1;
  }

  // Embed the message in the least significant bit of every pixel.
  int message_index = 0;
  for (int i = 32; i < length; i++) {
    data[i] &= 0xFE;
    data[i] |= message[message_index] & 1;
    message_index++;
    if (message_index >= strlen(message)) {
      break;
    }
  }

  // Save the modified image.
  FILE *output = fopen("output.bmp", "wb");
  if (!output) {
    fprintf(stderr, "Error: Unable to open output file.\n");
    free(data);
    exit(EXIT_FAILURE);
  }

  fwrite(data, 1, length, output);
  fclose(output);

  free(data);

  printf("Message successfully hidden in image.\n");
}

void reveal(const char *filename) {
  FILE *image = fopen(filename, "rb");
  if (!image) {
    fprintf(stderr, "Error: Unable to open image file.\n");
    exit(EXIT_FAILURE);
  }

  fseek(image, 0, SEEK_END);
  long length = ftell(image);
  fseek(image, 0, SEEK_SET);

  byte *data = malloc(length);
  if (!data) {
    fprintf(stderr, "Error: Unable to allocate memory.\n");
    fclose(image);
    exit(EXIT_FAILURE);
  }

  fread(data, 1, length, image);
  fclose(image);

  // Extract the message length from the least significant bits of the first 32 pixels.
  int message_length = 0;
  for (int i = 0; i < 32; i++) {
    message_length <<= 1;
    message_length |= data[i] & 1;
  }

  // Extract the message from the least significant bit of every pixel.
  char *message = malloc(message_length + 1);
  if (!message) {
    fprintf(stderr, "Error: Unable to allocate memory.\n");
    free(data);
    exit(EXIT_FAILURE);
  }

  int message_index = 0;
  for (int i = 32; i < length; i++) {
    message[message_index] <<= 1;
    message[message_index] |= data[i] & 1;
    message_index++;
    if (message_index >= message_length) {
      break;
    }
  }

  message[message_length] = '\0';

  printf("Extracted message: %s\n", message);

  free(data);
  free(message);
}

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s [hide|reveal] filename [message]\n", argv[0]);
    return EXIT_FAILURE;
  }

  if (strcmp(argv[1], "hide") == 0) {
    if (argc < 4) {
      fprintf(stderr, "Error: Missing message to hide.\n");
      return EXIT_FAILURE;
    }
    hide(argv[2], argv[3]);
  } else if (strcmp(argv[1], "reveal") == 0) {
    reveal(argv[2]);
  } else {
    fprintf(stderr, "Error: Invalid operation. Use hide or reveal.\n");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}