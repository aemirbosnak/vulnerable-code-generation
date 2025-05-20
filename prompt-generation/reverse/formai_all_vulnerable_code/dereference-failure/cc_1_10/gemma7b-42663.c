//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct Word {
  char *word;
  int frequency;
} Word;

Word **createWordList(int *numWords) {
  Word **words = malloc(sizeof(Word *) * MAX_WORDS);
  *numWords = 0;
  return words;
}

void addWordToWordList(Word **words, int *numWords, char *word) {
  int i = 0;
  for (; i < *numWords; i++) {
    if (strcmp(words[i]->word, word) == 0) {
      words[i]->frequency++;
      return;
    }
  }

  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->frequency = 1;
  words[*numWords] = newWord;
  (*numWords)++;
}

void printWordList(Word **words, int numWords) {
  for (int i = 0; i < numWords; i++) {
    printf("%s: %d\n", words[i]->word, words[i]->frequency);
  }
}

int main() {
  int numWords = 0;
  Word **words = createWordList(&numWords);

  addWordToWordList(words, &numWords, "apple");
  addWordToWordList(words, &numWords, "banana");
  addWordToWordList(words, &numWords, "apple");
  addWordToWordList(words, &numWords, "orange");

  printWordList(words, numWords);

  return 0;
}