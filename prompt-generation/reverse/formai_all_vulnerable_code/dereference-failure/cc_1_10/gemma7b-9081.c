//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY 10

typedef struct MemoryCell {
  int data;
  struct MemoryCell* next;
} MemoryCell;

MemoryCell* head = NULL;

void insert(int data) {
  MemoryCell* newCell = malloc(sizeof(MemoryCell));
  newCell->data = data;
  newCell->next = NULL;

  if (head == NULL) {
    head = newCell;
  } else {
    head->next = newCell;
    head = newCell;
  }
}

void play() {
  MemoryCell* current = head;
  int guesses = 0;

  while (current) {
    int guess = rand() % MAX_MEMORY;
    guesses++;

    if (guess == current->data) {
      printf("You guessed! It took you %d guesses.\n", guesses);
      break;
    } else if (guess < current->data) {
      printf("Too low.\n");
    } else {
      printf("Too high.\n");
    }

    current = current->next;
  }

  if (current == NULL) {
    printf("Sorry, you lost.\n");
  }
}

int main() {
  for (int i = 0; i < MAX_MEMORY; i++) {
    insert(rand() % MAX_MEMORY);
  }

  play();

  return 0;
}