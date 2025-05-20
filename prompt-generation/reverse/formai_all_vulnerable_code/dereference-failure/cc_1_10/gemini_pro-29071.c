//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

// Function to convert a string to lowercase
void to_lower(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    str[i] = tolower(str[i]);
  }
}

// Function to translate a word from English to Cat Language
char *translate_word(char *word) {
  // Create a buffer to store the translated word
  char *translated_word = malloc(MAX_WORD_LENGTH * sizeof(char));

  // Initialize the translated word
  translated_word[0] = '\0';

  // Check if the word is a vowel
  if (strchr("aeiou", word[0]) != NULL) {
    // If the word is a vowel, add "meow" to the beginning
    strcat(translated_word, "meow");
  }

  // Append the word to the translated word
  strcat(translated_word, word);

  // If the word is a consonant, add "purr" to the end
  if (!strchr("aeiou", word[0]) != NULL) {
    strcat(translated_word, "purr");
  }

  // Return the translated word
  return translated_word;
}

// Function to translate a line of text from English to Cat Language
char *translate_line(char *line) {
  // Create a buffer to store the translated line
  char *translated_line = malloc(MAX_LINE_LENGTH * sizeof(char));

  // Initialize the translated line
  translated_line[0] = '\0';

  // Convert the line to lowercase
  to_lower(line);

  // Split the line into words
  char *words[MAX_LINE_LENGTH];
  int num_words = 0;
  char *word = strtok(line, " ");
  while (word != NULL) {
    words[num_words++] = word;
    word = strtok(NULL, " ");
  }

  // Translate each word in the line
  for (int i = 0; i < num_words; i++) {
    char *translated_word = translate_word(words[i]);
    strcat(translated_line, translated_word);
    strcat(translated_line, " ");
    free(translated_word);
  }

  // Remove the trailing space from the translated line
  translated_line[strlen(translated_line) - 1] = '\0';

  // Return the translated line
  return translated_line;
}

// Main function
int main() {
  // Get the input line from the user
  char line[MAX_LINE_LENGTH];
  printf("Enter a line of text to translate: ");
  fgets(line, MAX_LINE_LENGTH, stdin);

  // Translate the line
  char *translated_line = translate_line(line);

  // Print the translated line
  printf("Translated line: %s\n", translated_line);

  // Free the allocated memory
  free(translated_line);

  return 0;
}