//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: puzzling
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define WORDS_PER_PAGE 20

typedef struct Word {
  char word[20];
  struct Word* next;
} Word;

Word* createWordList(int);
void printWordList(Word*);

int main() {
  Word* wordList = createWordList(MAX_WORDS);
  printWordList(wordList);

  time_t start, end;
  start = time(NULL);

  // Type as fast as you can to complete the sentences below
  // Each sentence is on a separate line.
  // The sentences are randomly chosen from the word list.

  for (int i = 0; i < MAX_WORDS; i++) {
    printf("%s\n", wordList->word);
    wordList = wordList->next;
  }

  end = time(NULL);
  printf("Time taken: %.2f seconds\n", end - start);

  return 0;
}

Word* createWordList(int size) {
  Word* head = malloc(sizeof(Word));
  head->word[0] = '\0';
  head->next = NULL;

  for (int i = 0; i < size; i++) {
    Word* newNode = malloc(sizeof(Word));
    newNode->word[0] = '\0';
    newNode->next = NULL;

    head->next = newNode;
    head = newNode;
  }

  return head;
}

void printWordList(Word* list) {
  while (list) {
    printf("%s\n", list->word);
    list = list->next;
  }
}