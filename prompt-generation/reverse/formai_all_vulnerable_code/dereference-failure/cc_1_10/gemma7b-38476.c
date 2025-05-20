//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_SHAPES 5

typedef struct Shape {
  char name;
  int points;
  struct Shape* next;
} Shape;

void initShapes(Shape** head) {
  *head = malloc(sizeof(Shape));
  (*head)->name = 'A';
  (*head)->points = 3;
  (*head)->next = NULL;

  Shape* tail = *head;
  for (int i = 1; i < MAX_NUM_SHAPES; i++) {
    tail->next = malloc(sizeof(Shape));
    tail = tail->next;
    tail->name = 'A' + i;
    tail->points = 3 + i;
    tail->next = NULL;
  }
}

void playGame(Shape* head) {
  time_t t = time(NULL);
  int seed = t + rand() % 10;
  srand(seed);

  Shape* current = head;
  int numShapes = 0;
  while (current) {
    numShapes++;
    current = current->next;
  }

  int guessNum = rand() % numShapes;

  current = head;
  for (int i = 0; i < guessNum; i++) {
    current = current->next;
  }

  printf("You guessed shape %c with %d points!\n", current->name, current->points);
}

int main() {
  Shape* head = NULL;
  initShapes(&head);

  playGame(head);

  return 0;
}