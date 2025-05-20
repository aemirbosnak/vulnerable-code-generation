//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word {
  char *word;
  int frequency;
} Word;

Word *words;

void word_frequency_counter(char *text) {
  words = (Word *)malloc(MAX_WORDS * sizeof(Word));
  int i = 0;
  char *word = NULL;
  int word_length = 0;
  for (int n = 0; n < MAX_WORDS && text[n] != '\0'; n++) {
    if (text[n] == ' ') {
      if (word) {
        words[i].word = (char *)malloc((word_length + 1) * sizeof(char));
        strcpy(words[i].word, word);
        words[i].frequency = 1;
        i++;
      }
      word = NULL;
      word_length = 0;
    } else {
      word_length++;
    }
    if (word == NULL) {
      word = (char *)malloc((word_length + 1) * sizeof(char));
      strcpy(word, text + n);
    }
  }
  if (word) {
    words[i].word = (char *)malloc((word_length + 1) * sizeof(char));
    strcpy(words[i].word, word);
    words[i].frequency = 1;
  }
  words[i].frequency = 0;
}

int main() {
  char *text = "This is a sample text for word frequency counter. It has many words, and some of them are repeated. The repeated words are the ones that appear more than once.";
  word_frequency_counter(text);

  for (int i = 0; words[i].word != NULL; i++) {
    printf("%s: %d\n", words[i].word, words[i].frequency);
  }

  return 0;
}