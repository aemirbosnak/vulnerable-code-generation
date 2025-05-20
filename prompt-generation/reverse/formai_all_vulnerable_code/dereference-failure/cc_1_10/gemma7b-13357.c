//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void image_to_ascii(unsigned char **image, int width, int height) {
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
          printf("$");
          break;
        case 3:
          printf("@");
          break;
        case 4:
          printf("#");
          break;
        case 5:
          printf("%");
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
  unsigned char **image = NULL;
  int width = 5;
  int height = 5;

  image = (unsigned char **)malloc(height * sizeof(unsigned char *) + height);
  for (int y = 0; y < height; y++) {
    image[y] = (unsigned char *)malloc(width * sizeof(unsigned char) + width);
  }

  // Fill the image with pixel values
  image[2][2] = 3;
  image[1][1] = 2;
  image[0][0] = 1;
  image[3][3] = 4;

  image_to_ascii(image, width, height);

  free(image);

  return 0;
}