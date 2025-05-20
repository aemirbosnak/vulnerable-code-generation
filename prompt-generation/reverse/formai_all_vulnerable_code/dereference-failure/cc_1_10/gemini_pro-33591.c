//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Read the image data from a file
  FILE *image_file = fopen("image.bmp", "rb");
  if (image_file == NULL) {
    printf("Error: could not open image file.\n");
    return 1;
  }

  // Get the image dimensions
  int width, height;
  fread(&width, sizeof(int), 1, image_file);
  fread(&height, sizeof(int), 1, image_file);

  // Create a 2D array to store the image data
  unsigned char **image_data = (unsigned char **)malloc(height * sizeof(unsigned char *));
  for (int i = 0; i < height; i++) {
    image_data[i] = (unsigned char *)malloc(width * sizeof(unsigned char));
    fread(image_data[i], sizeof(unsigned char), width, image_file);
  }

  // Read the message to be hidden from a file
  FILE *message_file = fopen("message.txt", "rb");
  if (message_file == NULL) {
    printf("Error: could not open message file.\n");
    return 1;
  }

  // Get the size of the message
  int message_size;
  fread(&message_size, sizeof(int), 1, message_file);

  // Read the message into a buffer
  char *message = (char *)malloc(message_size * sizeof(char));
  fread(message, sizeof(char), message_size, message_file);

  // Hide the message in the image data
  int message_index = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // Get the least significant bit of the pixel value
      unsigned char lsb = image_data[i][j] & 1;

      // Replace the least significant bit with the next bit of the message
      if (message_index < message_size) {
        image_data[i][j] &= ~1;
        image_data[i][j] |= (message[message_index] & 1);
        message_index++;
      }
    }
  }

  // Write the modified image data to a new file
  FILE *output_file = fopen("output.bmp", "wb");
  if (output_file == NULL) {
    printf("Error: could not open output file.\n");
    return 1;
  }

  // Write the image dimensions to the output file
  fwrite(&width, sizeof(int), 1, output_file);
  fwrite(&height, sizeof(int), 1, output_file);

  // Write the modified image data to the output file
  for (int i = 0; i < height; i++) {
    fwrite(image_data[i], sizeof(unsigned char), width, output_file);
    free(image_data[i]);
  }
  free(image_data);

  // Close the files
  fclose(image_file);
  fclose(message_file);
  fclose(output_file);

  printf("Message hidden successfully.\n");
  return 0;
}