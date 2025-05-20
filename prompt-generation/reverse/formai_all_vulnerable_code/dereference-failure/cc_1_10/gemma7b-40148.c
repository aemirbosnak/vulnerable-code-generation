//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void compress(char **buffer) {
  int i, j, count = 0, previous = 0, current = 0;
  char *compressed_buffer = NULL;

  for (i = 0; buffer[i] != '\0'; i++) {
    current = buffer[i];
    if (previous == current) {
      count++;
    } else {
      if (compressed_buffer) {
        free(compressed_buffer);
      }
      compressed_buffer = malloc(MAX_BUFFER_SIZE);
      compressed_buffer[0] = previous;
      compressed_buffer[1] = count;
      j = 2;
      while (compressed_buffer[j - 1] != '\0') {
        compressed_buffer[j] = buffer[i - count];
        j++;
      }
      previous = current;
      count = 1;
    }
  }

  free(compressed_buffer);
  *buffer = compressed_buffer;
}

int main() {
  char *buffer = malloc(MAX_BUFFER_SIZE);
  buffer[0] = 'a';
  buffer[1] = 'a';
  buffer[2] = 'b';
  buffer[3] = 'b';
  buffer[4] = 'c';
  buffer[5] = '\0';

  compress(&buffer);

  printf("%s", buffer);

  free(buffer);

  return 0;
}