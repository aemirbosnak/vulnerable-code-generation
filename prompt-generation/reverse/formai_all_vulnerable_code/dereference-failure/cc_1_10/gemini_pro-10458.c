//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// The secret message to hide
char *message = "This is a secret message!";

// The image file to hide the message in
char *image_file = "image.bmp";

// The output image file to save the steganographed image
char *output_file = "output.bmp";

// Function to embed the message in the image
int embed_message(uint8_t *image_data, int image_size, char *message) {
  int message_length = strlen(message);
  if (message_length > image_size) {
    printf("Error: Message too long for image!\n");
    return -1;
  }

  // Iterate over the message characters
  for (int i = 0; i < message_length; i++) {
    // Convert the character to binary
    uint8_t binary = (uint8_t)message[i];

    // Embed the binary into the least significant bits of the image
    for (int j = 0; j < 8; j++) {
      uint8_t mask = 1 << j;
      image_data[i * 8 + j] = (image_data[i * 8 + j] & ~mask) | ((binary >> j) & mask);
    }
  }

  return 0;
}

// Function to extract the message from the image
char *extract_message(uint8_t *image_data, int image_size) {
  char *message = malloc(image_size / 8 + 1);
  for (int i = 0; i < image_size / 8; i++) {
    uint8_t binary = 0;
    for (int j = 0; j < 8; j++) {
      uint8_t mask = 1 << j;
      binary |= (image_data[i * 8 + j] & mask) << j;
    }
    message[i] = binary;
  }
  message[image_size / 8] = '\0';
  return message;
}

// Main function
int main() {
  // Open the image file
  FILE *image_fp = fopen(image_file, "rb");
  if (image_fp == NULL) {
    printf("Error: Could not open image file!\n");
    return 1;
  }

  // Get the image size
  fseek(image_fp, 0, SEEK_END);
  int image_size = ftell(image_fp);
  fseek(image_fp, 0, SEEK_SET);

  // Read the image data
  uint8_t *image_data = malloc(image_size);
  fread(image_data, 1, image_size, image_fp);
  fclose(image_fp);

  // Embed the message in the image
  int embed_result = embed_message(image_data, image_size, message);
  if (embed_result != 0) {
    printf("Error: Could not embed message!\n");
    free(image_data);
    return 1;
  }

  // Save the steganographed image
  FILE *output_fp = fopen(output_file, "wb");
  if (output_fp == NULL) {
    printf("Error: Could not open output file!\n");
    free(image_data);
    return 1;
  }
  fwrite(image_data, 1, image_size, output_fp);
  fclose(output_fp);

  printf("Success! The message has been hidden in the image.\n");

  // Extract the message from the image
  char *extracted_message = extract_message(image_data, image_size);
  printf("The extracted message is: %s\n", extracted_message);
  free(extracted_message);

  free(image_data);
  return 0;
}