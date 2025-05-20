//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  unsigned char r, g, b;
} pixel;

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <input_image> <output_image> <message>\n", argv[0]);
    return 1;
  }

  FILE *input_file = fopen(argv[1], "rb");
  if (input_file == NULL) {
    printf("Error opening input image file.\n");
    return 1;
  }

  FILE *output_file = fopen(argv[2], "wb");
  if (output_file == NULL) {
    printf("Error opening output image file.\n");
    return 1;
  }

  fseek(input_file, 0, SEEK_END);
  long image_size = ftell(input_file);
  rewind(input_file);

  unsigned char *image_data = malloc(image_size);
  if (image_data == NULL) {
    printf("Error allocating memory for image data.\n");
    return 1;
  }

  fread(image_data, 1, image_size, input_file);
  fclose(input_file);

  int message_length = strlen(argv[3]);
  if (message_length > (image_size / 3 - 1)) {
    printf("Message too long.\n");
    return 1;
  }

  int message_index = 0;
  for (int i = 0; i < image_size; i += 3) {
    if (message_index < message_length) {
      image_data[i] = (image_data[i] & 0xF8) | ((argv[3][message_index] >> 5) & 0x07);
      image_data[i + 1] = (image_data[i + 1] & 0xFC) | ((argv[3][message_index] >> 2) & 0x03);
      image_data[i + 2] = (image_data[i + 2] & 0xF0) | (argv[3][message_index] & 0x03);
      message_index++;
    }
  }

  fwrite(image_data, 1, image_size, output_file);
  fclose(output_file);

  free(image_data);

  printf("Message successfully embedded in image.\n");
  return 0;
}