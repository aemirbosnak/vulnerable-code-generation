//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertImageToASCII(char **image, int width, int height) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int pixelValue = image[y][x];
      switch (pixelValue) {
        case 0:
          printf(" ");
          break;
        case 1:
          printf(".");
          break;
        case 2:
          printf("$");
          break;
        case 3:
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
  char **image = NULL;
  image = malloc(5 * sizeof(char *));
  for (int i = 0; i < 5; i++) {
    image[i] = malloc(10 * sizeof(char));
  }

  image[0][0] = 1;
  image[0][1] = 2;
  image[0][2] = 0;
  image[0][3] = 3;
  image[0][4] = 1;
  image[1][0] = 2;
  image[1][1] = 0;
  image[1][2] = 3;
  image[1][3] = 1;
  image[1][4] = 2;
  image[2][0] = 0;
  image[2][1] = 2;
  image[2][2] = 3;
  image[2][3] = 1;
  image[2][4] = 0;
  image[3][0] = 3;
  image[3][1] = 1;
  image[3][2] = 0;
  image[3][3] = 2;
  image[3][4] = 3;
  image[4][0] = 1;
  image[4][1] = 2;
  image[4][2] = 3;
  image[4][3] = 1;
  image[4][4] = 0;

  convertImageToASCII(image, 10, 5);

  free(image);
  return 0;
}