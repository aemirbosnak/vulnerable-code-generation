//FormAI DATASET v1.0 Category: Image Steganography ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

// Function to hide the message in the image
void hide_message(char *message, char *image) {

  // Open the image file in read mode
  FILE *fp = fopen(image, "rb");
  
  if (fp == NULL) {
    printf("Error opening the image file.\n");
    exit(1);
  }
  
  // Open a new file to store the encoded image
  FILE *encoded_image = fopen("encoded_image.bmp", "wb");
  if (encoded_image == NULL) {
    printf("Error opening the encoded image file.\n");
    exit(1);
  }

  // Copy the header of the image as it is
  unsigned char header[54];
  fread(header, sizeof(unsigned char), 54, fp);
  fwrite(header, sizeof(unsigned char), 54, encoded_image);

  // Traverse through the message
  int i, j = 0;
  for (i = 0; message[i] != '\0'; i++) {
    char c = message[i];

    // Traverse through the bits in the character
    for (j = 7; j >= 0; j--) {
      int bit = (c >> j) & 1;

      // Read the pixel value of blue color from the image
      unsigned char pixel;
      fread(&pixel, sizeof(unsigned char), 1, fp);

      // Modify the last bit of the pixel
      pixel = (pixel & 0xFE) | bit;

      // Write the modified pixel value to the encoded image
      fwrite(&pixel, sizeof(unsigned char), 1, encoded_image);
    }
  }

  // Copy the remaining pixels from the image as it is
  unsigned char pixel;
  while (fread(&pixel, sizeof(unsigned char), 1, fp) == 1) {
    fwrite(&pixel, sizeof(unsigned char), 1, encoded_image);
  }

  // Close the files
  fclose(fp);
  fclose(encoded_image);

  // Print a success message
  printf("Message hidden in the image successfully!\n");
}

// Function to decode and retrieve the hidden message from the image
void decode_message(char *image) {

  // Open the image file in read mode
  FILE *fp = fopen(image, "rb");
  if (fp == NULL) {
    printf("Error opening the image file.\n");
    exit(1);
  }

  // Traverse through the pixel values to retrieve the message
  int i, j = 0;
  char message[10000] = "";
  for (i = 0; i < 10000; i++) {
    char c = 0;

    // Traverse through the bits in the character
    for (j = 0; j < 8; j++) {

      // Read the pixel value of blue color from the image
      unsigned char pixel;
      fread(&pixel, sizeof(unsigned char), 1, fp);

      // Retrieve the last bit of the pixel
      int bit = pixel & 1;

      // Add the bit to the character
      c = (c << 1) | bit;
    }

    // Terminate the loop when null character is encountered
    if (c == '\0') {
      break;
    }

    // Concatenate the character to the message
    message[i] = c;
  }

  // Close the file
  fclose(fp);

  // Print the decoded message
  printf("Decoded Message: %s\n", message);
}


// Main function to test the program
int main() {

  // Hide the message in the image
  char message[] = "Hello, World!";
  char image[] = "image.bmp";
  hide_message(message, image);

  // Decode and retrieve the message from the image
  char encoded_image[] = "encoded_image.bmp";
  decode_message(encoded_image);
  
  return 0;
}