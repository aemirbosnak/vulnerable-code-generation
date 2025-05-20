//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_SENTENCES 10

typedef struct Word {
  char *word;
  struct Word *next;
} Word;

typedef struct Sentence {
  char *sentence;
  Word *words;
  struct Sentence *next;
} Sentence;

Sentence *createSentence() {
  Sentence *sentence = malloc(sizeof(Sentence));
  sentence->sentence = malloc(MAX_SENTENCES * MAX_WORDS);
  sentence->words = NULL;
  sentence->next = NULL;
  return sentence;
}

void addWord(Sentence *sentence, char *word) {
  Word *wordNode = malloc(sizeof(Word));
  wordNode->word = malloc(MAX_WORDS * sizeof(char));
  strcpy(wordNode->word, word);
  wordNode->next = NULL;

  if (sentence->words == NULL) {
    sentence->words = wordNode;
  } else {
    sentence->words->next = wordNode;
  }
}

void detectSpam(Sentence *sentence) {
  char *keywords[] = {"free", "lottery", "miracle", "prize", "offer"};
  int i = 0;

  for (Word *word = sentence->words; word; word = word->next) {
    for (i = 0; i < MAX_WORDS; i++) {
      if (strcmp(word->word, keywords[i]) == 0) {
        printf("Spam detected!\n");
        free(sentence);
        return;
      }
    }
  }

  printf("No spam detected.\n");
  free(sentence);
}

int main() {
  Sentence *sentence = createSentence();
  addWord(sentence, "This is a sample sentence.");
  addWord(sentence, "It contains no spam.");
  addWord(sentence, "Free money!");

  detectSpam(sentence);

  return 0;
}