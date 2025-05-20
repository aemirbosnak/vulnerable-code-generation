//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_LINE_LENGTH 100
#define MAX_WORD_LENGTH 20

// Function prototypes
char* translate_word(char* word);
void translate_line(char* line);

// Main function
int main() {
  // Get the input line from the user
  char line[MAX_LINE_LENGTH];
  printf("Enter a line of text to translate: ");
  fgets(line, MAX_LINE_LENGTH, stdin);

  // Translate the line
  translate_line(line);

  // Print the translated line
  printf("Translated line: %s", line);

  return 0;
}

// Function to translate a word
char* translate_word(char* word) {
  // Check if the word is a reserved word
  if (strcmp(word, "meow") == 0) {
    return "purr";
  } else if (strcmp(word, "purr") == 0) {
    return "meow";
  } else if (strcmp(word, "hiss") == 0) {
    return "spit";
  } else if (strcmp(word, "spit") == 0) {
    return "hiss";
  } else if (strcmp(word, "scratch") == 0) {
    return "claw";
  } else if (strcmp(word, "claw") == 0) {
    return "scratch";
  } else if (strcmp(word, "bite") == 0) {
    return "chomp";
  } else if (strcmp(word, "chomp") == 0) {
    return "bite";
  } else if (strcmp(word, "love") == 0) {
    return "cuddle";
  } else if (strcmp(word, "cuddle") == 0) {
    return "love";
  }

  // Otherwise, return the word unchanged
  return word;
}

// Function to translate a line
void translate_line(char* line) {
  // Tokenize the line into words
  char* words[MAX_WORD_LENGTH];
  char* word = strtok(line, " ");
  int i = 0;
  while (word != NULL) {
    words[i++] = word;
    word = strtok(NULL, " ");
  }

  // Translate each word
  for (int j = 0; j < i; j++) {
    words[j] = translate_word(words[j]);
  }

  // Reconstruct the line from the translated words
  strcpy(line, words[0]);
  for (int j = 1; j < i; j++) {
    strcat(line, " ");
    strcat(line, words[j]);
  }
}