//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define WIDTH 512
#define HEIGHT 512

typedef struct {
  uint8_t r, g, b, a;
} pixel;

pixel image[WIDTH * HEIGHT];

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s <input image> <output image>\n", argv[0]);
    return 1;
  }

  FILE *input = fopen(argv[1], "rb");
  if (input == NULL) {
    printf("Error opening input image\n");
    return 1;
  }

  FILE *output = fopen(argv[2], "wb");
  if (output == NULL) {
    printf("Error opening output image\n");
    return 1;
  }

  fread(image, sizeof(pixel), WIDTH * HEIGHT, input);

  // Hide a secret message in the least significant bits of the blue channel
  char *message = "Hello, world!";
  int message_length = strlen(message);
  int message_index = 0;
  for (int i = 0; i < WIDTH * HEIGHT; i++) {
    if (message_index < message_length) {
      image[i].b &= 0xF8;
      image[i].b |= message[message_index] & 0x07;
      message_index++;
    }
  }

  // Write the modified image to the output file
  fwrite(image, sizeof(pixel), WIDTH * HEIGHT, output);

  fclose(input);
  fclose(output);

  printf("Message hidden in image!\n");
  return 0;
}