//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void image_to_ascii(char **img, int w, int h) {
  int i, j, k, l;
  char pixel;
  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      pixel = img[i][j];
      switch (pixel) {
        case 0:
          printf(" ");
          break;
        case 1:
          printf(".");
          break;
        case 2:
          printf("=");
          break;
        case 3:
          printf("#");
          break;
      }
    }
    printf("\n");
  }
}

int main() {
  char **img = NULL;
  int w, h;

  printf("Enter image width: ");
  scanf("%d", &w);

  printf("Enter image height: ");
  scanf("%d", &h);

  img = (char **)malloc(h * sizeof(char *) + 1);
  for (int i = 0; i < h; i++) {
    img[i] = (char *)malloc(w * sizeof(char) + 1);
  }

  printf("Enter image data (separate pixels with space): ");
  scanf("%s", img[0]);

  image_to_ascii(img, w, h);

  free(img);
  return 0;
}