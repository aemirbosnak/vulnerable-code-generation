//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct Word {
  char *word;
  int frequency;
} Word;

Word *words = NULL;

void addWord(char *word) {
  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->frequency = 1;
  words = words ? words : newWord;
  words = realloc(words, (words->frequency + 1) * sizeof(Word));
}

void countWords() {
  FILE *fp = fopen("sample.txt", "r");
  char buffer[MAX_WORD_LENGTH];
  int i = 0;

  if (fp) {
    while (fgets(buffer, MAX_WORD_LENGTH, fp) != NULL) {
      char *word = strtok(buffer, " ");
      while (word) {
        addWord(word);
        word = strtok(NULL, " ");
      }
    }
    fclose(fp);
  }
}

void printWords() {
  printf("Word frequency:\n");
  for (Word *w = words; w; w++) {
    printf("%s: %d\n", w->word, w->frequency);
  }
}

int main() {
  countWords();
  printWords();

  return 0;
}