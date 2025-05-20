//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 200

typedef struct Word {
  char *word;
  int frequency;
} Word;

typedef struct Sentence {
  char *sentence;
  Word **words;
  int numWords;
} Sentence;

Sentence **createSentence(char *sentence) {
  Sentence **sentencePtr = (Sentence **)malloc(sizeof(Sentence));

  *sentencePtr = (Sentence *)malloc(sizeof(Sentence));
  (*sentencePtr)->sentence = strdup(sentence);
  (*sentencePtr)->words = (Word **)malloc(MAX_WORDS * sizeof(Word));
  (*sentencePtr)->numWords = 0;

  return sentencePtr;
}

void addWordToSentence(Sentence *sentence, char *word) {
  Word *newWord = (Word *)malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->frequency = 0;

  sentence->words[sentence->numWords++] = newWord;
}

int main() {
  char *sentence = "This is a sample sentence with a lot of spam words, such as free, cheap, and miracle. It also has some nonsensical words, like bucephalus and quagmire.";

  Sentence *sentencePtr = createSentence(sentence);

  addWordToSentence(sentencePtr, "free");
  addWordToSentence(sentencePtr, "cheap");
  addWordToSentence(sentencePtr, "miracle");
  addWordToSentence(sentencePtr, "bucephalus");
  addWordToSentence(sentencePtr, "quagmire");

  int numWords = sentencePtr->numWords;

  for (int i = 0; i < numWords; i++) {
    printf("%s (%d) ", sentencePtr->words[i]->word, sentencePtr->words[i]->frequency);
  }

  printf("\n");

  return 0;
}