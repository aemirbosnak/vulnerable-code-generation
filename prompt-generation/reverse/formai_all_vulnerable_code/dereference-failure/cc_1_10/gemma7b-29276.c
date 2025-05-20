//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Budget {
  struct Node* head;
  int total;
  char name[20];
};

void insert(struct Budget* budget, int data) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (budget->head == NULL) {
    budget->head = newNode;
  } else {
    struct Node* current = budget->head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }

  budget->total += data;
}

int main() {
  struct Budget* budget = malloc(sizeof(struct Budget));
  budget->head = NULL;
  budget->total = 0;
  strcpy(budget->name, "John Doe");

  insert(budget, 100);
  insert(budget, 200);
  insert(budget, 300);

  printf("Name: %s\n", budget->name);
  printf("Total: %d\n", budget->total);
  printf("Items:\n");

  struct Node* current = budget->head;
  while (current) {
    printf("%d\n", current->data);
    current = current->next;
  }

  return 0;
}