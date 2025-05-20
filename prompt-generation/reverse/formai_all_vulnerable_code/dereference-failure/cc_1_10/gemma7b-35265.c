//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

void convertImageToASCII(unsigned char **image, int width, int height) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int pixelValue = image[y][x];
      switch (pixelValue) {
        case 0:
          printf(" ");
          break;
        case 1:
          printf("·");
          break;
        case 2:
          printf(":");
          break;
        case 3:
          printf("=");
          break;
        case 4:
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
  unsigned char **image = malloc(5 * sizeof(unsigned char *));
  image[0] = malloc(5 * sizeof(unsigned char));
  image[1] = malloc(5 * sizeof(unsigned char));
  image[2] = malloc(5 * sizeof(unsigned char));
  image[3] = malloc(5 * sizeof(unsigned char));
  image[4] = malloc(5 * sizeof(unsigned char));

  image[0][0] = 1;
  image[0][1] = 2;
  image[0][2] = 3;
  image[0][3] = 4;
  image[0][4] = 0;

  image[1][0] = 2;
  image[1][1] = 0;
  image[1][2] = 1;
  image[1][3] = 3;
  image[1][4] = 0;

  image[2][0] = 3;
  image[2][1] = 1;
  image[2][2] = 2;
  image[2][3] = 0;
  image[2][4] = 0;

  image[3][0] = 4;
  image[3][1] = 2;
  image[3][2] = 3;
  image[3][3] = 1;
  image[3][4] = 0;

  image[4][0] = 0;
  image[4][1] = 0;
  image[4][2] = 0;
  image[4][3] = 0;
  image[4][4] = 0;

  convertImageToASCII(image, 5, 5);

  free(image[0]);
  free(image[1]);
  free(image[2]);
  free(image[3]);
  free(image[4]);
  free(image);

  return 0;
}