//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to embed a message into an image
void embedMessage(char *imageFile, char *message) {
  // Open the image file
  FILE *image = fopen(imageFile, "rb+");
  if (image == NULL) {
    perror("Error opening image file");
    exit(1);
  }

  // Get the size of the message
  int messageLength = strlen(message);

  // Get the size of the image
  fseek(image, 0, SEEK_END);
  int imageSize = ftell(image);

  // Make sure the message is not too long
  if (messageLength > imageSize) {
    fprintf(stderr, "Error: Message is too long\n");
    exit(1);
  }

  // Rewind the file pointer to the beginning of the image
  fseek(image, 0, SEEK_SET);

  // Read the image data into a buffer
  unsigned char *imageData = malloc(imageSize);
  fread(imageData, 1, imageSize, image);

  // Embed the message into the image data
  for (int i = 0; i < messageLength; i++) {
    imageData[i] = imageData[i] | (message[i] >> 1);
  }

  // Write the modified image data back to the file
  fseek(image, 0, SEEK_SET);
  fwrite(imageData, 1, imageSize, image);

  // Close the image file
  fclose(image);

  // Print a success message
  printf("Message successfully embedded into image\n");
}

// Function to extract a message from an image
char *extractMessage(char *imageFile) {
  // Open the image file
  FILE *image = fopen(imageFile, "rb");
  if (image == NULL) {
    perror("Error opening image file");
    exit(1);
  }

  // Get the size of the image
  fseek(image, 0, SEEK_END);
  int imageSize = ftell(image);

  // Rewind the file pointer to the beginning of the image
  fseek(image, 0, SEEK_SET);

  // Read the image data into a buffer
  unsigned char *imageData = malloc(imageSize);
  fread(imageData, 1, imageSize, image);

  // Extract the message from the image data
  char *message = malloc(imageSize);
  for (int i = 0; i < imageSize; i++) {
    message[i] = imageData[i] & 1;
  }

  // Null-terminate the message
  message[imageSize] = '\0';

  // Close the image file
  fclose(image);

  // Return the message
  return message;
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <input_image> <output_image> [message]\n", argv[0]);
    exit(1);
  }

  // Get the input and output image file names
  char *inputFile = argv[1];
  char *outputFile = argv[2];

  // Check if we are embedding or extracting a message
  if (argc == 4) {
    // Embed a message into an image
    embedMessage(inputFile, argv[3]);
  } else {
    // Extract a message from an image
    char *message = extractMessage(inputFile);
    printf("Extracted message: %s\n", message);
  }

  return 0;
}