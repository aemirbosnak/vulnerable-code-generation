//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a character to ASCII art
char *char_to_ascii(char c) {
  // Array of ASCII art characters
  char *ascii_chars[] = {
    " _   _ ",
    "| | | |",
    "| |_| |",
    "|  _  |",
    "|_| |_|",
    "   | | ",
    "  _| | ",
    " |_  | ",
    "   | | ",
    "  _| | "
  };

  // Return the ASCII art character for the given character
  return ascii_chars[c - '0'];
}

// Function to convert a string to ASCII art
char *string_to_ascii(char *str) {
  // Allocate memory for the ASCII art string
  char *ascii_str = malloc(strlen(str) * 7 + 1);

  // Convert each character in the string to ASCII art
  int i;
  for (i = 0; i < strlen(str); i++) {
    strcat(ascii_str, char_to_ascii(str[i]));
  }

  // Add a newline character to the end of the ASCII art string
  strcat(ascii_str, "\n");

  // Return the ASCII art string
  return ascii_str;
}

// Main function
int main() {
  // Get the input string from the user
  char str[100];
  printf("Enter a string: ");
  scanf("%s", str);

  // Convert the string to ASCII art
  char *ascii_str = string_to_ascii(str);

  // Print the ASCII art string
  printf("%s", ascii_str);

  // Free the memory allocated for the ASCII art string
  free(ascii_str);

  return 0;
}