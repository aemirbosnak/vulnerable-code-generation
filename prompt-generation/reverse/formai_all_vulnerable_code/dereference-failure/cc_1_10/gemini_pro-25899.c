//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the image and the message
#define MAX_IMAGE_SIZE 1000000
#define MAX_MESSAGE_SIZE 1000

// Define the bitmask for the red, green, and blue channels
#define RED_MASK 0xFF0000
#define GREEN_MASK 0x00FF00
#define BLUE_MASK 0x0000FF

// Define the function to encode the message into the image
void encodeMessage(unsigned char *image, int imageSize, char *message, int messageSize) {
  // Check if the message is too large for the image
  if (messageSize > (imageSize / 3)) {
    printf("Error: The message is too large for the image.\n");
    return;
  }

  // Convert the message to binary
  char binaryMessage[MAX_MESSAGE_SIZE * 8];
  for (int i = 0; i < messageSize; i++) {
    for (int j = 0; j < 8; j++) {
      binaryMessage[i * 8 + j] = (message[i] >> j) & 1;
    }
  }

  // Encode the binary message into the image
  int bitIndex = 0;
  for (int i = 0; i < imageSize; i += 3) {
    // Get the red, green, and blue channels of the pixel
    int red = image[i] & RED_MASK;
    int green = image[i + 1] & GREEN_MASK;
    int blue = image[i + 2] & BLUE_MASK;

    // Set the least significant bit of each channel to the next bit of the message
    red = (red & ~1) | binaryMessage[bitIndex++];
    green = (green & ~1) | binaryMessage[bitIndex++];
    blue = (blue & ~1) | binaryMessage[bitIndex++];

    // Set the pixel back to the image
    image[i] = red;
    image[i + 1] = green;
    image[i + 2] = blue;
  }
}

// Define the function to decode the message from the image
char *decodeMessage(unsigned char *image, int imageSize) {
  // Allocate memory for the message
  char *message = malloc(MAX_MESSAGE_SIZE);

  // Decode the binary message from the image
  int bitIndex = 0;
  for (int i = 0; i < imageSize; i += 3) {
    // Get the red, green, and blue channels of the pixel
    int red = image[i] & RED_MASK;
    int green = image[i + 1] & GREEN_MASK;
    int blue = image[i + 2] & BLUE_MASK;

    // Get the least significant bit of each channel
    int bit1 = red & 1;
    int bit2 = green & 1;
    int bit3 = blue & 1;

    // Combine the bits into a byte
    message[bitIndex / 8] |= (bit1 << (7 - (bitIndex % 8))) | (bit2 << (6 - (bitIndex % 8))) | (bit3 << (5 - (bitIndex % 8)));
    bitIndex += 3;
  }

  // Null-terminate the message
  message[bitIndex / 8] = '\0';

  // Return the message
  return message;
}

// Define the main function
int main() {
  // Load the image from a file
  FILE *imagefile = fopen("image.bmp", "rb");
  if (imagefile == NULL) {
    printf("Error: Could not open the image file.\n");
    return 1;
  }

  // Get the size of the image
  fseek(imagefile, 0, SEEK_END);
  int imageSize = ftell(imagefile);
  rewind(imagefile);

  // Allocate memory for the image
  unsigned char *image = malloc(imageSize);

  // Read the image into memory
  fread(image, 1, imageSize, imagefile);

  // Close the image file
  fclose(imagefile);

  // Encode a message into the image
  char message[] = "Hello, world!";
  encodeMessage(image, imageSize, message, strlen(message));

  // Save the image to a file
  imagefile = fopen("encoded_image.bmp", "wb");
  if (imagefile == NULL) {
    printf("Error: Could not open the encoded image file.\n");
    return 1;
  }

  // Write the image to the file
  fwrite(image, 1, imageSize, imagefile);

  // Close the encoded image file
  fclose(imagefile);

  // Decode the message from the image
  char *decodedMessage = decodeMessage(image, imageSize);

  // Print the decoded message
  printf("Decoded message: %s\n", decodedMessage);

  // Free the memory allocated for the image and the message
  free(image);
  free(decodedMessage);

  return 0;
}