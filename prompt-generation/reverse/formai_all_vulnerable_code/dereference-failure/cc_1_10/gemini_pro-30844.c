//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

char *text_to_ascii(char *text, int width, int height) {
  int text_len = strlen(text);
  int num_cols = (width + 1) / 8;
  int num_rows = (height + 7) / 8;
  int num_bytes = num_cols * num_rows;
  char *ascii_art = malloc(num_bytes);
  memset(ascii_art, 0, num_bytes);
  for (int i = 0; i < text_len; i++) {
    int char_index = text[i] - 32;
    int byte_index = char_index / 8;
    int bit_index = char_index % 8;
    ascii_art[byte_index] |= (1 << bit_index);
  }
  return ascii_art;
}

void print_ascii_art(char *ascii_art, int width, int height) {
  int num_cols = (width + 1) / 8;
  int num_rows = (height + 7) / 8;
  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_cols; j++) {
      int byte_index = i * num_cols + j;
      char byte = ascii_art[byte_index];
      for (int k = 0; k < 8; k++) {
        if ((byte & (1 << k)) != 0) {
          printf("#");
        } else {
          printf(" ");
        }
      }
    }
    printf("\n");
  }
}

int main() {
  char *text = "Hello, world!";
  int width = 80;
  int height = 25;
  char *ascii_art = text_to_ascii(text, width, height);
  print_ascii_art(ascii_art, width, height);
  free(ascii_art);
  return 0;
}