//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: ephemeral
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

char *compress(char *str) {
  char *compressed = (char *)malloc(MAX_SIZE * sizeof(char));
  int count = 1;
  char last = str[0];
  int index = 0;

  for (int i = 1; i < strlen(str); i++) {
    if (str[i] == last) {
      count++;
    } else {
      compressed[index++] = last;
      compressed[index++] = '0' + count;
      count = 1;
      last = str[i];
    }
  }

  compressed[index++] = last;
  compressed[index++] = '0' + count;

  return compressed;
}

char *decompress(char *compressed) {
  char *decompressed = (char *)malloc(MAX_SIZE * sizeof(char));
  int count = 0;
  int index = 0;

  for (int i = 0; i < strlen(compressed); i++) {
    if (compressed[i] <= '9' && compressed[i] >= '0') {
      count = count * 10 + (compressed[i] - '0');
    } else {
      for (int j = 0; j < count; j++) {
        decompressed[index++] = compressed[i];
      }
      count = 0;
    }
  }

  return decompressed;
}

int main() {
  char str[] = "aabcccccaaa";
  char *compressed = compress(str);
  printf("Compressed: %s\n", compressed);

  char *decompressed = decompress(compressed);
  printf("Decompressed: %s\n", decompressed);

  return 0;
}