//FormAI DATASET v1.0 Category: Compression algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN_SIZE 100
#define OUT_SIZE 100

void compress(char in[], char out[]);

int main()
{
  char in[IN_SIZE], out[OUT_SIZE];

  printf("Enter a string to compress: ");
  fgets(in, IN_SIZE, stdin);

  compress(in, out);

  printf("Compressed string: %s", out);

  return 0;
}

void compress(char in[], char out[])
{
  int i, j, count;
  char prev, curr;

  prev = in[0];
  count = 1;
  j = 0;

  for (i = 1; i < strlen(in); i++) {
    curr = in[i];

    if (curr == prev) {
      count++;
    } else {
      out[j] = prev;
      j++;

      if (count > 1) {
        sprintf(&out[j], "%d", count);
        j += strlen(&out[j]);
      }

      prev = curr;
      count = 1;
    }
  }

  out[j] = prev;
  j++;

  if (count > 1) {
    sprintf(&out[j], "%d", count);
    j += strlen(&out[j]);
  }

  out[j] = '\0';
}