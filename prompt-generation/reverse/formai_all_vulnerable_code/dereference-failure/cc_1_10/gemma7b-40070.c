//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1000

int main() {
  char text[MAX_WORDS][256];
  int text_size = 0;
  char word[256];
  int word_size = 0;
  int word_count = 0;
  int i, j, k;

  // Get text from the user
  printf("Enter text: ");
  fgets(text[text_size], 256, stdin);

  // Calculate text size
  text_size++;

  // Split the text into words
  for (i = 0; text[text_size - 1][i] != '\0'; i++) {
    if (text[text_size - 1][i] == ' ') {
      word[word_size] = '\0';
      word_size = 0;
      word_count++;
    } else {
      word[word_size] = text[text_size - 1][i];
      word_size++;
    }
  }

  // Create a word frequency table
  int word_frequency[word_count];
  for (i = 0; i < word_count; i++) {
    word_frequency[i] = 0;
  }

  // Count the frequency of each word
  for (i = 0; i < text_size; i++) {
    for (j = 0; j < word_count; j++) {
      if (strcmp(word[j], text[i]) == 0) {
        word_frequency[j]++;
      }
    }
  }

  // Print the word frequency table
  printf("Word frequency:\n");
  for (i = 0; i < word_count; i++) {
    printf("%s: %d\n", word[i], word_frequency[i]);
  }

  return 0;
}