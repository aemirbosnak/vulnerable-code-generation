//LLAMA2-13B DATASET v1.0 Category: Spell checking ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 20
#define MAX_LINES 100

// A recursive function to check the spelling of a word
void check_spelling(char *word) {
  // Base case: If the word is empty, return
  if (*word == '\0') {
    return;
  }

  // Recursive case: If the word has only one letter, return
  if (strlen(word) == 1) {
    return;
  }

  // Check if the word is a palindrome
  if (strcmp(word, word + strlen(word) - 1) == 0) {
    printf("Palindrome found: %s\n", word);
    return;
  }

  // Split the word into two parts: prefix and suffix
  char *prefix = word;
  char *suffix = word + strlen(word) - 1;

  // Recursively check the spelling of the prefix and suffix
  check_spelling(prefix);
  check_spelling(suffix);
}

int main() {
  // Input a sentence from the user
  char sentence[MAX_LINES];
  printf("Enter a sentence: ");
  fgets(sentence, MAX_LINES, stdin);

  // Split the sentence into individual words
  char *words[MAX_LINES];
  char *p = sentence;
  int i = 0;
  while (p != NULL && i < MAX_LINES) {
    words[i] = p;
    p = strchr(p, ' ');
    if (p == NULL) {
      p = sentence + strlen(sentence) - 1;
    }
    i++;
  }

  // Check the spelling of each word
  for (int i = 0; i < MAX_LINES; i++) {
    check_spelling(words[i]);
  }

  return 0;
}