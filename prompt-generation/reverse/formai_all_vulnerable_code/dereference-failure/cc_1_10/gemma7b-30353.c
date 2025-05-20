//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: mind-bending
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

void insert_item(struct Warehouse* warehouse, char item) {
  struct Node* new_node = malloc(sizeof(struct Node));
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

char search_item(struct Warehouse* warehouse, char item) {
  struct Node* current_node = warehouse->head;

  while (current_node) {
    if (strcmp(current_node->item, item) == 0) {
      return current_node->item;
    }

    current_node = current_node->next;
  }

  return NULL;
}

int main() {
  struct Warehouse warehouse;
  warehouse.head = NULL;
  warehouse.tail = NULL;
  warehouse.items_count = 0;

  insert_item(&warehouse, "Apple");
  insert_item(&warehouse, "Banana");
  insert_item(&warehouse, "Orange");

  char item_to_search = 'B';

  char item_found = search_item(&warehouse, item_to_search);

  if (item_found) {
    printf("Item found: %s\n", item_found);
  } else {
    printf("Item not found.\n");
  }

  return 0;
}