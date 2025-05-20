//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char **ascii_art = malloc(5 * sizeof(char *));
  ascii_art[0] = malloc(10 * sizeof(char));
  ascii_art[1] = malloc(10 * sizeof(char));
  ascii_art[2] = malloc(10 * sizeof(char));
  ascii_art[3] = malloc(10 * sizeof(char));
  ascii_art[4] = malloc(10 * sizeof(char));

  ascii_art[0][0] = 219;
  ascii_art[0][1] = 219;
  ascii_art[0][2] = 219;
  ascii_art[0][3] = 219;
  ascii_art[0][4] = 219;
  ascii_art[0][5] = 219;
  ascii_art[0][6] = 219;
  ascii_art[0][7] = 219;
  ascii_art[0][8] = 219;
  ascii_art[0][9] = 219;

  ascii_art[1][0] = 219;
  ascii_art[1][1] = 219;
  ascii_art[1][2] = 219;
  ascii_art[1][3] = 219;
  ascii_art[1][4] = 219;
  ascii_art[1][5] = 219;
  ascii_art[1][6] = 219;
  ascii_art[1][7] = 219;
  ascii_art[1][8] = 219;
  ascii_art[1][9] = 219;

  ascii_art[2][0] = 219;
  ascii_art[2][1] = 219;
  ascii_art[2][2] = 219;
  ascii_art[2][3] = 219;
  ascii_art[2][4] = 219;
  ascii_art[2][5] = 219;
  ascii_art[2][6] = 219;
  ascii_art[2][7] = 219;
  ascii_art[2][8] = 219;
  ascii_art[2][9] = 219;

  ascii_art[3][0] = 219;
  ascii_art[3][1] = 219;
  ascii_art[3][2] = 219;
  ascii_art[3][3] = 219;
  ascii_art[3][4] = 219;
  ascii_art[3][5] = 219;
  ascii_art[3][6] = 219;
  ascii_art[3][7] = 219;
  ascii_art[3][8] = 219;
  ascii_art[3][9] = 219;

  ascii_art[4][0] = 219;
  ascii_art[4][1] = 219;
  ascii_art[4][2] = 219;
  ascii_art[4][3] = 219;
  ascii_art[4][4] = 219;
  ascii_art[4][5] = 219;
  ascii_art[4][6] = 219;
  ascii_art[4][7] = 219;
  ascii_art[4][8] = 219;
  ascii_art[4][9] = 219;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%c ", ascii_art[i][j]);
    }
    printf("\n");
  }

  free(ascii_art[0]);
  free(ascii_art[1]);
  free(ascii_art[2]);
  free(ascii_art[3]);
  free(ascii_art[4]);
  free(ascii_art);

  return 0;
}