//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct WordEntry {
  char *word;
  int frequency;
} WordEntry;

WordEntry *word_frequency_counter(char *text) {
  WordEntry *entries = malloc(MAX_WORDS * sizeof(WordEntry));
  int i = 0;
  char *word = NULL;
  int frequency = 0;

  for (int j = 0; text[j] != '\0'; j++) {
    if (word == NULL) {
      word = malloc(20);
      strcpy(word, "");
    }

    if (text[j] == ' ' || text[j] == '\n' || text[j] == '\t') {
      entries[i].word = word;
      entries[i].frequency = frequency;
      i++;
      word = NULL;
      frequency = 0;
    } else {
      word = realloc(word, 20 * (frequency + 1));
      word[frequency] = text[j];
      frequency++;
    }
  }

  entries[i].word = word;
  entries[i].frequency = frequency;

  return entries;
}

int main() {
  char *text = "This is a sample text for word frequency counter. It has many words, some repeated twice. The frequency of each word is counted and displayed below.";

  WordEntry *entries = word_frequency_counter(text);

  for (int i = 0; entries[i].word != NULL; i++) {
    printf("%s: %d\n", entries[i].word, entries[i].frequency);
  }

  free(entries);

  return 0;
}