//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Function to hide a message in an image
void hideMessage(char *fileName, char *message) {
  // Open the image file
  FILE *imageFile = fopen(fileName, "rb");
  if (imageFile == NULL) {
    perror("Error opening image file");
    exit(1);
  }

  // Get the file size
  fseek(imageFile, 0, SEEK_END);
  long fileSize = ftell(imageFile);
  rewind(imageFile);

  // Check if the message is too long to fit in the image
  if (strlen(message) > fileSize) {
    fprintf(stderr, "Error: Message is too long to fit in image\n");
    exit(1);
  }

  // Read the image data into a buffer
  unsigned char *imageData = malloc(fileSize);
  if (imageData == NULL) {
    perror("Error allocating memory for image data");
    exit(1);
  }
  fread(imageData, fileSize, 1, imageFile);

  // Hide the message in the image data by modifying the least significant bit of each pixel
  for (int i = 0; i < strlen(message); i++) {
    for (int j = 0; j < 8; j++) {
      imageData[i * 8 + j] = (imageData[i * 8 + j] & 0xFE) | ((message[i] >> j) & 0x01);
    }
  }

  // Write the modified image data back to the file
  rewind(imageFile);
  fwrite(imageData, fileSize, 1, imageFile);

  // Close the image file
  fclose(imageFile);
}

// Function to extract a message from an image
char *extractMessage(char *fileName) {
  // Open the image file
  FILE *imageFile = fopen(fileName, "rb");
  if (imageFile == NULL) {
    perror("Error opening image file");
    exit(1);
  }

  // Get the file size
  fseek(imageFile, 0, SEEK_END);
  long fileSize = ftell(imageFile);
  rewind(imageFile);

  // Read the image data into a buffer
  unsigned char *imageData = malloc(fileSize);
  if (imageData == NULL) {
    perror("Error allocating memory for image data");
    exit(1);
  }
  fread(imageData, fileSize, 1, imageFile);

  // Extract the message from the image data by reading the least significant bit of each pixel
  char *message = malloc(fileSize / 8 + 1);
  if (message == NULL) {
    perror("Error allocating memory for message");
    exit(1);
  }
  for (int i = 0; i < fileSize / 8; i++) {
    for (int j = 0; j < 8; j++) {
      message[i] |= (imageData[i * 8 + j] & 0x01) << j;
    }
  }
  message[fileSize / 8] = '\0';

  // Close the image file
  fclose(imageFile);

  // Return the message
  return message;
}

int main() {
  // Hide a message in an image
  hideMessage("image.png", "Hello, world!");

  // Extract the message from the image
  char *message = extractMessage("image.png");

  // Print the message
  printf("The message is: %s\n", message);

  // Free the memory allocated for the message
  free(message);

  return 0;
}