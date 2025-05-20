//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: sophisticated
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 100
#define WORDS_PER_PAGE 20

typedef struct Word {
  char word[20];
  struct Word* next;
} Word;

Word* head = NULL;

void insertWord(char* word) {
  Word* newNode = malloc(sizeof(Word));
  strcpy(newNode->word, word);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
    head = newNode;
  }
}

void printWords() {
  Word* current = head;
  int i = 0;
  while (current) {
    printf("%s ", current->word);
    current = current->next;
    i++;
    if (i % WORDS_PER_PAGE == 0) {
      printf("\n");
    }
  }
}

int main() {
  clock_t start, end;
  double timeTaken;

  insertWord("Hello");
  insertWord("World");
  insertWord("!");

  start = clock();
  printWords();
  end = clock();

  timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Time taken: %.2lf seconds\n", timeTaken);

  return 0;
}