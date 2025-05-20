//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str[] = "The quick brown fox jumps over the lazy dog.";
  int i, len = strlen(str);
  int compressed_size = 0;
  char **compressed_str = NULL;

  // Calculate the number of unique characters
  int unique_chars = 0;
  for (i = 0; i < len; i++) {
    char letter = str[i];
    if (!unique_chars || letter != compressed_str[unique_chars - 1]) {
      unique_chars++;
    }
  }

  // Allocate memory for compressed string
  compressed_str = malloc(unique_chars * sizeof(char *));

  // Compress the string
  for (i = 0; i < len; i++) {
    char letter = str[i];
    int occurrences = 0;
    for (int j = 0; j < i; j++) {
      if (letter == str[j]) {
        occurrences++;
      }
    }
    compressed_str[compressed_size++] = letter;
    if (occurrences > 1) {
      compressed_str[compressed_size++] = occurrences - 1;
    }
  }

  // Print the compressed string
  printf("Compressed string: ");
  for (i = 0; i < compressed_size; i++) {
    printf("%c", compressed_str[i]);
  }

  printf("\n");

  // Free memory
  free(compressed_str);

  return 0;
}