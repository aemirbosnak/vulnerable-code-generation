//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t byte;

int main(int argc, char** argv) {
  if (argc != 4) {
    printf("Usage: %s <input image> <output image> <message>\n", argv[0]);
    return 1;
  }

  FILE* input = fopen(argv[1], "rb");
  if (input == NULL) {
    printf("Error opening input image\n");
    return 1;
  }

  FILE* output = fopen(argv[2], "wb");
  if (output == NULL) {
    printf("Error opening output image\n");
    return 1;
  }

  fseek(input, 0, SEEK_END);
  long input_size = ftell(input);
  rewind(input);

  byte* input_data = malloc(input_size);
  if (input_data == NULL) {
    printf("Error allocating memory for input image\n");
    return 1;
  }

  fread(input_data, 1, input_size, input);
  fclose(input);

  long message_size = strlen(argv[3]) + 1;
  if (message_size > input_size) {
    printf("Error: Message too large for image\n");
    return 1;
  }

  for (long i = 0; i < message_size; i++) {
    input_data[i] = (input_data[i] & 0xFE) | ((argv[3][i] >> 7) & 0x01);
    input_data[i + 1] = (input_data[i + 1] & 0xFE) | ((argv[3][i] >> 6) & 0x01);
    input_data[i + 2] = (input_data[i + 2] & 0xFE) | ((argv[3][i] >> 5) & 0x01);
    input_data[i + 3] = (input_data[i + 3] & 0xFE) | ((argv[3][i] >> 4) & 0x01);
    input_data[i + 4] = (input_data[i + 4] & 0xFE) | ((argv[3][i] >> 3) & 0x01);
    input_data[i + 5] = (input_data[i + 5] & 0xFE) | ((argv[3][i] >> 2) & 0x01);
    input_data[i + 6] = (input_data[i + 6] & 0xFE) | ((argv[3][i] >> 1) & 0x01);
    input_data[i + 7] = (input_data[i + 7] & 0xFE) | (argv[3][i] & 0x01);
  }

  fwrite(input_data, 1, input_size, output);
  fclose(output);

  printf("Message successfully embedded in image\n");
  return 0;
}