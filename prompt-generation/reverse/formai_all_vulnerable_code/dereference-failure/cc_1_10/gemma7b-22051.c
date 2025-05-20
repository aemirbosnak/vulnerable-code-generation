//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

struct Node {
  char item[20];
  struct Node* next;
};

struct Warehouse {
  struct Node* head;
  struct Node* tail;
  int items_count;
};

void insert_item(struct Warehouse* w, char item[]) {
  struct Node* newNode = malloc(sizeof(struct Node));
  strcpy(newNode->item, item);
  newNode->next = NULL;

  if (w->head == NULL) {
    w->head = newNode;
    w->tail = newNode;
  } else {
    w->tail->next = newNode;
    w->tail = newNode;
  }

  w->items_count++;
}

int search_item(struct Warehouse* w, char item[]) {
  struct Node* current = w->head;

  while (current) {
    if (strcmp(current->item, item) == 0) {
      return 1;
    }
    current = current->next;
  }

  return 0;
}

int main() {
  struct Warehouse w;
  w.head = NULL;
  w.tail = NULL;
  w.items_count = 0;

  insert_item(&w, "Apple");
  insert_item(&w, "Banana");
  insert_item(&w, "Orange");

  if (search_item(&w, "Apple") == 1) {
    printf("Apple is found.\n");
  }

  return 0;
}