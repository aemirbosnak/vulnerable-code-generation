//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 1000

typedef struct WordCount {
  char *word;
  int count;
} WordCount;

WordCount *word_count(char *text) {
  WordCount *words = malloc(sizeof(WordCount) * MAX_WORDS);
  int i = 0;
  char *word = NULL;
  int word_count = 0;

  for (i = 0; text[i] != '\0'; i++) {
    if (word == NULL) {
      word = malloc(20);
    }

    if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t') {
      words[word_count].word = word;
      words[word_count].count = word_count;
      word_count++;
      word = NULL;
    } else {
      word[strlen(word)] = text[i];
    }
  }

  words[word_count].word = word;
  words[word_count].count = word_count;

  return words;
}

int main() {
  char *text = "This is a sample text. It has many words. Some words are repeated. The word count is a useful tool.";

  WordCount *words = word_count(text);

  int i = 0;
  for (i = 0; words[i].word != NULL; i++) {
    printf("%s: %d\n", words[i].word, words[i].count);
  }

  free(words);

  return 0;
}