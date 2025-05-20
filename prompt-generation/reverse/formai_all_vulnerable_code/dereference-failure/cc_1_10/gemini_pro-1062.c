//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

char *compress(char *str) {
  int len = strlen(str);
  char *compressed = malloc(len);
  int i, j, k;
  for (i = 0, j = 0, k = 0; i < len; i++) {
    if (str[i] == str[i + 1]) {
      compressed[j++] = str[i];
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

char *decompress(char *str) {
  int len = strlen(str);
  char *decompressed = malloc(len * 2);
  int i, j, k;
  for (i = 0, j = 0, k = 0; i < len; i++) {
    if (str[i] <= '9' && str[i] >= '0') {
      k = k * 10 + str[i] - '0';
    } else {
      while (k--) {
        decompressed[j++] = str[i];
      }
      k = 0;
    }
  }
  decompressed[j] = '\0';
  return decompressed;
}

int main() {
  char str[] = "AABBCCDD";
  char *compressed = compress(str);
  printf("Compressed: %s\n", compressed);
  char *decompressed = decompress(compressed);
  printf("Decompressed: %s\n", decompressed);
  return 0;
}