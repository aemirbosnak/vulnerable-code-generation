//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

#define WIDTH 256
#define HEIGHT 256
#define MAX_CHAR 256
#define BITS_PER_PIXEL 8
#define BYTES_PER_PIXEL 1
#define TOTAL_PIXELS (WIDTH * HEIGHT)

typedef unsigned char byte;

int main(int argc, char* argv[]) {
  FILE* input_file, *output_file;
  byte* input_buffer, *output_buffer;
  int i, j, k, l, m, n, x, y, z;
  byte pixel_value, bit_value;
  byte* message_buffer;
  int message_length;

  if (argc!= 3) {
    printf("Usage: %s <input_image> <output_image>\n", argv[0]);
    return 1;
  }

  // Open input and output files
  input_file = fopen(argv[1], "rb");
  output_file = fopen(argv[2], "wb");

  // Allocate memory for input and output buffers
  input_buffer = (byte*) malloc(TOTAL_PIXELS * BITS_PER_PIXEL / 8);
  output_buffer = (byte*) malloc(TOTAL_PIXELS * BITS_PER_PIXEL / 8);

  // Read input image into buffer
  fread(input_buffer, TOTAL_PIXELS * BITS_PER_PIXEL / 8, 1, input_file);

  // Get message from user
  printf("Enter message to hide in image: ");
  scanf("%s", message_buffer);
  message_length = strlen(message_buffer);

  // Hide message in image
  i = 0;
  for (y = 0; y < HEIGHT; y++) {
    for (x = 0; x < WIDTH; x++) {
      pixel_value = input_buffer[i];
      bit_value = (pixel_value >> 1) & 0x01;
      if (message_buffer[i % message_length] == '1') {
        pixel_value |= 0x80;
      } else {
        pixel_value &= 0x7F;
      }
      output_buffer[i] = pixel_value;
      i++;
    }
  }

  // Write output image to file
  fwrite(output_buffer, TOTAL_PIXELS * BITS_PER_PIXEL / 8, 1, output_file);

  // Clean up
  fclose(input_file);
  fclose(output_file);
  free(input_buffer);
  free(output_buffer);

  return 0;
}