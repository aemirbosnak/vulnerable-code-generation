//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: relaxed
#include <stdio.h>

int main() {
  int width, height, i, j;

  // Prompt user for image width and height
  printf("Enter image width: ");
  scanf("%d", &width);
  printf("Enter image height: ");
  scanf("%d", &height);

  // Create 2D array for image pixels
  int image[width][height];

  // Prompt user for pixel values of the image
  printf("Enter image pixel values (0-255):\n");
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      scanf("%d", &image[j][i]);
    }
  }

  // Convert image to ASCII art
  char ascii[width][height];
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      if (image[j][i] >= 200) {
        ascii[j][i] = '@';
      } else if (image[j][i] >= 150) {
        ascii[j][i] = '#';
      } else if (image[j][i] >= 100) {
        ascii[j][i] = '*';
      } else if (image[j][i] >= 50) {
        ascii[j][i] = '+';
      } else {
        ascii[j][i] = '.';
      }
    }
  }

  // Print ASCII art
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      printf("%c", ascii[j][i]);
    }
    printf("\n");
  }

  return 0;
}