//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to embed the secret message into the image
void embedMessage(char *imageData, char *secretMessage) {
  int imageSize = strlen(imageData);
  int messageSize = strlen(secretMessage);

  if (messageSize > imageSize) {
    printf("Error: Secret message is too large to embed in the image.\n");
    exit(1);
  }

  // Loop through the image data and embed the secret message one character at a time
  for (int i = 0; i < messageSize; i++) {
    // Convert the secret message character to binary
    int binaryMessage = secretMessage[i];

    // Loop through the 8 bits of the secret message character
    for (int j = 0; j < 8; j++) {
      // Get the least significant bit of the image data
      int imageBit = imageData[i] & 1;

      // If the least significant bit of the image data is the same as the current bit of the secret message character, do nothing
      if (imageBit == (binaryMessage & 1)) {
        // Do nothing
      }
      // Otherwise, flip the least significant bit of the image data
      else {
        imageData[i] ^= 1;
      }

      // Shift the secret message character right by one bit
      binaryMessage >>= 1;
    }
  }

  printf("Secret message successfully embedded in the image.\n");
}

// Function to extract the secret message from the image
char *extractMessage(char *imageData) {
  int imageSize = strlen(imageData);
  int messageSize = 0;

  // Loop through the image data and count the number of secret message characters
  for (int i = 0; i < imageSize; i++) {
    // Get the least significant bit of the image data
    int imageBit = imageData[i] & 1;

    // If the least significant bit of the image data is 1, increment the message size
    if (imageBit == 1) {
      messageSize++;
    }
  }

  // Allocate memory for the secret message
  char *secretMessage = malloc(messageSize + 1);

  // Loop through the image data and extract the secret message one character at a time
  int messageIndex = 0;
  for (int i = 0; i < imageSize; i++) {
    // Get the least significant bit of the image data
    int imageBit = imageData[i] & 1;

    // Add the least significant bit of the image data to the secret message character
    secretMessage[messageIndex] = (secretMessage[messageIndex] << 1) | imageBit;

    // If the secret message character is complete, increment the message index
    if (messageIndex < messageSize && imageBit == 1) {
      messageIndex++;
    }
  }

  // Add the null terminator to the secret message
  secretMessage[messageSize] = '\0';

  printf("Secret message successfully extracted from the image.\n");
  return secretMessage;
}

int main() {
  // Image data
  char imageData[] = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

  // Secret message
  char secretMessage[] = "Hello world!";

  // Embed the secret message into the image
  embedMessage(imageData, secretMessage);

  // Extract the secret message from the image
  char *extractedMessage = extractMessage(imageData);

  // Print the extracted secret message
  printf("Extracted secret message: %s\n", extractedMessage);

  // Free the memory allocated for the extracted secret message
  free(extractedMessage);

  return 0;
}