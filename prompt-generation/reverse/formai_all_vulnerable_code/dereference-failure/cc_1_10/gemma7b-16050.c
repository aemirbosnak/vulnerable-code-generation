//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

void convert_image_to_ascii(char **image, int width, int height) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int pixel_value = image[y][x];
      switch (pixel_value) {
        case 0:
          printf(" ");
          break;
        case 1:
          printf(".");
          break;
        case 2:
          printf("/");
          break;
        case 3:
          printf("$");
          break;
        case 4:
          printf("@");
          break;
        default:
          printf("?");
          break;
      }
    }
    printf("\n");
  }
}

int main() {
  char **image = malloc(5 * sizeof(char *));
  image[0] = malloc(10 * sizeof(char));
  image[1] = malloc(10 * sizeof(char));
  image[2] = malloc(10 * sizeof(char));
  image[3] = malloc(10 * sizeof(char));
  image[4] = malloc(10 * sizeof(char));

  image[0][0] = 1;
  image[0][1] = 2;
  image[0][2] = 3;
  image[0][3] = 4;
  image[0][4] = 1;

  image[1][0] = 2;
  image[1][1] = 1;
  image[1][2] = 3;
  image[1][3] = 4;
  image[1][4] = 2;

  image[2][0] = 3;
  image[2][1] = 2;
  image[2][2] = 1;
  image[2][3] = 4;
  image[2][4] = 3;

  image[3][0] = 4;
  image[3][1] = 3;
  image[3][2] = 2;
  image[3][3] = 4;
  image[3][4] = 4;

  image[4][0] = 1;
  image[4][1] = 2;
  image[4][2] = 3;
  image[4][3] = 4;
  image[4][4] = 1;

  convert_image_to_ascii(image, 10, 5);

  free(image[0]);
  free(image[1]);
  free(image[2]);
  free(image[3]);
  free(image[4]);
  free(image);

  return 0;
}