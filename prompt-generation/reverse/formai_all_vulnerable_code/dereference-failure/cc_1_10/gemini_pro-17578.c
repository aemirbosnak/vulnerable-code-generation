//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

// Declare the Alien language alphabet
const char *alien_alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,?!-_ ";

// Declare the English language alphabet
const char *english_alphabet = "zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA'?/.>,<;:_+=-";

// Function to translate from Alien to English
char *alien_to_english(char *alien_text) {
  int i;
  char *english_text = (char *)malloc(MAX_SIZE);

  for (i = 0; i < strlen(alien_text); i++) {
    int index = strchr(alien_alphabet, alien_text[i]) - alien_alphabet;
    if (index >= 0) {
      english_text[i] = english_alphabet[index];
    } else {
      english_text[i] = '?';
    }
  }

  return english_text;
}

// Function to translate from English to Alien
char *english_to_alien(char *english_text) {
  int i;
  char *alien_text = (char *)malloc(MAX_SIZE);

  for (i = 0; i < strlen(english_text); i++) {
    int index = strchr(english_alphabet, english_text[i]) - english_alphabet;
    if (index >= 0) {
      alien_text[i] = alien_alphabet[index];
    } else {
      alien_text[i] = '?';
    }
  }

  return alien_text;
}

// Main function
int main() {
  char alien_text[] = "zyxwvutsrqponmlkjihgfedcba";
  char english_text[] = "abcdefghijklmnopqrstuvwxyz";

  printf("Alien text: %s\n", alien_text);
  printf("English text: %s\n", english_alphabet);

  char *alien_to_english_text = alien_to_english(alien_text);
  printf("Alien to English: %s\n", alien_to_english_text);

  char *english_to_alien_text = english_to_alien(english_text);
  printf("English to Alien: %s\n", english_to_alien_text);

  free(alien_to_english_text);
  free(english_to_alien_text);

  return 0;
}