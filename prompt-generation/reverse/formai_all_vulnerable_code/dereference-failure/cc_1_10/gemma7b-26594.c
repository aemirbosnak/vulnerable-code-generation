//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_SENTENCE_LENGTH 200

typedef struct Word {
  char *word;
  struct Word *next;
} Word;

typedef struct Sentence {
  char *sentence;
  Word *words;
  struct Sentence *next;
} Sentence;

Sentence *createSentence(char *sentence) {
  Sentence *newSentence = (Sentence *)malloc(sizeof(Sentence));
  newSentence->sentence = strdup(sentence);
  newSentence->words = NULL;
  newSentence->next = NULL;

  return newSentence;
}

Word *createWord(char *word) {
  Word *newWord = (Word *)malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->next = NULL;

  return newWord;
}

int main() {
  Sentence *sentences = NULL;
  char sentence[MAX_SENTENCE_LENGTH];

  printf("Enter a sentence: ");
  fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

  sentences = createSentence(sentence);

  Word *words = sentences->words;
  while (words) {
    printf("%s ", words->word);
    words = words->next;
  }

  return 0;
}