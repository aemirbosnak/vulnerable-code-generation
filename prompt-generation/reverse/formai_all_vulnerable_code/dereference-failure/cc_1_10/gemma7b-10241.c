//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void image_to_ascii(char **img, int w, int h) {
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
  int w = 5;
  int h = 5;

  img = (char **)malloc(h * sizeof(char *) + h);
  for (int i = 0; i < h; i++) {
    img[i] = (char *)malloc(w * sizeof(char) + w);
  }

  // Populate the image data
  img[0][0] = 1;
  img[0][1] = 2;
  img[0][2] = 0;
  img[0][3] = 3;
  img[0][4] = 1;
  img[1][0] = 2;
  img[1][1] = 3;
  img[1][2] = 0;
  img[1][3] = 2;
  img[1][4] = 1;
  img[2][0] = 0;
  img[2][1] = 1;
  img[2][2] = 2;
  img[2][3] = 0;
  img[2][4] = 1;
  img[3][0] = 3;
  img[3][1] = 2;
  img[3][2] = 1;
  img[3][3] = 0;
  img[3][4] = 2;
  img[4][0] = 1;
  img[4][1] = 2;
  img[4][2] = 0;
  img[4][3] = 3;
  img[4][4] = 1;

  image_to_ascii(img, w, h);

  free(img);

  return 0;
}