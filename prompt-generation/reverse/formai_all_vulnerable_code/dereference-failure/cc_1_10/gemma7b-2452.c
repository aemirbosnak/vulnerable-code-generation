//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int item_id;
  struct Node* next;
} Node;

typedef struct Warehouse {
  Node* head;
  int total_items;
} Warehouse;

Warehouse* create_warehouse() {
  Warehouse* warehouse = (Warehouse*)malloc(sizeof(Warehouse));
  warehouse->head = NULL;
  warehouse->total_items = 0;
  return warehouse;
}

void add_item(Warehouse* warehouse, int item_id) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->item_id = item_id;
  new_node->next = NULL;

  if (warehouse->head == NULL) {
    warehouse->head = new_node;
  } else {
    Node* current_node = warehouse->head;
    while (current_node->next) {
      current_node = current_node->next;
    }
    current_node->next = new_node;
  }

  warehouse->total_items++;
}

int search_item(Warehouse* warehouse, int item_id) {
  Node* current_node = warehouse->head;
  while (current_node) {
    if (current_node->item_id == item_id) {
      return 1;
    }
    current_node = current_node->next;
  }
  return 0;
}

int main() {
  Warehouse* warehouse = create_warehouse();
  add_item(warehouse, 1);
  add_item(warehouse, 2);
  add_item(warehouse, 3);
  add_item(warehouse, 4);

  if (search_item(warehouse, 2) == 1) {
    printf("Item 2 is found.\n");
  }

  return 0;
}