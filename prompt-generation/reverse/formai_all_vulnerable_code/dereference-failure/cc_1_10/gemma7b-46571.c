//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  char item[20];
  struct Node* next;
};

struct Warehouse {
  struct Node* head;
  struct Node* tail;
  int items_count;
};

void insert_item(struct Warehouse* warehouse, char item[]) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  strcpy(new_node->item, item);
  new_node->next = NULL;

  if (warehouse->head == NULL) {
    warehouse->head = new_node;
    warehouse->tail = new_node;
  } else {
    warehouse->tail->next = new_node;
    warehouse->tail = new_node;
  }

  warehouse->items_count++;
}

void search_item(struct Warehouse* warehouse, char item[]) {
  struct Node* current_node = warehouse->head;

  while (current_node) {
    if (strcmp(current_node->item, item) == 0) {
      printf("Item found: %s\n", current_node->item);
      return;
    }
    current_node = current_node->next;
  }

  printf("Item not found: %s\n", item);
}

int main() {
  struct Warehouse warehouse;
  warehouse.head = NULL;
  warehouse.tail = NULL;
  warehouse.items_count = 0;

  insert_item(&warehouse, "Apple");
  insert_item(&warehouse, "Banana");
  insert_item(&warehouse, "Orange");

  search_item(&warehouse, "Apple");
  search_item(&warehouse, "Peach");

  return 0;
}