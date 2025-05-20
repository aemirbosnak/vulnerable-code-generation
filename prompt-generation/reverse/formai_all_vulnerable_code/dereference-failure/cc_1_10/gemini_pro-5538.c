//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Get the image file name from the user.
  char imageFileName[256];
  printf("Enter the name of the image file: ");
  scanf("%s", imageFileName);

  // Open the image file.
  FILE *imageFile = fopen(imageFileName, "rb");
  if (imageFile == NULL) {
    printf("Error opening the image file.\n");
    return 1;
  }

  // Get the image dimensions.
  int width, height;
  fread(&width, sizeof(int), 1, imageFile);
  fread(&height, sizeof(int), 1, imageFile);

  // Create a 2D array to store the pixel values.
  unsigned char **pixels = malloc(height * sizeof(unsigned char *));
  for (int i = 0; i < height; i++) {
    pixels[i] = malloc(width * sizeof(unsigned char));
  }

  // Read the pixel values from the image file.
  fread(pixels, sizeof(unsigned char), width * height, imageFile);

  // Close the image file.
  fclose(imageFile);

  // Create a 2D array to store the ASCII characters.
  char **asciiCharacters = malloc(height * sizeof(char *));
  for (int i = 0; i < height; i++) {
    asciiCharacters[i] = malloc(width * sizeof(char));
  }

  // Convert the pixel values to ASCII characters.
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      asciiCharacters[i][j] = (pixels[i][j] / 255.0) * '~';
    }
  }

  // Print the ASCII characters to the console.
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", asciiCharacters[i][j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the pixel values and the ASCII characters.
  for (int i = 0; i < height; i++) {
    free(pixels[i]);
    free(asciiCharacters[i]);
  }
  free(pixels);
  free(asciiCharacters);

  return 0;
}