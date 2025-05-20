//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void text_to_ascii(char *text) {
  int i, j, k, l, height, width;
  char **ascii_art = NULL;

  height = 10;
  width = 20;
  ascii_art = (char **)malloc(height * sizeof(char *) + width * sizeof(char));

  for (i = 0; i < height; i++) {
    ascii_art[i] = (char *)malloc(width * sizeof(char));
  }

  l = 0;
  for (i = 0; text[i] != '\0'; i++) {
    switch (text[i]) {
      case 'a':
      case 'A':
        ascii_art[l][0] = 97;
        ascii_art[l][1] = 114;
        ascii_art[l][2] = 101;
        break;
      case 'b':
      case 'B':
        ascii_art[l][0] = 98;
        ascii_art[l][1] = 114;
        ascii_art[l][2] = 101;
        break;
      case 'c':
      case 'C':
        ascii_art[l][0] = 99;
        ascii_art[l][1] = 114;
        ascii_art[l][2] = 101;
        break;
      case 'd':
      case 'D':
        ascii_art[l][0] = 100;
        ascii_art[l][1] = 114;
        ascii_art[l][2] = 101;
        break;
      case 'e':
      case 'E':
        ascii_art[l][0] = 101;
        ascii_art[l][1] = 114;
        ascii_art[l][2] = 101;
        break;
      default:
        ascii_art[l][0] = 32;
    }

    l++;
  }

  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      printf("%c ", ascii_art[i][j]);
    }
    printf("\n");
  }

  free(ascii_art);
}

int main() {
  char text[] = "HELLO WORLD!";
  text_to_ascii(text);

  return 0;
}