//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <text>\n", argv[0]);
    return 1;
  }

  char *text = argv[1];
  int width = strlen(text);
  int height = 1;

  // Calculate the height of the text
  for (int i = 0; i < width; i++) {
    if (text[i] == '\n') {
      height++;
    }
  }

  // Create a 2D array to store the ASCII art
  char **art = malloc(sizeof(char *) * height);
  for (int i = 0; i < height; i++) {
    art[i] = malloc(sizeof(char) * (width + 1));
  }

  // Convert the text to ASCII art
  int x = 0;
  int y = 0;
  for (int i = 0; i < width; i++) {
    if (text[i] == '\n') {
      y++;
      x = 0;
    } else {
      art[y][x] = text[i];
      x++;
    }
  }

  // Print the ASCII art
  for (int i = 0; i < height; i++) {
    printf("%s\n", art[i]);
  }

  // Free the memory
  for (int i = 0; i < height; i++) {
    free(art[i]);
  }
  free(art);

  return 0;
}