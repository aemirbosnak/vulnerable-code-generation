//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_CREDITS 10
#define MAX_DEBTS 5

typedef struct Knight {
  char name[20];
  int credits, debts;
  struct Knight *next;
} Knight;

Knight *insertKnight(Knight *head, char *name, int credits, int debts) {
  Knight *newKnight = malloc(sizeof(Knight));
  strcpy(newKnight->name, name);
  newKnight->credits = credits;
  newKnight->debts = debts;
  newKnight->next = NULL;

  if (head == NULL) {
    return newKnight;
  }

  Knight *currKnight = head;
  while (currKnight->next) {
    currKnight = currKnight->next;
  }

  currKnight->next = newKnight;
  return head;
}

void printKnights(Knight *head) {
  Knight *currKnight = head;
  while (currKnight) {
    printf("%s has %d credits and %d debts.\n", currKnight->name, currKnight->credits, currKnight->debts);
    currKnight = currKnight->next;
  }
}

int main() {
  Knight *head = NULL;

  insertKnight(head, "Sir Robin", 20, 10);
  insertKnight(head, "Sir Gareth", 10, 5);
  insertKnight(head, "Lady Alice", 15, 7);

  printKnights(head);

  return 0;
}