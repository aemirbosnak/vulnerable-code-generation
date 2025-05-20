//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: complex
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 100
#define WORDS_PER_LINE 20

typedef struct Word {
  char word[20];
  struct Word* next;
} Word;

void insertWord(Word** head, char* word) {
  Word* newNode = malloc(sizeof(Word));
  strcpy(newNode->word, word);
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void printWords(Word* head) {
  while (head) {
    printf("%s ", head->word);
    head = head->next;
  }
  printf("\n");
}

int main() {
  Word* head = NULL;
  char word[20];

  // Insert words into the list
  insertWord(&head, "apple");
  insertWord(&head, "banana");
  insertWord(&head, "cherry");
  insertWord(&head, "orange");
  insertWord(&head, "peach");

  // Print the words in the list
  printWords(head);

  // Start the timer
  time_t start = time(NULL);

  // Type the words as fast as you can
  printf("Type the words below as quickly as possible:\n");
  printWords(head);

  // Stop the timer
  time_t end = time(NULL);

  // Calculate the time taken
  int timeTaken = end - start;

  // Print the time taken
  printf("Time taken: %d seconds\n", timeTaken);

  return 0;
}