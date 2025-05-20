//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct {
  char ch;
  int count;
} CharCount;

// Compare two CharCount structures by count
int compareCharCount(const void *a, const void *b) {
  CharCount *c1 = (CharCount *)a;
  CharCount *c2 = (CharCount *)b;
  return c2->count - c1->count;
}

// Compress a string using run-length encoding
char *compress(const char *str) {
  int len = strlen(str);
  CharCount charCounts[MAX_LEN];
  int numCharCounts = 0;

  // Count the occurrences of each character
  for (int i = 0; i < len; i++) {
    int found = 0;
    for (int j = 0; j < numCharCounts; j++) {
      if (charCounts[j].ch == str[i]) {
        charCounts[j].count++;
        found = 1;
        break;
      }
    }
    if (!found) {
      charCounts[numCharCounts].ch = str[i];
      charCounts[numCharCounts].count = 1;
      numCharCounts++;
    }
  }

  // Sort the character counts in decreasing order of count
  qsort(charCounts, numCharCounts, sizeof(CharCount), compareCharCount);

  // Create the compressed string
  int compressedLen = 0;
  for (int i = 0; i < numCharCounts; i++) {
    compressedLen += strlen(charCounts[i].ch) + snprintf(NULL, 0, "%d", charCounts[i].count);
  }

  char *compressedStr = malloc(compressedLen + 1);
  int pos = 0;
  for (int i = 0; i < numCharCounts; i++) {
    pos += sprintf(compressedStr + pos, "%s%d", charCounts[i].ch, charCounts[i].count);
  }
  compressedStr[compressedLen] = '\0';

  return compressedStr;
}

// Decompress a string compressed using run-length encoding
char *decompress(const char *str) {
  int len = strlen(str);
  int decompressedLen = 0;

  // Calculate the decompressed length
  for (int i = 0; i < len; i++) {
    while (isdigit(str[i])) {
      i++;
    }
    decompressedLen++;
  }

  char *decompressedStr = malloc(decompressedLen + 1);
  int pos = 0;
  int num = 0;
  for (int i = 0; i < len; i++) {
    if (isdigit(str[i])) {
      num = num * 10 + str[i] - '0';
    } else {
      for (int j = 0; j < num; j++) {
        decompressedStr[pos++] = str[i];
      }
      num = 0;
    }
  }
  decompressedStr[decompressedLen] = '\0';

  return decompressedStr;
}

int main() {
  char *str = "AAABBBCCC";
  printf("Original string: %s\n", str);

  char *compressedStr = compress(str);
  printf("Compressed string: %s\n", compressedStr);

  char *decompressedStr = decompress(compressedStr);
  printf("Decompressed string: %s\n", decompressedStr);

  free(compressedStr);
  free(decompressedStr);

  return 0;
}