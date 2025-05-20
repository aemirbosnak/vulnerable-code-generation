//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

void img_to_ascii(char **img, int w, int h) {
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      int pixel_value = img[y][x];
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
  int w, h;

  printf("Enter the width and height of the image: ");
  scanf("%d %d", &w, &h);

  img = malloc(h * sizeof(char *) + 1);
  for (int i = 0; i < h; i++) {
    img[i] = malloc(w * sizeof(char) + 1);
  }

  printf("Enter the pixels of the image (separated by commas): ");
  scanf("%s", img[0]);

  img_to_ascii(img, w, h);

  for (int i = 0; i < h; i++) {
    free(img[i]);
  }
  free(img);

  return 0;
}