//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Input image - change filename as needed
  char filename[] = "input_image.jpg";

  // Read the image file into a character buffer
  FILE *fileptr;
  fileptr = fopen(filename, "rb");
  fseek(fileptr, 0, SEEK_END);
  long fileSize = ftell(fileptr);
  rewind(fileptr);
  char *imageBuffer = (char *)malloc(fileSize * sizeof(char));
  fread(imageBuffer, sizeof(char), fileSize, fileptr);
  fclose(fileptr);

  // Embedding a watermark
  char watermark[] = "This is a digital watermark!";

  // Calculate the length of the watermark
  int watermarkLen = strlen(watermark);

  // Embed the watermark into the image
  for (int i = 0; i < watermarkLen; i++) {
    // Extract the next character of the watermark
    char c = watermark[i];

    // Embed the character into the image
    int imageIndex = ((i+1) * 100) % fileSize; // Choose a random position in the image
    imageBuffer[imageIndex] = (imageBuffer[imageIndex] & 0xFE) | ((c >> 7) & 0x01); // Embed the most significant bit
    imageBuffer[imageIndex+1] = (imageBuffer[imageIndex+1] & 0xFE) | ((c >> 6) & 0x01); // Embed the 2nd most significant bit
    imageBuffer[imageIndex+2] = (imageBuffer[imageIndex+2] & 0xFE) | ((c >> 5) & 0x01); // Embed the 3rd most significant bit
    imageBuffer[imageIndex+3] = (imageBuffer[imageIndex+3] & 0xFE) | ((c >> 4) & 0x01); // Embed the 4th most significant bit
    imageBuffer[imageIndex+4] = (imageBuffer[imageIndex+4] & 0xFE) | ((c >> 3) & 0x01); // Embed the 5th most significant bit
    imageBuffer[imageIndex+5] = (imageBuffer[imageIndex+5] & 0xFE) | ((c >> 2) & 0x01); // Embed the 6th most significant bit
    imageBuffer[imageIndex+6] = (imageBuffer[imageIndex+6] & 0xFE) | ((c >> 1) & 0x01); // Embed the 7th most significant bit
    imageBuffer[imageIndex+7] = (imageBuffer[imageIndex+7] & 0xFE) | ((c >> 0) & 0x01); // Embed the least significant bit
  }

  // Output image - change filename as needed
  char outputFilename[] = "output_image.jpg";

  // Write the watermarked image to a new file
  FILE *outputFileptr;
  outputFileptr = fopen(outputFilename, "wb");
  fwrite(imageBuffer, sizeof(char), fileSize, outputFileptr);
  fclose(outputFileptr);

  // Print out a success message
  printf("The watermark has been embedded successfully!");

  return 0;
}