//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

int main() {
  int x, y, w, h;
  char **img = NULL;

  printf("Enter image width: ");
  scanf("%d", &w);

  printf("Enter image height: ");
  scanf("%d", &h);

  img = (char **)malloc(h * sizeof(char *) + 1);
  for (y = 0; y < h; y++) {
    img[y] = (char *)malloc(w * sizeof(char) + 1);
  }

  // Get image data
  printf("Enter image data (separate pixels with spaces): ");
  scanf("%s", img[0]);

  // Convert image to ASCII art
  for (y = 0; y < h; y++) {
    for (x = 0; x < w; x++) {
      int pixel = img[y][x];
      switch (pixel) {
        case 0:
          printf(" ");
          break;
        case 1:
          printf(". ");
          break;
        case 2:
          printf("* ");
          break;
        case 3:
          printf("# ");
          break;
      }
    }
    printf("\n");
  }

  // Free memory
  for (y = 0; y < h; y++) {
    free(img[y]);
  }
  free(img);

  return 0;
}