//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the character map
char charMap[] = " .:-=+*#%@@";

// Convert an image to ASCII art
void imageToAscii(char *filename) {
  // Open the image file
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Get the image dimensions
  int width, height;
  fread(&width, sizeof(int), 1, fp);
  fread(&height, sizeof(int), 1, fp);

  // Create a 2D array to store the image data
  unsigned char **image = (unsigned char **)malloc(height * sizeof(unsigned char *));
  for (int i = 0; i < height; i++) {
    image[i] = (unsigned char *)malloc(width * sizeof(unsigned char));
  }

  // Read the image data into the array
  fread(image[0], sizeof(unsigned char), width * height, fp);

  // Close the image file
  fclose(fp);

  // Convert the image data to ASCII art
  char **asciiArt = (char **)malloc(height * sizeof(char *));
  for (int i = 0; i < height; i++) {
    asciiArt[i] = (char *)malloc(width * sizeof(char));
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // Calculate the brightness of the pixel
      double brightness = image[i][j] / 255.0;

      // Find the corresponding character in the character map
      int index = (int)round(brightness * (sizeof(charMap) - 1));

      // Store the character in the ASCII art array
      asciiArt[i][j] = charMap[index];
    }
  }

  // Print the ASCII art to the console
  for (int i = 0; i < height; i++) {
    printf("%s\n", asciiArt[i]);
  }

  // Free the memory allocated for the ASCII art
  for (int i = 0; i < height; i++) {
    free(asciiArt[i]);
  }
  free(asciiArt);

  // Free the memory allocated for the image data
  for (int i = 0; i < height; i++) {
    free(image[i]);
  }
  free(image);
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the user has provided a filename
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    exit(1);
  }

  // Convert the image to ASCII art
  imageToAscii(argv[1]);

  return 0;
}