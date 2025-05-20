//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s <text>\n", argv[0]);
    return 1;
  }

  char *text = argv[1];
  int width = strlen(text);
  int height = 1;

  int i, j;
  for (i = 0; i < width; i++) {
    if (text[i] == '\n') {
      height++;
    }
  }

  if (width > MAX_WIDTH || height > MAX_HEIGHT) {
    printf("Error: Text too large. Maximum width is %d, maximum height is %d.\n", MAX_WIDTH, MAX_HEIGHT);
    return 1;
  }

  char *ascii = malloc(width * height + 1);
  memset(ascii, ' ', width * height);
  ascii[width * height] = '\0';

  int index = 0;
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      if (text[index] != '\n') {
        ascii[i * width + j] = text[index];
      }
      index++;
    }
  }

  for (i = 0; i < height; i++) {
    printf("%s\n", ascii + i * width);
  }

  free(ascii);

  return 0;
}