//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a character to ASCII art
char *char_to_ascii(char c) {
  char *art[] = {
    "  ____  ",
    " |__  | |",
    "   / /  |",
    "  / /_  |",
    " /____| |",
    "|______/ "
  };

  // Return the ASCII art for the given character
  return art[c - 'A'];
}

// Function to convert a string to ASCII art
char *string_to_ascii(char *str) {
  // Allocate memory for the ASCII art
  char *art = malloc(strlen(str) * 6 + 1);

  // Convert each character to ASCII art and concatenate it to the art string
  for (int i = 0; i < strlen(str); i++) {
    strcat(art, char_to_ascii(str[i]));
  }

  // Add a newline character to the end of the art string
  strcat(art, "\n");

  // Return the ASCII art
  return art;
}

// Main function
int main() {
  // Get the input string from the user
  char str[100];
  printf("Enter a string: ");
  scanf("%s", str);

  // Convert the string to ASCII art
  char *art = string_to_ascii(str);

  // Print the ASCII art
  printf("\n%s", art);

  // Free the memory allocated for the ASCII art
  free(art);

  return 0;
}