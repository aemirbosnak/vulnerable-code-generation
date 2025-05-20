//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

#define FOREGROUND_COLOR "\x1b[38;5;255m"
#define BACKGROUND_COLOR "\x1b[48;5;0m"
#define RESET_COLOR "\x1b[0m"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <text>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *text = argv[1];
  int width = strlen(text);
  int height = 1;

  // Create a 2D array of characters to represent the ASCII art
  char **art = malloc(height * sizeof(char *));
  for (int i = 0; i < height; i++) {
    art[i] = malloc(width * sizeof(char));
  }

  // Fill the array with spaces
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      art[i][j] = ' ';
    }
  }

  // Draw the text in the center of the array
  int start_x = (width - strlen(text)) / 2;
  int start_y = (height - 1) / 2;
  for (int i = 0; i < strlen(text); i++) {
    art[start_y][start_x + i] = text[i];
  }

  // Print the ASCII art to the console
  for (int i = 0; i < height; i++) {
    printf("%s%s%s\n", FOREGROUND_COLOR, art[i], RESET_COLOR);
  }

  // Free the memory allocated for the ASCII art
  for (int i = 0; i < height; i++) {
    free(art[i]);
  }
  free(art);

  return EXIT_SUCCESS;
}