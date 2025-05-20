//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to convert a text string to ASCII art */
char *text_to_ascii(char *text) {
  int width = strlen(text) * 8;
  int height = 8;
  char *ascii = malloc(width * height);

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int index = y * width + x;
      ascii[index] = ' ';
    }
  }

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int index = y * width + x;
      int char_index = x / 8;
      int char_bit = 7 - (y % 8);
      char bit = text[char_index] & (1 << char_bit);
      if (bit) {
        ascii[index] = '#';
      }
    }
  }

  return ascii;
}

/* Function to print the ASCII art */
void print_ascii(char *ascii, int width, int height) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int index = y * width + x;
      printf("%c", ascii[index]);
    }
    printf("\n");
  }
}

/* Main function */
int main() {
  char *text = "Hello, ASCII art!";
  char *ascii = text_to_ascii(text);
  int width = strlen(text) * 8;
  int height = 8;
  print_ascii(ascii, width, height);
  free(ascii);
  return 0;
}