//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int item_id;
  struct Node* next;
};

struct Warehouse {
  struct Node* head;
  int items_count;
  char warehouse_name[20];
};

void insert_item(struct Warehouse* warehouse, int item_id) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->item_id = item_id;
  new_node->next = NULL;

  if (warehouse->head == NULL) {
    warehouse->head = new_node;
  } else {
    struct Node* temp = warehouse->head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = new_node;
  }

  warehouse->items_count++;
}

void search_item(struct Warehouse* warehouse, int item_id) {
  struct Node* temp = warehouse->head;
  while (temp) {
    if (temp->item_id == item_id) {
      printf("Item found: item_id = %d\n", item_id);
      return;
    }
    temp = temp->next;
  }

  printf("Item not found: item_id = %d\n", item_id);
}

int main() {
  struct Warehouse* warehouse = (struct Warehouse*)malloc(sizeof(struct Warehouse));
  warehouse->head = NULL;
  warehouse->items_count = 0;
  warehouse->warehouse_name[0] = '\0';

  insert_item(warehouse, 1);
  insert_item(warehouse, 2);
  insert_item(warehouse, 3);

  search_item(warehouse, 2);
  search_item(warehouse, 4);

  return 0;
}