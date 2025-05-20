//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024

char **textToAsciiArt(const char *text, int width, int height);
void printAsciiArt(char **asciiArt);
void freeAsciiArt(char **asciiArt);

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("Usage: %s <text> <width>\n", argv[0]);
    return 1;
  }

  int width = atoi(argv[2]);
  if (width <= 0 || width > MAX_WIDTH) {
    printf("Invalid width: %d\n", width);
    return 1;
  }

  char **asciiArt = textToAsciiArt(argv[1], width, 0);
  if (asciiArt == NULL) {
    printf("Failed to generate ASCII art\n");
    return 1;
  }

  printAsciiArt(asciiArt);
  freeAsciiArt(asciiArt);

  return 0;
}

char **textToAsciiArt(const char *text, int width, int height) {
  // Calculate the height of the ASCII art
  if (height == 0) {
    height = strlen(text) / width + 1;
  }

  // Allocate memory for the ASCII art
  char **asciiArt = malloc(height * sizeof(char *));
  if (asciiArt == NULL) {
    return NULL;
  }
  for (int i = 0; i < height; i++) {
    asciiArt[i] = malloc(width + 1);
    if (asciiArt[i] == NULL) {
      for (int j = 0; j < i; j++) {
        free(asciiArt[j]);
      }
      free(asciiArt);
      return NULL;
    }
  }

  // Convert the text to ASCII art
  int index = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      asciiArt[i][j] = text[index++];
      if (text[index] == '\0') {
        break;
      }
    }
    asciiArt[i][width] = '\0';
  }

  return asciiArt;
}

void printAsciiArt(char **asciiArt) {
  for (int i = 0; asciiArt[i] != NULL; i++) {
    printf("%s\n", asciiArt[i]);
  }
}

void freeAsciiArt(char **asciiArt) {
  for (int i = 0; asciiArt[i] != NULL; i++) {
    free(asciiArt[i]);
  }
  free(asciiArt);
}