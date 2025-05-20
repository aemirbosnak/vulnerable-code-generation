//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

void print_art(char **art, int width, int height) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", art[i][j]);
    }
    printf("\n");
  }
}

void generate_art(char *text, int width, int height, char **art) {
  int char_idx = 0;
  int row = 0;
  int col = 0;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (char_idx < strlen(text)) {
        art[i][j] = text[char_idx++];
      } else {
        art[i][j] = ' ';
      }
    }
  }
}

int main() {
  char *text = "Hello, world!";
  int width = MAX_WIDTH;
  int height = MAX_HEIGHT;

  char **art = malloc(sizeof(char *) * height);
  for (int i = 0; i < height; i++) {
    art[i] = malloc(sizeof(char) * width);
  }

  generate_art(text, width, height, art);
  print_art(art, width, height);

  for (int i = 0; i < height; i++) {
    free(art[i]);
  }
  free(art);

  return 0;
}