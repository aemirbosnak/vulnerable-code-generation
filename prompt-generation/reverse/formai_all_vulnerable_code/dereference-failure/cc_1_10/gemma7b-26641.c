//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROLLS 10
#define MAX_NUMBER 6

typedef struct Roll {
  int number;
  struct Roll* next;
} Roll;

Roll* createRoll(int number) {
  Roll* newRoll = malloc(sizeof(Roll));
  newRoll->number = number;
  newRoll->next = NULL;
  return newRoll;
}

void addRoll(Roll* head, int number) {
  Roll* newRoll = createRoll(number);
  if (head == NULL) {
    head = newRoll;
  } else {
    newRoll->next = head;
    head = newRoll;
  }
}

void printRolls(Roll* head) {
  while (head) {
    printf("%d ", head->number);
    head = head->next;
  }
  printf("\n");
}

int main() {
  srand(time(NULL));
  int rolls = 0;
  Roll* head = NULL;

  while (rolls < MAX_ROLLS) {
    int number = rand() % MAX_NUMBER + 1;
    addRoll(head, number);
    rolls++;
  }

  printRolls(head);

  return 0;
}