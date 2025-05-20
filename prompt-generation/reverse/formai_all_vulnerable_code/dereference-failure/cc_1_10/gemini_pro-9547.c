//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

int main(int argc, char *argv[]) {
  char *input;
  int len;
  int i;
  int j;
  int k;
  int l;
  int m;
  int n;
  int o;
  int p;
  int q;
  int r;
  int s;
  int t;
  int u;
  int v;
  int w;
  int x;
  int y;
  int z;

  if (argc != 2) {
    printf("Usage: %s <binary number>\n", argv[0]);
    return EXIT_FAILURE;
  }

  input = argv[1];
  len = strlen(input);

  if (len > MAX_LEN) {
    printf("Input too long.\n");
    return EXIT_FAILURE;
  }

  for (i = 0; i < len; i++) {
    if (input[i] != '0' && input[i] != '1') {
      printf("Invalid binary number.\n");
      return EXIT_FAILURE;
    }
  }

  j = 0;
  k = 1;
  l = 0;
  m = 0;
  n = 0;
  o = 0;
  p = 0;
  q = 0;
  r = 0;
  s = 0;
  t = 0;
  u = 0;
  v = 0;
  w = 0;
  x = 0;
  y = 0;
  z = 0;

  for (i = len - 1; i >= 0; i--) {
    if (input[i] == '1') {
      j += k;
    }
    k *= 2;
  }

  printf("%d\n", j);

  return EXIT_SUCCESS;
}