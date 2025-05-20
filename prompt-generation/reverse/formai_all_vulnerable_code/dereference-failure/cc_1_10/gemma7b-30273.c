//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10

typedef struct Word {
  char *word;
  struct Word *next;
} Word;

Word *head = NULL;

void addWord(char *word) {
  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->next = NULL;

  if (head == NULL) {
    head = newWord;
  } else {
    head->next = newWord;
  }
}

int main() {
  srand(time(NULL));

  addWord("Water");
  addWord("Canned Food");
  addWord("Rations");
  addWord("Scrap Metal");
  addWord("Medications");
  addWord("Firearms");

  int numWords = rand() % MAX_WORDS;
  char **words = malloc(numWords * sizeof(char *));

  for (int i = 0; i < numWords; i++) {
    words[i] = head->word;
    head = head->next;
  }

  for (int i = 0; i < numWords; i++) {
    printf("%s ", words[i]);
  }

  printf("\n");

  return 0;
}