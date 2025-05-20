//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is a funny C compression algorithm that I made up.
// It's not very efficient, but it's funny!

#define MAX_CODE_SIZE 1024

// This function compresses a string using my funny algorithm.
char *compress(char *str) {
  char *code = malloc(MAX_CODE_SIZE);
  int code_size = 0;

  // Loop through the string one character at a time.
  for (int i = 0; i < strlen(str); i++) {
    // Get the current character.
    char c = str[i];

    // If we haven't seen this character before, add it to the code.
    if (strchr(code, c) == NULL) {
      code[code_size++] = c;
    }

    // Add the code for the current character to the output.
    code[code_size++] = c;
  }

  // Return the compressed string.
  return code;
}

// This function decompresses a string using my funny algorithm.
char *decompress(char *code) {
  char *str = malloc(strlen(code));
  int str_size = 0;

  // Loop through the code one character at a time.
  for (int i = 0; i < strlen(code); i++) {
    // Get the current character.
    char c = code[i];

    // If we haven't seen this character before, add it to the string.
    if (strchr(str, c) == NULL) {
      str[str_size++] = c;
    }

    // Add the character to the output.
    str[str_size++] = c;
  }

  // Return the decompressed string.
  return str;
}

// This function prints a string in a funny way.
void print_funny(char *str) {
  // Loop through the string one character at a time.
  for (int i = 0; i < strlen(str); i++) {
    // Get the current character.
    char c = str[i];

    // Print the character in a funny way.
    printf("%c%c", c, c);
  }

  // Print a newline.
  printf("\n");
}

// This is the main function.
int main() {
  // Get the input string from the user.
  char *str = NULL;
  size_t len = 0;
  getline(&str, &len, stdin);

  // Compress the string.
  char *code = compress(str);

  // Print the compressed string.
  printf("Compressed string: %s\n", code);

  // Decompress the string.
  char *str2 = decompress(code);

  // Print the decompressed string.
  printf("Decompressed string: %s\n", str2);

  // Print the string in a funny way.
  print_funny(str2);

  // Free the memory that we allocated.
  free(str);
  free(code);
  free(str2);

  return 0;
}