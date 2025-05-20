//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Function to embed a message into an image
void embedMessage(char *image, char *message) {
  int imageSize = 0;
  int messageSize = 0;

  // Determine the size of the image and message
  while (image[imageSize] != '\0') {
    imageSize++;
  }
  while (message[messageSize] != '\0') {
    messageSize++;
  }

  // Check if the image is large enough to hold the message
  if (imageSize < messageSize) {
    printf("Error: The image is too small to hold the message.\n");
    return;
  }

  // Embed the message into the image by modifying the least significant bits of each pixel
  for (int i = 0; i < messageSize; i++) {
    for (int j = 0; j < 8; j++) {
      // Get the jth bit of the message character
      int bit = (message[i] >> j) & 1;

      // Modify the least significant bit of the image pixel to match the bit
      image[i * 8 + j] = (image[i * 8 + j] & 0xFE) | bit;
    }
  }

  printf("Message successfully embedded into image.\n");
}

// Function to extract a message from an image
char *extractMessage(char *image) {
  int imageSize = 0;
  int messageSize = 0;

  // Determine the size of the image
  while (image[imageSize] != '\0') {
    imageSize++;
  }

  // Determine the size of the message by counting the number of modified pixels
  for (int i = 0; i < imageSize; i++) {
    if (image[i] & 1) {
      messageSize++;
    }
  }

  // Extract the message from the image by reading the least significant bits of each modified pixel
  char *message = malloc(messageSize + 1);
  for (int i = 0; i < messageSize; i++) {
    message[i] = 0;
    for (int j = 0; j < 8; j++) {
      // Get the jth bit of the message character
      int bit = image[i * 8 + j] & 1;

      // Shift the message character to the left and add the bit
      message[i] = (message[i] << 1) | bit;
    }
  }

  // Add the null terminator to the message
  message[messageSize] = '\0';

  return message;
}

int main() {
  // Get the image and message from the user
  char *image = malloc(1000);
  char *message = malloc(100);
  printf("Enter the image: ");
  scanf("%s", image);
  printf("Enter the message: ");
  scanf("%s", message);

  // Embed the message into the image
  embedMessage(image, message);

  // Extract the message from the image
  char *extractedMessage = extractMessage(image);

  // Print the extracted message
  printf("Extracted message: %s\n", extractedMessage);

  // Free the allocated memory
  free(image);
  free(message);
  free(extractedMessage);

  return 0;
}