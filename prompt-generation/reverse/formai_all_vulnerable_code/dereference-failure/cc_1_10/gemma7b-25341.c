//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

void watermark(char **img, char **wm, int w)
{
  int i, j, k, l;
  for (i = 0; i < w; i++)
  {
    for (j = 0; j < MAX; j++)
    {
      k = rand() % MAX;
      l = rand() % MAX;
      img[i][j] ^= (wm[k][l] & 0x0F) << 2;
    }
  }
}

int main()
{
  char **img = NULL;
  char **wm = NULL;
  int w, h, i, j;

  printf("Enter image width: ");
  scanf("%d", &w);

  printf("Enter image height: ");
  scanf("%d", &h);

  img = (char *)malloc(h * w * MAX);
  wm = (char *)malloc(h * w * MAX);

  printf("Enter watermark data: ");
  scanf("%s", wm);

  watermark(img, wm, w);

  printf("Watermarked image:\n");
  for (i = 0; i < h; i++)
  {
    for (j = 0; j < w; j++)
    {
      printf("%x ", img[i][j]);
    }
    printf("\n");
  }

  return 0;
}