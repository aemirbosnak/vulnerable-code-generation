//FormAI DATASET v1.0 Category: Compression algorithms ; Style: lively
// Welcome to our unique C compression algorithm!
// This program takes a string as input and compresses it
// by replacing consecutive identical characters with a count

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// This function takes a string and compresses it
// by replacing consecutive identical characters with a count
char* compress(char* str) {

  if (str == NULL || strlen(str) == 0) {
    return str;
  }

  int n = strlen(str);
  char* compressed = (char*) malloc((n + 1) * sizeof(char));
  compressed[0] = str[0];
  int count = 1;
  int j = 1;

  for (int i = 1; i < n; i++) {
    if (str[i] == str[i - 1]) {
      count++;
    } else {
      compressed[j++] = count + '0';
      compressed[j++] = str[i];
      count = 1;
    }
  }

  compressed[j++] = count + '0';
  compressed[j] = '\0';

  return compressed;
}

// This is the main function
int main() {

  printf("Please enter the string you'd like to compress:\n");
  char input[100];
  fgets(input, 100, stdin);

  // Remove new line character if present
  if (input[strlen(input) - 1] == '\n') {
     input[strlen(input) - 1] = '\0';
  }

  printf("Original string: %s\n", input);

  char* compressed = compress(input);

  printf("Compressed string: %s\n", compressed);

  free(compressed);

  return 0;
}