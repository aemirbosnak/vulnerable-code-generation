//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the image and the secret message
#define MAX_IMAGE_SIZE 1000000
#define MAX_MESSAGE_SIZE 1000

// Define the function to encode the secret message into the image
void encode(char *image, int imageSize, char *message, int messageSize) {
  // Convert the secret message into a binary string
  char *binaryMessage = (char *)malloc(messageSize * 8);
  for (int i = 0; i < messageSize; i++) {
    for (int j = 7; j >= 0; j--) {
      binaryMessage[i * 8 + j] = (message[i] >> j) & 1;
    }
  }

  // Encode the binary message into the image by changing the least significant bit of each pixel
  int binaryMessageIndex = 0;
  for (int i = 0; i < imageSize; i++) {
    if (binaryMessageIndex < messageSize * 8) {
      image[i] &= 0xFE;
      image[i] |= binaryMessage[binaryMessageIndex++];
    }
  }

  // Free the memory allocated for the binary message
  free(binaryMessage);
}

// Define the function to decode the secret message from the image
char *decode(char *image, int imageSize) {
  // Create a buffer to store the decoded secret message
  char *message = (char *)malloc(MAX_MESSAGE_SIZE);
  memset(message, 0, MAX_MESSAGE_SIZE);

  // Decode the secret message from the image by extracting the least significant bit of each pixel
  int messageIndex = 0;
  for (int i = 0; i < imageSize; i++) {
    if (messageIndex < MAX_MESSAGE_SIZE * 8) {
      message[messageIndex / 8] |= (image[i] & 1) << (7 - (messageIndex % 8));
      messageIndex++;
    } else {
      break;
    }
  }

  // Return the decoded secret message
  return message;
}

// Define the main function
int main() {
  // Open the image file
  FILE *imageFile = fopen("image.bmp", "rb");
  if (imageFile == NULL) {
    printf("Error opening the image file!\n");
    return 1;
  }

  // Get the size of the image file
  fseek(imageFile, 0, SEEK_END);
  int imageSize = ftell(imageFile);
  rewind(imageFile);

  // Read the image data into a buffer
  char *image = (char *)malloc(imageSize);
  fread(image, 1, imageSize, imageFile);
  fclose(imageFile);

  // Open the secret message file
  FILE *messageFile = fopen("message.txt", "rb");
  if (messageFile == NULL) {
    printf("Error opening the secret message file!\n");
    return 1;
  }

  // Get the size of the secret message file
  fseek(messageFile, 0, SEEK_END);
  int messageSize = ftell(messageFile);
  rewind(messageFile);

  // Read the secret message into a buffer
  char *message = (char *)malloc(messageSize);
  fread(message, 1, messageSize, messageFile);
  fclose(messageFile);

  // Encode the secret message into the image
  encode(image, imageSize, message, messageSize);

  // Save the modified image to a file
  imageFile = fopen("encoded_image.bmp", "wb");
  if (imageFile == NULL) {
    printf("Error saving the modified image file!\n");
    return 1;
  }
  fwrite(image, 1, imageSize, imageFile);
  fclose(imageFile);

  // Free the memory allocated for the image and the secret message
  free(image);
  free(message);

  // Decode the secret message from the image
  char *decodedMessage = decode(image, imageSize);

  // Print the decoded secret message to the console
  printf("Decoded secret message: %s\n", decodedMessage);

  // Free the memory allocated for the decoded secret message
  free(decodedMessage);

  return 0;
}