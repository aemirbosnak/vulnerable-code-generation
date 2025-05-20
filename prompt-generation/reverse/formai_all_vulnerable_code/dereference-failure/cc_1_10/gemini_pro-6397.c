//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define WIDTH 1024
#define HEIGHT 1024

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <input_image> <output_image>\n", argv[0]);
    return 1;
  }

  FILE *input_file = fopen(argv[1], "rb");
  if (input_file == NULL) {
    printf("Error opening input file: %s\n", argv[1]);
    return 1;
  }

  FILE *output_file = fopen(argv[2], "wb");
  if (output_file == NULL) {
    printf("Error opening output file: %s\n", argv[2]);
    return 1;
  }

  uint8_t header[54];
  fread(header, 54, 1, input_file);
  fwrite(header, 54, 1, output_file);

  uint8_t *image_data = (uint8_t *)malloc(WIDTH * HEIGHT * 3);
  fread(image_data, WIDTH * HEIGHT * 3, 1, input_file);

  uint8_t *message = (uint8_t *)malloc(strlen(argv[3]));
  strcpy(message, argv[3]);

  int message_length = strlen(argv[3]);

  for (int i = 0; i < message_length; i++) {
    for (int j = 0; j < 8; j++) {
      int bit = (message[i] >> j) & 1;
      image_data[i * 8 + j] = (image_data[i * 8 + j] & ~1) | bit;
    }
  }

  fwrite(image_data, WIDTH * HEIGHT * 3, 1, output_file);

  free(image_data);
  free(message);
  fclose(input_file);
  fclose(output_file);

  return 0;
}