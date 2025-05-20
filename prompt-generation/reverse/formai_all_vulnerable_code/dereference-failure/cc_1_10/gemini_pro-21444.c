//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STRING_SIZE 100
#define MAX_COMPRESSED_STRING_SIZE (MAX_STRING_SIZE * 2)

char *compressString(char *string) {
  int i, j, k, count;
  char *compressedString = (char *)malloc(MAX_COMPRESSED_STRING_SIZE);

  k = 0;
  for (i = 0; i < strlen(string); i++) {
    count = 1;
    while (string[i] == string[i + 1]) {
      count++;
      i++;
    }
    compressedString[k++] = string[i];
    compressedString[k++] = count + '0';
  }
  compressedString[k] = '\0';

  return compressedString;
}

char *decompressString(char *compressedString) {
  int i, j, k, count;
  char *decompressedString = (char *)malloc(MAX_STRING_SIZE);

  k = 0;
  for (i = 0; i < strlen(compressedString); i++) {
    count = compressedString[i + 1] - '0';
    for (j = 0; j < count; j++) {
      decompressedString[k++] = compressedString[i];
    }
    i++;
  }
  decompressedString[k] = '\0';

  return decompressedString;
}

int main() {
  char string[MAX_STRING_SIZE];
  char *compressedString;
  char *decompressedString;

  printf("Enter a string to compress: ");
  scanf("%s", string);

  compressedString = compressString(string);

  printf("Compressed string: %s\n", compressedString);

  decompressedString = decompressString(compressedString);

  printf("Decompressed string: %s\n", decompressedString);

  return 0;
}