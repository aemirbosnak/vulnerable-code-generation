//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to hide a secret message in an image
void hide_secret_message(char *image_file_name, char *message) {
  // Open the image file for reading
  FILE *image_file = fopen(image_file_name, "rb");
  if (image_file == NULL) {
    printf("Error opening image file!\n");
    exit(1);
  }

  // Get the size of the image file
  fseek(image_file, 0, SEEK_END);
  int image_size = ftell(image_file);
  fseek(image_file, 0, SEEK_SET);

  // Read the image file into a buffer
  unsigned char *image_buffer = malloc(image_size);
  if (image_buffer == NULL) {
    printf("Error allocating memory for image buffer!\n");
    exit(1);
  }
  fread(image_buffer, 1, image_size, image_file);

  // Hide the secret message in the image buffer
  int message_size = strlen(message);
  for (int i = 0; i < message_size; i++) {
    image_buffer[i] = image_buffer[i] & 0xF8 | (message[i] & 0x07);
  }

  // Write the modified image buffer to a new file
  FILE *output_file = fopen("output.bmp", "wb");
  if (output_file == NULL) {
    printf("Error opening output file!\n");
    exit(1);
  }
  fwrite(image_buffer, 1, image_size, output_file);

  // Free the allocated memory
  free(image_buffer);

  // Close the files
  fclose(image_file);
  fclose(output_file);

  printf("Secret message hidden in image successfully!\n");
}

// Function to extract the secret message from an image
char *extract_secret_message(char *image_file_name) {
  // Open the image file for reading
  FILE *image_file = fopen(image_file_name, "rb");
  if (image_file == NULL) {
    printf("Error opening image file!\n");
    exit(1);
  }

  // Get the size of the image file
  fseek(image_file, 0, SEEK_END);
  int image_size = ftell(image_file);
  fseek(image_file, 0, SEEK_SET);

  // Read the image file into a buffer
  unsigned char *image_buffer = malloc(image_size);
  if (image_buffer == NULL) {
    printf("Error allocating memory for image buffer!\n");
    exit(1);
  }
  fread(image_buffer, 1, image_size, image_file);

  // Extract the secret message from the image buffer
  int message_size = 0;
  while (image_buffer[message_size] != '\0') {
    message_size++;
  }

  char *message = malloc(message_size + 1);
  if (message == NULL) {
    printf("Error allocating memory for message!\n");
    exit(1);
  }
  for (int i = 0; i < message_size; i++) {
    message[i] = image_buffer[i] & 0x07;
  }
  message[message_size] = '\0';

  // Free the allocated memory
  free(image_buffer);

  // Close the file
  fclose(image_file);

  return message;
}

int main() {
  // Hide a secret message in an image
  hide_secret_message("image.bmp", "Secret message!");

  // Extract the secret message from the image
  char *message = extract_secret_message("output.bmp");

  // Print the secret message
  printf("Secret message: %s\n", message);

  // Free the allocated memory
  free(message);

  return 0;
}