//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void img_to_ascii(char **img, int w, int h) {
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      int pixel = img[y][x];
      switch (pixel) {
        case 0:
          printf(" ");
          break;
        case 1:
          printf(".");
          break;
        case 2:
          printf("#");
          break;
        default:
          printf("!");
          break;
      }
    }
    printf("\n");
  }
}

int main() {
  char **img = NULL;
  int w = 0;
  int h = 0;

  // Allocate memory for the image
  img = malloc(h * w * sizeof(char *));
  for (int i = 0; i < h; i++) {
    img[i] = malloc(w * sizeof(char));
  }

  // Fill the image with data
  img[0][0] = 2;
  img[0][1] = 1;
  img[1][0] = 0;
  img[1][1] = 2;

  // Convert the image to ASCII art
  img_to_ascii(img, w, h);

  // Free the image memory
  for (int i = 0; i < h; i++) {
    free(img[i]);
  }
  free(img);

  return 0;
}