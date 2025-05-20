//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Hiding text in an image
void hideTextInImage(char *image, char *text, char *output) {
  FILE *inputImage = fopen(image, "rb");
  FILE *inputText = fopen(text, "rb");
  FILE *outputImage = fopen(output, "wb");

  // Get the size of the input image
  fseek(inputImage, 0, SEEK_END);
  long imageSize = ftell(inputImage);
  rewind(inputImage);

  // Get the size of the input text
  fseek(inputText, 0, SEEK_END);
  long textSize = ftell(inputText);
  rewind(inputText);

  // Check if the image is large enough to hold the text
  if (imageSize < textSize) {
    printf("Error: The image is not large enough to hold the text.\n");
    return;
  }

  // Read the image into memory
  unsigned char *imageData = malloc(imageSize);
  fread(imageData, 1, imageSize, inputImage);

  // Read the text into memory
  unsigned char *textData = malloc(textSize);
  fread(textData, 1, textSize, inputText);

  // Hide the text in the image
  for (int i = 0; i < textSize; i++) {
    // Get the least significant bit of the text data
    unsigned char bit = textData[i] & 1;

    // Set the least significant bit of the image data to the bit of the text data
    imageData[i] = (imageData[i] & ~1) | bit;
  }

  // Write the steganographed image to the output file
  fwrite(imageData, 1, imageSize, outputImage);

  // Free the memory
  free(imageData);
  free(textData);

  // Close the files
  fclose(inputImage);
  fclose(inputText);
  fclose(outputImage);
}

// Extracting text from an image
void extractTextFromImage(char *image, char *output) {
  FILE *inputImage = fopen(image, "rb");
  FILE *outputText = fopen(output, "wb");

  // Get the size of the input image
  fseek(inputImage, 0, SEEK_END);
  long imageSize = ftell(inputImage);
  rewind(inputImage);

  // Read the image into memory
  unsigned char *imageData = malloc(imageSize);
  fread(imageData, 1, imageSize, inputImage);

  // Extract the text from the image
  char *textData = malloc(imageSize);
  for (int i = 0; i < imageSize; i++) {
    // Get the least significant bit of the image data
    unsigned char bit = imageData[i] & 1;

    // Append the bit to the text data
    textData[i] = bit;
  }

  // Write the extracted text to the output file
  fwrite(textData, 1, imageSize, outputText);

  // Free the memory
  free(imageData);
  free(textData);

  // Close the files
  fclose(inputImage);
  fclose(outputText);
}

int main() {
  // Hide text in an image
  hideTextInImage("image.jpg", "text.txt", "output.jpg");

  // Extract text from an image
  extractTextFromImage("output.jpg", "output.txt");

  return 0;
}