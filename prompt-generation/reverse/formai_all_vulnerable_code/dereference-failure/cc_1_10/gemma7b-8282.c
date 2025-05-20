//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 100

char **words = NULL;

void analyze_text(char *text) {
  // Tokenize the text into words
  char *word_ptr = strtok(text, " ");
  int word_count = 0;
  words = malloc(MAX_WORDS * sizeof(char *));
  while (word_ptr) {
    words[word_count++] = strdup(word_ptr);
    word_ptr = strtok(NULL, " ");
  }

  // Remove stop words
  for (int i = 0; i < word_count; i++) {
    if (is_stop_word(words[i])) {
      free(words[i]);
      words[i] = NULL;
    }
  }

  // Analyze remaining words
  for (int i = 0; i < word_count; i++) {
    if (words[i] != NULL) {
      // Check for spam-related words
      if (is_spam_word(words[i])) {
        printf("%s is a spam-related word.\n", words[i]);
      }
    }
  }
}

int is_stop_word(char *word) {
  // List of common stop words
  char *stop_words[] = {"the", "a", "of", "to", "in", "for", "at", "by", "with", "in", "that", "a"};

  for (int i = 0; i < 11; i++) {
    if (strcmp(word, stop_words[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

int is_spam_word(char *word) {
  // List of common spam-related words
  char *spam_words[] = {"free", "lottery", "prize", "miracle", "miracle", "offer", "golden", "fast", "easy", "quick", "earn"};

  for (int i = 0; i < 11; i++) {
    if (strcmp(word, spam_words[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

int main() {
  char text[] = "You have won a free lottery! Claim your prize now!";

  analyze_text(text);

  return 0;
}