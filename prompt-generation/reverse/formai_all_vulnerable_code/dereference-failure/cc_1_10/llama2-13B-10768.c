//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024
#define MAGIC_NUMBER 0xDEADBEEF

void compress(char *input, int len) {
  int i, j, k;
  char *output = malloc(len * 2);
  for (i = 0; i < len; i++) {
    if (input[i] == 'a' || input[i] == 'e' || input[i] == 'o') {
      output[j] = input[i];
      j++;
      while (j < len && input[j] == 'a' || input[j] == 'e' || input[j] == 'o') {
        j++;
      }
      output[j] = '\0';
    } else {
      output[j] = input[i];
      j++;
    }
  }
  printf("Compressed string: %s\n", output);
}

void decompress(char *compressed, int len) {
  int i, j;
  char *output = malloc(len);
  for (i = 0; i < len; i++) {
    if (compressed[i] == 'a' || compressed[i] == 'e' || compressed[i] == 'o') {
      j = i + 1;
      while (j < len && compressed[j] == 'a' || compressed[j] == 'e' || compressed[j] == 'o') {
        j++;
      }
      output[i] = compressed[j];
    } else {
      output[i] = compressed[i];
    }
  }
  printf("Decompressed string: %s\n", output);
}

int main() {
  char input[] = "Hello World!";
  int len = strlen(input);
  compress(input, len);
  decompress(input, len);
  return 0;
}