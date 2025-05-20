//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int item_id;
  char item_name[50];
  int quantity;
  struct Node* next;
};

struct Warehouse {
  struct Node* head;
  struct Node* tail;
  int total_items;
};

void insert_item(struct Warehouse* warehouse, char* item_name, int quantity) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->item_id = warehouse->total_items++;
  newNode->quantity = quantity;
  strcpy(newNode->item_name, item_name);
  newNode->next = NULL;

  if (warehouse->head == NULL) {
    warehouse->head = newNode;
    warehouse->tail = newNode;
  } else {
    warehouse->tail->next = newNode;
    warehouse->tail = newNode;
  }
}

void search_item(struct Warehouse* warehouse, int item_id) {
  struct Node* current = warehouse->head;

  while (current) {
    if (current->item_id == item_id) {
      printf("Item name: %s\n", current->item_name);
      printf("Quantity: %d\n", current->quantity);
      break;
    }
    current = current->next;
  }

  if (current == NULL) {
    printf("Item not found.\n");
  }
}

int main() {
  struct Warehouse* warehouse = malloc(sizeof(struct Warehouse));
  warehouse->head = NULL;
  warehouse->tail = NULL;
  warehouse->total_items = 0;

  insert_item(warehouse, "Apple", 10);
  insert_item(warehouse, "Banana", 20);
  insert_item(warehouse, "Orange", 30);

  search_item(warehouse, 1);
  search_item(warehouse, 2);

  return 0;
}