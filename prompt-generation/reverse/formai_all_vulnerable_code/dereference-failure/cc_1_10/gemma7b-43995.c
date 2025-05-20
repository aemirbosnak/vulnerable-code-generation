//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 255

typedef struct Word {
  char *word;
  int frequency;
} Word;

Word **createWordList(char **text) {
  Word **wordList = malloc(sizeof(Word *) * MAX_WORDS);
  int i = 0;
  for (char **p = text; *p != NULL; p++) {
    Word *word = malloc(sizeof(Word));
    word->word = strdup(*p);
    word->frequency = 1;
    wordList[i++] = word;
  }
  return wordList;
}

int calculateWordSimilarity(Word **wordList, char **sentence) {
  int i = 0;
  int similarity = 0;
  for (char **p = sentence; *p != NULL; p++) {
    for (Word *word = wordList; word->word != NULL; word++) {
      if (strcmp(word->word, *p) == 0) {
        similarity += word->frequency;
      }
    }
  }
  return similarity;
}

int main() {
  char **text = {"This is a sample text with some spam words.", "Spam spam spam, it's a lot of spam.", "But it is not spam, this text is clean."};
  char **sentence = {"This text contains a lot of spam words."};

  Word **wordList = createWordList(text);
  int similarity = calculateWordSimilarity(wordList, sentence);

  if (similarity > 50) {
    printf("The text contains a high amount of spam.\n");
  } else {
    printf("The text does not contain a high amount of spam.\n");
  }

  return 0;
}