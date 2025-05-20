//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert text to ASCII art
char *text_to_ascii(char *text) {
  // Create a 2D array to store the ASCII art
  char **ascii_art = malloc(sizeof(char *) * 8);
  for (int i = 0; i < 8; i++) {
    ascii_art[i] = malloc(sizeof(char) * strlen(text) * 8);
  }

  // Convert each character in the text to ASCII art
  for (int i = 0; i < strlen(text); i++) {
    char character = text[i];
    int ascii_code = (int)character;

    // Get the ASCII art for the character
    char *character_ascii_art = malloc(sizeof(char) * 8);
    for (int j = 0; j < 8; j++) {
      character_ascii_art[j] = ' ';
    }

    // Set the bits in the ASCII art to represent the character
    for (int j = 0; j < 8; j++) {
      int bit = (ascii_code >> j) & 1;
      if (bit == 1) {
        character_ascii_art[j] = '*';
      }
    }

    // Copy the ASCII art for the character into the 2D array
    for (int j = 0; j < 8; j++) {
      ascii_art[j][i * 8 + j] = character_ascii_art[j];
    }

    // Free the memory allocated for the ASCII art for the character
    free(character_ascii_art);
  }

  // Convert the 2D array to a single string
  char *ascii_art_string = malloc(sizeof(char) * 8 * strlen(text) + 1);
  int index = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < strlen(text) * 8; j++) {
      ascii_art_string[index++] = ascii_art[i][j];
    }
    ascii_art_string[index++] = '\n';
  }
  ascii_art_string[index] = '\0';

  // Free the memory allocated for the 2D array
  for (int i = 0; i < 8; i++) {
    free(ascii_art[i]);
  }
  free(ascii_art);

  // Return the ASCII art string
  return ascii_art_string;
}

// Main function
int main() {
  // Get the text from the user
  char text[100];
  printf("Enter the text to convert to ASCII art: ");
  scanf("%s", text);

  // Convert the text to ASCII art
  char *ascii_art = text_to_ascii(text);

  // Print the ASCII art
  printf("\n%s", ascii_art);

  // Free the memory allocated for the ASCII art
  free(ascii_art);

  return 0;
}