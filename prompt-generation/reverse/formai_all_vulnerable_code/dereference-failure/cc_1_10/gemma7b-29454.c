//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 80

void draw_ascii_art(char **arr, int h, int w) {
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      printf("%c ", arr[i][j]);
    }
    printf("\n");
  }
}

int main() {
  char **arr = NULL;
  int h = 5;
  int w = 10;

  arr = (char **)malloc(h * sizeof(char *) + w * sizeof(char));
  for (int i = 0; i < h; i++) {
    arr[i] = (char *)malloc(w * sizeof(char));
  }

  // Generate ASCII art
  arr[0][0] = 'H';
  arr[0][1] = 'A';
  arr[0][2] = 'R';
  arr[0][3] = 'D';

  arr[1][0] = 'A';
  arr[1][1] = 'R';
  arr[1][2] = 'T';
  arr[1][3] = 'A';

  arr[2][0] = 'N';
  arr[2][1] = 'C';
  arr[2][2] = 'A';

  arr[3][0] = 'O';
  arr[3][1] = 'P';
  arr[3][2] = 'L';

  arr[4][0] = 'A';
  arr[4][1] = 'S';
  arr[4][2] = 'C';

  draw_ascii_art(arr, h, w);

  free(arr);
  return 0;
}