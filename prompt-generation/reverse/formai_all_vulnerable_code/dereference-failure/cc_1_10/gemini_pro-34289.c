//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_LEN 1024

char *compress(char *str) {
  int i, j, k;
  char *compressed = malloc(MAX_BUF_LEN);
  int len = strlen(str);

  for (i = 0, j = 0, k = 0; i < len; i++) {
    if (str[i] == str[i + 1]) {
      k++;
    } else {
      compressed[j++] = str[i];
      compressed[j++] = k + '0';
      k = 0;
    }
  }
  compressed[j] = '\0';
  return compressed;
}

char *decompress(char *compressed) {
  int i, j, k;
  char *decompressed = malloc(MAX_BUF_LEN);
  int len = strlen(compressed);

  for (i = 0, j = 0, k = 0; i < len; i++) {
    if (compressed[i] >= '0' && compressed[i] <= '9') {
      k = compressed[i] - '0';
      i++;
    } else {
      for (; k > 0; k--) {
        decompressed[j++] = compressed[i];
      }
    }
  }
  decompressed[j] = '\0';
  return decompressed;
}

int main() {
  char str[] = "aaaabbbccc";
  char *compressed = compress(str);
  char *decompressed = decompress(compressed);

  printf("Original string: %s\n", str);
  printf("Compressed string: %s\n", compressed);
  printf("Decompressed string: %s\n", decompressed);

  free(compressed);
  free(decompressed);
  return 0;
}