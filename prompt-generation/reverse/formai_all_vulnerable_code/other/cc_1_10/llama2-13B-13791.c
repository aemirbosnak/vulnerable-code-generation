//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024
#define MAGIC_NUMBER 0xA5E7B7B5

// Compression function
void compress(char *input, int length, char *output) {
  int i, j, k;
  char *p, *q;
  int count = 0;

  // Step 1: Initialize the output buffer
  memset(output, 0, MAX_LENGTH);

  // Step 2: Find the first occurrence of each character
  for (i = 0; i < length; i++) {
    p = &input[i];
    count = 0;
    while (i + count < length && input[i + count] == p[count]) {
      count++;
    }
    output[count] = p[0];
  }

  // Step 3: Replace each character with its count
  for (i = 0; i < length; i++) {
    p = &input[i];
    count = 0;
    for (j = 0; j < count; j++) {
      q = &output[j];
      if (*q == *p) {
        count++;
        *q = (char)((MAGIC_NUMBER * count) % 256);
      }
    }
  }

  // Step 4: Output the compressed data
  for (i = 0; i < length; i++) {
    printf("%c", output[i]);
  }
}

// Decompression function
void decompress(char *input, int length, char *output) {
  int i, j, k;
  char *p, *q;
  int count = 0;

  // Step 1: Initialize the output buffer
  memset(output, 0, MAX_LENGTH);

  // Step 2: Find the first occurrence of each character
  for (i = 0; i < length; i++) {
    p = &input[i];
    count = 0;
    while (i + count < length && input[i + count] == p[count]) {
      count++;
    }
    output[count] = p[0];
  }

  // Step 3: Replace each character with its original value
  for (i = 0; i < length; i++) {
    p = &input[i];
    count = 0;
    for (j = 0; j < count; j++) {
      q = &output[j];
      if (*q == (char)((MAGIC_NUMBER * count) % 256)) {
        count++;
        *q = *p;
      }
    }
  }

  // Step 4: Output the decompressed data
  for (i = 0; i < length; i++) {
    printf("%c", output[i]);
  }
}

int main() {
  char input[] = "Hello World!";
  int length = strlen(input);
  char output[MAX_LENGTH];

  compress(input, length, output);
  printf("Compressed data: ");
  for (int i = 0; i < length; i++) {
    printf("%c", output[i]);
  }
  printf("\n");

  decompress(output, length, input);
  printf("Decompressed data: ");
  for (int i = 0; i < length; i++) {
    printf("%c", input[i]);
  }
  printf("\n");

  return 0;
}