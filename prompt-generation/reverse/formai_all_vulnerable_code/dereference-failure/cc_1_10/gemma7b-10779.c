//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

void compress(char **buf, int **size) {
  int i, j, k = 0, count = 1, run_length = 1;
  char prev_char = buf[0];

  for (i = 1; buf[i] != '\0'; i++) {
    if (buf[i] == prev_char) {
      run_length++;
    } else {
      prev_char = buf[i];
      if (run_length > 1) {
        *size -= run_length - 1;
        for (j = k; j < k + run_length - 1; j++) {
          buf[j] = count - 1;
        }
        count = 1;
      }
    }
  }

  if (run_length > 1) {
    *size -= run_length - 1;
    for (i = k; i < k + run_length - 1; i++) {
      buf[i] = count - 1;
    }
  }

  prev_char = buf[0];
  count = 1;
  run_length = 1;

  for (i = 0; buf[i] != '\0'; i++) {
    if (buf[i] == prev_char) {
      run_length++;
    } else {
      prev_char = buf[i];
      if (run_length > 1) {
        *size -= run_length - 1;
        for (j = k; j < k + run_length - 1; j++) {
          buf[j] = count - 1;
        }
        count = 1;
      }
    }
  }

  return;
}

int main() {
  char *buf = "aabbbbcaaaabbbb";
  int size = 13;

  compress(&buf, &size);

  printf("Compressed size: %d\n", size);

  return 0;
}