//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word {
  char *word;
  int frequency;
} Word;

Word **createWordList(char **text, int textSize) {
  Word **words = malloc(sizeof(Word *) * MAX_WORDS);
  int i = 0;
  for (int j = 0; j < textSize; j++) {
    char *word = strdup(text[j]);
    Word *newWord = malloc(sizeof(Word));
    newWord->word = word;
    newWord->frequency = 1;
    words[i++] = newWord;
  }
  return words;
}

void calculateWordFrequency(Word **words, int numWords) {
  for (int i = 0; i < numWords; i++) {
    words[i]->frequency = 0;
    for (int j = 0; j < numWords; j++) {
      if (words[i]->word == words[j]->word) {
        words[i]->frequency++;
      }
    }
  }
}

int main() {
  char **text = malloc(sizeof(char *) * 10);
  text[0] = "The quick brown fox jumps over the lazy dog";
  text[1] = "The cat sat on the mat";
  text[2] = "The quick brown fox jumped over the lazy dog";

  int textSize = 3;

  Word **words = createWordList(text, textSize);
  calculateWordFrequency(words, textSize);

  for (int i = 0; i < textSize; i++) {
    printf("%s: %d\n", words[i]->word, words[i]->frequency);
  }

  free(words);
  free(text);

  return 0;
}