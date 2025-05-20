//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
  int item_id;
  struct Node* next;
} Node;

typedef struct Warehouse {
  Node* head;
  int items_count;
} Warehouse;

void insert_item(Warehouse* warehouse, int item_id) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->item_id = item_id;
  newNode->next = NULL;

  if (warehouse->head == NULL) {
    warehouse->head = newNode;
  } else {
    warehouse->head->next = newNode;
  }

  warehouse->items_count++;
}

int search_item(Warehouse* warehouse, int item_id) {
  Node* current = warehouse->head;

  while (current) {
    if (current->item_id == item_id) {
      return 1;
    }

    current = current->next;
  }

  return 0;
}

int main() {
  Warehouse* warehouse = (Warehouse*)malloc(sizeof(Warehouse));
  warehouse->head = NULL;
  warehouse->items_count = 0;

  insert_item(warehouse, 1);
  insert_item(warehouse, 2);
  insert_item(warehouse, 3);

  if (search_item(warehouse, 2) == 1) {
    printf("Item 2 found!");
  } else {
    printf("Item 2 not found!");
  }

  return 0;
}