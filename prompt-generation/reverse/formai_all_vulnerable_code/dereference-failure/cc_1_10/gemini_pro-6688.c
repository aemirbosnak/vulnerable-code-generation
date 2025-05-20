//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

// This function compresses a string using a surrealist algorithm.
char* surrealist_compress(char* str) {
  int len = strlen(str);
  char* compressed_str = malloc(len + 1);
  int i, j;
  int curr_char_count = 0;
  int prev_char_count = 0;
  char prev_char = '\0';

  // Loop through the string and count the occurrences of each character.
  for (i = 0; i < len; i++) {
    if (str[i] == prev_char) {
      curr_char_count++;
    } else {
      if (prev_char != '\0') {
        compressed_str[j++] = prev_char;
        compressed_str[j++] = prev_char_count + '0';
      }
      prev_char = str[i];
      prev_char_count = 1;
      curr_char_count = 1;
    }
  }

  // Add the last character and its count to the compressed string.
  compressed_str[j++] = prev_char;
  compressed_str[j++] = prev_char_count + '0';

  // Terminate the compressed string.
  compressed_str[j] = '\0';

  return compressed_str;
}

// This function decompresses a string that was compressed using the surrealist algorithm.
char* surrealist_decompress(char* compressed_str) {
  int len = strlen(compressed_str);
  char* decompressed_str = malloc(len * 2 + 1);
  int i, j;
  int char_count;

  // Loop through the compressed string and decompress it.
  for (i = 0, j = 0; i < len; i += 2) {
    char_count = compressed_str[i + 1] - '0';
    for (int k = 0; k < char_count; k++) {
      decompressed_str[j++] = compressed_str[i];
    }
  }

  // Terminate the decompressed string.
  decompressed_str[j] = '\0';

  return decompressed_str;
}

int main() {
  // Get the input string from the user.
  char* input_str = malloc(MAX_BUF_SIZE);
  printf("Enter a string to compress: ");
  fgets(input_str, MAX_BUF_SIZE, stdin);

  // Compress the input string.
  char* compressed_str = surrealist_compress(input_str);

  // Print the compressed string.
  printf("Compressed string: %s", compressed_str);

  // Decompress the compressed string.
  char* decompressed_str = surrealist_decompress(compressed_str);

  // Print the decompressed string.
  printf("Decompressed string: %s", decompressed_str);

  // Free the allocated memory.
  free(input_str);
  free(compressed_str);
  free(decompressed_str);

  return 0;
}