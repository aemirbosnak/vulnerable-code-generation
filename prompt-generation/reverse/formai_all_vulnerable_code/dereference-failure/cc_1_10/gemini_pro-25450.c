//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the image and the message
#define MAX_IMAGE_SIZE 1000000
#define MAX_MESSAGE_SIZE 1000

// Define the bit manipulation functions
unsigned char get_bit(unsigned char byte, int bit_position);
void set_bit(unsigned char *byte, int bit_position, int bit_value);

// Define the main function
int main() {
  // Get the input image
  FILE *image_file = fopen("image.bmp", "rb");
  if (image_file == NULL) {
    printf("Error opening the image file.\n");
    return 1;
  }

  // Get the size of the image
  fseek(image_file, 2, SEEK_SET);
  unsigned int image_size;
  fread(&image_size, sizeof(image_size), 1, image_file);

  // Check if the image is too large
  if (image_size > MAX_IMAGE_SIZE) {
    printf("Error: The image is too large.\n");
    return 1;
  }

  // Get the input message
  char message[MAX_MESSAGE_SIZE];
  printf("Enter the message to hide: ");
  gets(message);

  // Check if the message is too long
  int message_length = strlen(message);
  if (message_length > MAX_MESSAGE_SIZE) {
    printf("Error: The message is too long.\n");
    return 1;
  }

  // Encode the message into the image
  unsigned char *image_data = malloc(image_size);
  fread(image_data, image_size, 1, image_file);
  int bit_position = 0;
  for (int i = 0; i < message_length; i++) {
    for (int j = 0; j < 8; j++) {
      int bit_value = get_bit(message[i], j);
      set_bit(&image_data[bit_position / 8], bit_position % 8, bit_value);
      bit_position++;
    }
  }

  // Write the modified image to a file
  FILE *output_file = fopen("output.bmp", "wb");
  if (output_file == NULL) {
    printf("Error opening the output file.\n");
    return 1;
  }
  fwrite(image_data, image_size, 1, output_file);

  // Free the memory
  free(image_data);
  fclose(image_file);
  fclose(output_file);

  printf("Message successfully hidden in the image.\n");
  return 0;
}

// Define the function to get a bit from a byte
unsigned char get_bit(unsigned char byte, int bit_position) {
  return (byte >> bit_position) & 1;
}

// Define the function to set a bit in a byte
void set_bit(unsigned char *byte, int bit_position, int bit_value) {
  *byte |= (1 << bit_position) * bit_value;
}