//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARG_COUNT 3
#define BUF_SIZE 1000
#define HASH_SIZE 16

unsigned char *hash(const char *input, size_t len) {
  unsigned char *result = malloc(HASH_SIZE);
  if (!result) {
    return NULL;
  }

  unsigned int h = 0, g;
  for (size_t i = 0; i < len; i++) {
    h += input[i];
    g = h << 5 - h >> 3;
    h ^= g;
  }

  for (size_t i = 0; i < HASH_SIZE; i++) {
    result[i] = (h >> (8 * (HASH_SIZE - 1 - i))) & 0xFF;
  }

  return result;
}

int main(int argc, char *argv[]) {
  if (argc != ARG_COUNT) {
    printf("Usage: %s <input_file> <output_file>\n", argv[0]);
    return 1;
  }

  FILE *input = fopen(argv[1], "r");
  if (!input) {
    perror("fopen");
    return 1;
  }

  fseek(input, 0, SEEK_END);
  size_t len = ftell(input);
  fseek(input, 0, SEEK_SET);

  char *buf = malloc(len + 1);
  if (!buf) {
    perror("malloc");
    return 1;
  }

  fread(buf, 1, len, input);
  buf[len] = '\0';
  fclose(input);

  unsigned char *result = hash(buf, len);
  free(buf);

  if (!result) {
    perror("hash");
    return 1;
  }

  FILE *output = fopen(argv[2], "w");
  if (!output) {
    perror("fopen");
    return 1;
  }

  fwrite(result, 1, HASH_SIZE, output);
  fclose(output);
  free(result);

  return 0;
}