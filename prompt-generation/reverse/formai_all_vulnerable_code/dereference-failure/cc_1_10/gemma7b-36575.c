//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

void compress(char **a, int *n) {
  int i, j, k, count = 0, l = 0, b[MAX], *c = NULL;

  for (i = 0; a[i] && i < *n; i++) {
    char current = a[i];
    int flag = 0;

    for (j = 0; b[j] && j < l; j++) {
      if (current == b[j]) {
        flag = 1;
        break;
      }
    }

    if (!flag) {
      b[l++] = current;
      count++;
    }
  }

  *n = l;
  c = malloc((*n) * sizeof(int));

  for (i = 0; i < l; i++) {
    c[i] = b[i];
  }

  free(a);
  a = c;
}

int main() {
  char *a = "aabbbbcccccaaa";
  int n = 13;

  compress(&a, &n);

  printf("Compressed data: ");
  for (int i = 0; a[i] && i < n; i++) {
    printf("%c ", a[i]);
  }

  printf("\nNumber of bytes saved: %d", n - 13);

  return 0;
}