//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

struct Node {
  char item[20];
  struct Node* next;
};

struct Warehouse {
  struct Node* head;
  int items;
  int capacity;
};

void insert(struct Warehouse* w, char item) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->item[0] = item;
  newNode->next = NULL;

  if (w->head == NULL) {
    w->head = newNode;
  } else {
    w->head->next = newNode;
  }

  w->items++;
}

void search(struct Warehouse* w, char item) {
  struct Node* current = w->head;

  while (current) {
    if (strcmp(current->item, item) == 0) {
      printf("Item found: %s\n", item);
      return;
    }

    current = current->next;
  }

  printf("Item not found: %s\n", item);
}

int main() {
  struct Warehouse* w = malloc(sizeof(struct Warehouse));
  w->head = NULL;
  w->items = 0;
  w->capacity = 100;

  insert(w, "Apple");
  insert(w, "Banana");
  insert(w, "Orange");

  search(w, "Apple");
  search(w, "Banana");
  search(w, "Mango");

  return 0;
}