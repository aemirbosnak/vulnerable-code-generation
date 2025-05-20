//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the character set for the ASCII art
char *charset = " .,-~*#%&#@";

// Convert a character to its ASCII art representation
char *char_to_ascii(char c) {
  int index = (int)c % strlen(charset);
  return &charset[index];
}

// Convert a string to its ASCII art representation
char *string_to_ascii(char *str) {
  char *ascii_art = malloc(strlen(str) * 2 + 1);  // Allocate memory for the ASCII art
  int i;
  for (i = 0; i < strlen(str); i++) {
    strcat(ascii_art, char_to_ascii(str[i]));
    strcat(ascii_art, " ");  // Add a space between characters
  }
  ascii_art[strlen(ascii_art) - 1] = '\0';  // Remove the trailing space
  return ascii_art;
}

// Generate a random ASCII art string of a given length
char *random_ascii_art(int length) {
  char *ascii_art = malloc(length + 1);  // Allocate memory for the ASCII art
  int i;
  for (i = 0; i < length; i++) {
    ascii_art[i] = charset[rand() % strlen(charset)];
  }
  ascii_art[length] = '\0';  // Null-terminate the string
  return ascii_art;
}

// Print the ASCII art to the console
void print_ascii_art(char *ascii_art) {
  printf("%s\n", ascii_art);
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the input string from the user
  char input[100];
  printf("Enter a string to convert to ASCII art: ");
  scanf("%s", input);

  // Convert the string to ASCII art
  char *ascii_art = string_to_ascii(input);

  // Print the ASCII art to the console
  print_ascii_art(ascii_art);

  // Free the memory allocated for the ASCII art
  free(ascii_art);

  return 0;
}