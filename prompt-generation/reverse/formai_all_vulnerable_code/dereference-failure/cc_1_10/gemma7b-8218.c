//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void img_to_ascii(char **img, int w, int h) {
  for (int r = 0; r < h; r++) {
    for (int c = 0; c < w; c++) {
      int pixel_value = img[r][c];
      switch (pixel_value) {
        case 0:
          printf(" ");
          break;
        case 1:
          printf(". ");
          break;
        case 2:
          printf(".. ");
          break;
        case 3:
          printf("... ");
          break;
        default:
          printf("Error!");
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
  img = (char **)malloc(h * sizeof(char *) + h);
  for (int r = 0; r < h; r++) {
    img[r] = (char *)malloc(w * sizeof(char) + w);
  }

  // Get the image dimensions
  printf("Enter the width of the image: ");
  scanf("%d", &w);

  printf("Enter the height of the image: ");
  scanf("%d", &h);

  // Get the image pixels
  printf("Enter the pixels of the image (separated by commas): ");
  char pixel_str[1024];
  scanf("%s", pixel_str);

  // Convert the pixel string into an image array
  char *pixel_arr = strdup(pixel_str);
  int i = 0;
  for (int r = 0; r < h; r++) {
    for (int c = 0; c < w; c++) {
      img[r][c] = pixel_arr[i] - '0';
      i++;
    }
  }

  // Convert the image to ASCII art
  img_to_ascii(img, w, h);

  // Free the image memory
  for (int r = 0; r < h; r++) {
    free(img[r]);
  }
  free(img);

  return 0;
}