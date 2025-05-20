//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPRESSED_SIZE 1024

char *compress(char *input) {
  int input_length = strlen(input);
  char *compressed = malloc(MAX_COMPRESSED_SIZE);
  int compressed_length = 0;

  int current_char_count = 1;
  for (int i = 1; i < input_length; i++) {
    if (input[i] == input[i - 1]) {
      current_char_count++;
    } else {
      compressed[compressed_length++] = input[i - 1];
      compressed[compressed_length++] = current_char_count + '0';
      current_char_count = 1;
    }
  }

  compressed[compressed_length++] = input[input_length - 1];
  compressed[compressed_length++] = current_char_count + '0';

  return compressed;
}

char *decompress(char *compressed) {
  int compressed_length = strlen(compressed);
  char *decompressed = malloc(MAX_COMPRESSED_SIZE);
  int decompressed_length = 0;

  int current_char_count = 0;
  for (int i = 1; i < compressed_length; i++) {
    if (compressed[i] >= '0' && compressed[i] <= '9') {
      current_char_count = current_char_count * 10 + (compressed[i] - '0');
    } else {
      for (int j = 0; j < current_char_count; j++) {
        decompressed[decompressed_length++] = compressed[i - 1];
      }
      current_char_count = 0;
    }
  }

  return decompressed;
}

int main() {
  char *input = "AAABBBCCCDDD";
  char *compressed = compress(input);
  char *decompressed = decompress(compressed);

  printf("Original string: %s\n", input);
  printf("Compressed string: %s\n", compressed);
  printf("Decompressed string: %s\n", decompressed);

  return 0;
}