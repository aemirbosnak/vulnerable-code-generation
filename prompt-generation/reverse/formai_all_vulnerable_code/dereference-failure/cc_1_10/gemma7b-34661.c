//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MEMORY_SIZE 10
#define MAX_WORDS_TO_LEARN 20

typedef struct MemoryItem {
  char word[MAX_WORDS_TO_LEARN];
  int isLearned;
  struct MemoryItem* next;
} MemoryItem;

void initializeMemory(MemoryItem** head) {
  *head = NULL;
  for (int i = 0; i < MAX_MEMORY_SIZE; i++) {
    *head = malloc(sizeof(MemoryItem));
    (*head)->isLearned = 0;
    (*head)->next = NULL;
    head = &((*head)->next);
  }
}

void learnWord(MemoryItem** head, char word) {
  for (MemoryItem* currentItem = *head; currentItem; currentItem = currentItem->next) {
    if (strcmp(currentItem->word, word) == 0) {
      currentItem->isLearned = 1;
      return;
    }
  }

  *head = malloc(sizeof(MemoryItem));
  (*head)->word[0] = word;
  (*head)->isLearned = 0;
  (*head)->next = NULL;

  *head = &((*head)->next);
}

int main() {
  MemoryItem* head = NULL;
  initializeMemory(&head);

  // Learn some words
  learnWord(&head, "apple");
  learnWord(&head, "banana");
  learnWord(&head, "orange");

  // Test the memory
  for (MemoryItem* currentItem = head; currentItem; currentItem = currentItem->next) {
    if (currentItem->isLearned) {
      printf("%s is learned!\n", currentItem->word);
    }
  }

  return 0;
}