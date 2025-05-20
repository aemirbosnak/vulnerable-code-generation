//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80

void draw_ascii_art(char **art, int h, int w) {
  for (int r = 0; r < h; r++) {
    for (int c = 0; c < w; c++) {
      printf("%c ", art[r][c]);
    }
    printf("\n");
  }
}

int main() {
  char **art = NULL;
  int h = 5, w = 10;

  art = malloc(h * sizeof(char *) + w * sizeof(char));
  for (int i = 0; i < h; i++) {
    art[i] = malloc(w * sizeof(char));
  }

  art[0][0] = '#';
  art[0][1] = '#';
  art[0][2] = '#';
  art[0][3] = '#';
  art[0][4] = '#';
  art[0][5] = '#';
  art[0][6] = '#';
  art[0][7] = '#';
  art[0][8] = '#';
  art[0][9] = '#';

  art[1][0] = '$';
  art[1][1] = '$';
  art[1][2] = '$';
  art[1][3] = '$';
  art[1][4] = '$';
  art[1][5] = '$';
  art[1][6] = '$';
  art[1][7] = '$';
  art[1][8] = '$';
  art[1][9] = '$';

  draw_ascii_art(art, h, w);

  for (int i = 0; i < h; i++) {
    free(art[i]);
  }
  free(art);

  return 0;
}