//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct {
  unsigned char r;
  unsigned char g;
  unsigned char b;
} pixel;

int main()
{
  // Open the input image file
  FILE *input_file = fopen("input.jpg", "rb");
  if (input_file == NULL)
  {
    printf("Error opening input file.\n");
    return EXIT_FAILURE;
  }

  // Determine the size of the input image
  fseek(input_file, 0L, SEEK_END);
  long input_size = ftell(input_file);
  fseek(input_file, 0L, SEEK_SET);

  // Read the input image into memory
  unsigned char *input_buffer = malloc(input_size);
  if (input_buffer == NULL)
  {
    printf("Error allocating memory for input buffer.\n");
    fclose(input_file);
    return EXIT_FAILURE;
  }
  fread(input_buffer, 1, input_size, input_file);
  fclose(input_file);

  // Extract the header from the input image
  unsigned char header[54];
  memcpy(header, input_buffer, 54);

  // Calculate the number of pixels in the input image
  int width = *(int *)(header + 18);
  int height = *(int *)(header + 22);
  int num_pixels = width * height;

  // Parse the message from the command line
  char *message = NULL;
  size_t message_size = 0;
  if (getline(&message, &message_size, stdin) == -1)
  {
    printf("Error reading message from stdin.\n");
    free(input_buffer);
    return EXIT_FAILURE;
  }

  // Embed the message in the input image
  for (int i = 0; i < strlen(message); i++)
  {
    // Convert the message character to its ASCII value
    unsigned char character = message[i];

    // Embed the ASCII value in the least significant bits of the pixel colors
    for (int j = 0; j < 8; j++)
    {
      // Extract the least significant bit of the character
      unsigned char bit = character & 1;

      // Set the least significant bit of the pixel color to the extracted bit
      int pixel_index = i * 8 + j;
      input_buffer[54 + pixel_index] = (input_buffer[54 + pixel_index] & 0xFE) | bit;

      // Shift the character to the right by one bit
      character >>= 1;
    }
  }

  // Open the output image file
  FILE *output_file = fopen("output.jpg", "wb");
  if (output_file == NULL)
  {
    printf("Error opening output file.\n");
    free(input_buffer);
    free(message);
    return EXIT_FAILURE;
  }

  // Write the header to the output image file
  fwrite(header, 1, 54, output_file);

  // Write the modified pixels to the output image file
  fwrite(input_buffer + 54, 1, num_pixels * 3, output_file);
  fclose(output_file);

  // Free the allocated memory
  free(input_buffer);
  free(message);

  return EXIT_SUCCESS;
}