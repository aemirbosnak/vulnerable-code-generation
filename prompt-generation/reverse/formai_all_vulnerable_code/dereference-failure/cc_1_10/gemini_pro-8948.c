//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char text[256];
  int width, height;
  int i, j, k;
  float scale = 1.0;

  printf("Enter text: ");
  fgets(text, sizeof(text), stdin);

  printf("Enter width: ");
  scanf("%d", &width);

  printf("Enter height: ");
  scanf("%d", &height);

  if (width <= 0 || height <= 0) {
    printf("Invalid width or height\n");
    return 1;
  }

  if (strlen(text) > width * height) {
    printf("Text too long\n");
    return 1;
  }

  char *bitmap = malloc(width * height);
  if (bitmap == NULL) {
    printf("Could not allocate memory\n");
    return 1;
  }

  memset(bitmap, ' ', width * height);

  for (i = 0; i < strlen(text); i++) {
    int x = i % width;
    int y = i / width;

    bitmap[x + y * width] = text[i];
  }

  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      if (scale == 1.0) {
        printf("%c", bitmap[j + i * width]);
      } else {
        for (k = 0; k < scale; k++) {
          printf("%c", bitmap[j + i * width]);
        }
      }
    }
    printf("\n");
  }

  free(bitmap);

  return 0;
}