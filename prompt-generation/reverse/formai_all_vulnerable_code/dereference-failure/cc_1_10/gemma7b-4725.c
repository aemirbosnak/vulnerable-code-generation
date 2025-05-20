//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

struct Node {
  char item[20];
  struct Node* next;
};

struct Warehouse {
  struct Node* head;
  int items_count;
};

void insert_item(struct Warehouse* w, char item) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  strcpy(new_node->item, item);
  new_node->next = NULL;

  if (w->head == NULL) {
    w->head = new_node;
  } else {
    w->head->next = new_node;
  }

  w->items_count++;
}

void search_item(struct Warehouse* w, char item) {
  struct Node* current = w->head;

  while (current) {
    if (strcmp(current->item, item) == 0) {
      printf("Item found: %s\n", current->item);
      return;
    }

    current = current->next;
  }

  printf("Item not found.\n");
}

int main() {
  struct Warehouse* w = (struct Warehouse*)malloc(sizeof(struct Warehouse));
  w->head = NULL;
  w->items_count = 0;

  insert_item(w, "Apple");
  insert_item(w, "Banana");
  insert_item(w, "Orange");

  search_item(w, "Banana");

  return 0;
}