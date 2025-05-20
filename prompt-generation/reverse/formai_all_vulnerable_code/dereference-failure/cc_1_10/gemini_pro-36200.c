//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Turing-inspired function to hide a secret message within an image
void turing_steganography(const char* image_path, const char* message, const char* output_path) {
  // Open the input image file
  FILE* image_file = fopen(image_path, "rb");
  if (!image_file) {
    printf("Error opening image file\n");
    return;
  }

  // Determine the size of the image file
  fseek(image_file, 0, SEEK_END);
  long image_size = ftell(image_file);
  rewind(image_file);

  // Read the image data into a buffer
  uint8_t* image_data = malloc(image_size);
  fread(image_data, 1, image_size, image_file);
  fclose(image_file);

  // Determine the size of the secret message
  long message_size = strlen(message);

  // Encode the secret message into the image data using Turing's method
  for (long i = 0; i < message_size; i++) {
    // Convert the ASCII value of the message character to binary
    uint8_t binary_message = message[i];

    // Get the least significant bit of the current pixel in the image
    uint8_t lsb = image_data[i] & 1;

    // Set the least significant bit of the current pixel to the least significant bit of the secret message
    image_data[i] = (image_data[i] & ~1) | (binary_message & 1);

    // Shift the secret message character to the right by one bit
    binary_message >>= 1;
  }

  // Open the output image file
  FILE* output_file = fopen(output_path, "wb");
  if (!output_file) {
    printf("Error opening output image file\n");
    free(image_data);
    return;
  }

  // Write the modified image data to the output file
  fwrite(image_data, 1, image_size, output_file);
  fclose(output_file);

  // Free the allocated memory
  free(image_data);

  printf("Secret message successfully hidden in the image!\n");
}

// Turing-inspired function to extract a secret message from an image
char* turing_decoding(const char* image_path) {
  // Open the input image file
  FILE* image_file = fopen(image_path, "rb");
  if (!image_file) {
    printf("Error opening image file\n");
    return NULL;
  }

  // Determine the size of the image file
  fseek(image_file, 0, SEEK_END);
  long image_size = ftell(image_file);
  rewind(image_file);

  // Read the image data into a buffer
  uint8_t* image_data = malloc(image_size);
  fread(image_data, 1, image_size, image_file);
  fclose(image_file);

  // Initialize the secret message
  char* secret_message = malloc(image_size);
  memset(secret_message, 0, image_size);

  // Decode the secret message from the image data using Turing's method
  for (long i = 0; i < image_size; i++) {
    // Get the least significant bit of the current pixel in the image
    uint8_t lsb = image_data[i] & 1;

    // Append the least significant bit to the secret message
    secret_message[i] |= lsb;

    // Shift the secret message character to the left by one bit
    secret_message[i] <<= 1;
  }

  // Remove any trailing null characters from the secret message
  secret_message = realloc(secret_message, strlen(secret_message) + 1);

  // Free the allocated memory
  free(image_data);

  return secret_message;
}

// MAIN-ufu
int main() {

    // path to your image file
    char* image_path = "/path/to/image.png";
    // the secret message to hide with in the image
    char* message = "Hello, world!";
    // path to store the output image with the hidden message
    char* output_path = "/path/to/output_image.png";

    // calling image steganography method
    turing_steganography(image_path, message, output_path);

    // path to the output image with hidden message
    char* output_image_path = "/path/to/output_image.png";

    // calling image decoding method
    char* decoded_message = turing_decoding(output_image_path);

    printf("Decoded secret message: %s\n", decoded_message);

    free(decoded_message);
	return 0;
}