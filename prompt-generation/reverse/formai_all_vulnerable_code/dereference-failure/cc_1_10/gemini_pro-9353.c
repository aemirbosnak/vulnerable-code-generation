//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80

// Function to convert a character to ASCII art
char *char_to_ascii(char c) {
  char *art[] = {
    "  ___  ",
    " |__ \\ ",
    "    ) |",
    "   / / ",
    "  / /_ ",
    " |____|",
  };

  if (c >= 'a' && c <= 'z') {
    return art[c - 'a'];
  } else if (c >= 'A' && c <= 'Z') {
    return art[c - 'A'];
  } else {
    return " ";
  }
}

// Function to convert a string to ASCII art
char *string_to_ascii(char *str) {
  char *art = malloc(strlen(str) * 6 + 1);
  int i;

  for (i = 0; i < strlen(str); i++) {
    strcat(art, char_to_ascii(str[i]));
  }

  return art;
}

// Function to print ASCII art
void print_ascii(char *art) {
  int i;

  for (i = 0; i < strlen(art); i += MAX_WIDTH) {
    printf("%.*s\n", MAX_WIDTH, art + i);
  }
}

// Main function
int main() {
  char *str = "Hello World!";
  char *art = string_to_ascii(str);

  print_ascii(art);

  free(art);

  return 0;
}