//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int item_id;
  struct Node* next;
};

struct Warehouse {
  struct Node* head;
  int size;
};

void insert_item(struct Warehouse* warehouse, int item_id) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->item_id = item_id;
  new_node->next = NULL;

  if (warehouse->head == NULL) {
    warehouse->head = new_node;
  } else {
    warehouse->head->next = new_node;
  }

  warehouse->size++;
}

int search_item(struct Warehouse* warehouse, int item_id) {
  struct Node* current_node = warehouse->head;

  while (current_node) {
    if (current_node->item_id == item_id) {
      return 1;
    }
    current_node = current_node->next;
  }

  return 0;
}

int main() {
  struct Warehouse* warehouse = (struct Warehouse*)malloc(sizeof(struct Warehouse));
  warehouse->head = NULL;
  warehouse->size = 0;

  insert_item(warehouse, 10);
  insert_item(warehouse, 20);
  insert_item(warehouse, 30);

  if (search_item(warehouse, 20)) {
    printf("Item 20 found.\n");
  } else {
    printf("Item 20 not found.\n");
  }

  return 0;
}