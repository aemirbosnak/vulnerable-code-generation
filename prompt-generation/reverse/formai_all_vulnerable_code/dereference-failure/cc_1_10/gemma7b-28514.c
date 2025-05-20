//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY 10

typedef struct MemoryCell {
  int data;
  struct MemoryCell* next;
} MemoryCell;

MemoryCell* CreateMemoryCell(int data) {
  MemoryCell* cell = malloc(sizeof(MemoryCell));
  cell->data = data;
  cell->next = NULL;
  return cell;
}

void InsertMemoryCell(MemoryCell* head, int data) {
  MemoryCell* newCell = CreateMemoryCell(data);
  if (head == NULL) {
    head = newCell;
  } else {
    head->next = newCell;
  }
  head = newCell;
}

void PlayMemoryGame() {
  MemoryCell* head = NULL;
  int guessNumber;
  int round = 0;

  while (round < MAX_MEMORY) {
    printf("Round %d: Guess a number between 1 and %d: ", round, MAX_MEMORY);
    scanf("%d", &guessNumber);

    if (head == NULL) {
      InsertMemoryCell(head, guessNumber);
    } else {
      if (guessNumber == head->data) {
        printf("You guessed the number!\n");
      } else {
        InsertMemoryCell(head, guessNumber);
      }
    }

    round++;
  }

  printf("Game over! You played %d rounds.\n", round);
}

int main() {
  PlayMemoryGame();
  return 0;
}