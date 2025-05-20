//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to hide the secret message in the image
void hideMessage(char *image, char *secret, int size) {
  // Iterate over the secret message
  for (int i = 0; i < size; i++) {
    // Convert the secret message character to binary
    char binary[8];
    for (int j = 0; j < 8; j++) {
      binary[j] = (secret[i] >> j) & 1;
    }
    // Embed the binary representation of the secret message character into the image
    for (int j = 0; j < 8; j++) {
      image[i * 8 + j] = (image[i * 8 + j] & 0xFE) | binary[j];
    }
  }
}

// Function to extract the secret message from the image
char *extractMessage(char *image, int size) {
  // Allocate memory for the secret message
  char *secret = malloc(size);
  // Iterate over the image
  for (int i = 0; i < size; i++) {
    // Extract the binary representation of the secret message character from the image
    char binary[8];
    for (int j = 0; j < 8; j++) {
      binary[j] = image[i * 8 + j] & 1;
    }
    // Convert the binary representation of the secret message character to ASCII
    secret[i] = 0;
    for (int j = 0; j < 8; j++) {
      secret[i] |= binary[j] << j;
    }
  }
  // Return the secret message
  return secret;
}

// Main function
int main() {
  // Open the image and the secret message file
  FILE *imagefile = fopen("image.bmp", "rb+");
  FILE *secretfile = fopen("secret.txt", "rb");
  if (imagefile == NULL || secretfile == NULL) {
    printf("Error opening the files!\n");
    return 1;
  }

  // Get the filesizes
  fseek(imagefile, 0, SEEK_END);
  long image_size = ftell(imagefile);
  fseek(secretfile, 0, SEEK_END);
  long secret_size = ftell(secretfile);

  // Check if the secret message is too large for the image
  if (secret_size > (image_size - 54)) {
    printf("Error: secret message is too large for the image!\n");
    return 1;
  }

  // Read the image data into memory
  char *image = malloc(image_size);
  fseek(imagefile, 0, SEEK_SET);
  fread(image, 1, image_size, imagefile);

  // Hide the secret message in the image
  hideMessage(image, secretfile, secret_size);

  // Write the modified image data to the file
  fseek(imagefile, 0, SEEK_SET);
  fwrite(image, 1, image_size, imagefile);

  // Close the files
  fclose(imagefile);
  fclose(secretfile);

  return 0;
}