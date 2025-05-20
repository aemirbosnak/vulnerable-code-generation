//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

void image_to_ascii(char **image, int width, int height) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int pixel_value = image[y][x];
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
        case 4:
          printf(".... ");
          break;
        case 5:
          printf("..... ");
          break;
        case 6:
          printf("...... ");
          break;
        case 7:
          printf("------- ");
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
  image[0][4] = 5;
  image[0][5] = 6;
  image[0][6] = 7;
  image[0][7] = 1;
  image[0][8] = 2;
  image[0][9] = 3;

  image[1][0] = 2;
  image[1][1] = 3;
  image[1][2] = 4;
  image[1][3] = 5;
  image[1][4] = 6;
  image[1][5] = 7;
  image[1][6] = 1;
  image[1][7] = 2;
  image[1][8] = 3;
  image[1][9] = 4;

  image_to_ascii(image, 10, 2);

  free(image);

  return 0;
}