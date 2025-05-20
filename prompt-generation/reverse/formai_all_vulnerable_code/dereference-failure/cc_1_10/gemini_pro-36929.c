//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int main() {
  // Read in the image file
  FILE *fp = fopen("image.bmp", "rb");
  if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Get the image size
  fseek(fp, 0, SEEK_END);
  long int size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  // Create a buffer for the image data
  unsigned char *data = (unsigned char *)malloc(size);
  if (data == NULL) {
    printf("Error allocating memory\n");
    fclose(fp);
    return 1;
  }

  // Read the image data into the buffer
  fread(data, 1, size, fp);
  fclose(fp);

  // Read in the message to embed
  printf("Enter the message to embed: ");
  char message[MAX_LEN];
  fgets(message, MAX_LEN, stdin);

  // Embed the message in the image data
  int i, j, k;
  for (i = 0, j = 0; i < size && j < strlen(message); i += 3, j++) {
    // Set the least significant bit of each byte of the pixel to the corresponding bit of the message
    data[i] = (data[i] & 0xFE) | (message[j] & 0x01);
    data[i + 1] = (data[i + 1] & 0xFE) | ((message[j] >> 1) & 0x01);
    data[i + 2] = (data[i + 2] & 0xFE) | ((message[j] >> 2) & 0x01);
  }

  // Write the modified image data to a new file
  fp = fopen("stego.bmp", "wb");
  if (fp == NULL) {
    printf("Error opening file\n");
    free(data);
    return 1;
  }

  // Write the image data to the file
  fwrite(data, 1, size, fp);
  fclose(fp);

  // Free the image data buffer
  free(data);

  printf("Message successfully embedded in image\n");

  return 0;
}