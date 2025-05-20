//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

void watermark(char **img, int w, int h, char **wm)
{
  int i, j, k, l, x, y;
  char **m = (char**)malloc(h * w * sizeof(char));
  for (i = 0; i < h; i++)
    for (j = 0; j < w; j++)
      m[i][j] = img[i][j];

  for (k = 0; wm[k] != '\0'; k++)
  {
    x = rand() % w;
    y = rand() % h;
    m[y][x] = wm[k];
  }

  for (i = 0; i < h; i++)
    for (j = 0; j < w; j++)
      img[i][j] = m[i][j];

  free(m);
}

int main()
{
  char **img = (char**)malloc(MAX * MAX * sizeof(char));
  for (int i = 0; i < MAX; i++)
    for (int j = 0; j < MAX; j++)
      img[i][j] = 0;

  char **wm = (char**)malloc(MAX * sizeof(char));
  wm[0] = 'A';
  wm[1] = 'B';
  wm[2] = 'C';
  wm[3] = '\0';

  watermark(img, MAX, MAX, wm);

  for (int i = 0; i < MAX; i++)
    for (int j = 0; j < MAX; j++)
      printf("%c ", img[i][j]);

  printf("\n");

  free(img);
  free(wm);

  return 0;
}