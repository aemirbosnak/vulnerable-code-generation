//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the Alien language dictionary
char alien_dict[26] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";

// Function to translate a string from English to Alien language
char *translate_to_alien(char *english_string) {
  int len = strlen(english_string);
  char *alien_string = malloc(len + 1);

  for (int i = 0; i < len; i++) {
    char c = english_string[i];
    if (isalpha(c)) {
      if (isupper(c)) {
        alien_string[i] = alien_dict[c - 'A'];
      } else {
        alien_string[i] = alien_dict[c - 'a'];
      }
    } else {
      alien_string[i] = c;
    }
  }

  alien_string[len] = '\0';
  return alien_string;
}

// Function to translate a string from Alien language to English
char *translate_to_english(char *alien_string) {
  int len = strlen(alien_string);
  char *english_string = malloc(len + 1);

  for (int i = 0; i < len; i++) {
    char c = alien_string[i];
    if (isalpha(c)) {
      if (isupper(c)) {
        english_string[i] = 'A' + (26 - (c - 'Z'));
      } else {
        english_string[i] = 'a' + (26 - (c - 'z'));
      }
    } else {
      english_string[i] = c;
    }
  }

  english_string[len] = '\0';
  return english_string;
}

// Main function
int main() {
  // Get the input string from the user
  char input_string[100];
  printf("Enter the string to translate: ");
  gets(input_string);

  // Translate the string to Alien language
  char *alien_string = translate_to_alien(input_string);

  // Print the translated string
  printf("Alien language: %s\n", alien_string);

  // Translate the string back to English
  char *english_string = translate_to_english(alien_string);

  // Print the translated string
  printf("English language: %s\n", english_string);

  // Free the allocated memory
  free(alien_string);
  free(english_string);

  return 0;
}