//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int item_id;
  struct Node* next;
};

struct Warehouse {
  struct Node* head;
  int items_count;
};

void insert_item(struct Warehouse* warehouse, int item_id) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->item_id = item_id;
  newNode->next = NULL;

  if (warehouse->head == NULL) {
    warehouse->head = newNode;
  } else {
    warehouse->head->next = newNode;
  }

  warehouse->items_count++;
}

void search_item(struct Warehouse* warehouse, int item_id) {
  struct Node* current = warehouse->head;

  while (current) {
    if (current->item_id == item_id) {
      printf("Item %d found.\n", item_id);
      return;
    }

    current = current->next;
  }

  printf("Item %d not found.\n", item_id);
}

int main() {
  struct Warehouse warehouse;
  warehouse.head = NULL;
  warehouse.items_count = 0;

  insert_item(&warehouse, 10);
  insert_item(&warehouse, 20);
  insert_item(&warehouse, 30);

  search_item(&warehouse, 20);
  search_item(&warehouse, 40);

  return 0;
}