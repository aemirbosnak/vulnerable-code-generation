//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

struct Item {
  char name[20];
  int quantity;
  float price;
};

struct Node {
  struct Item item;
  struct Node* next;
};

struct Warehouse {
  struct Node* head;
  struct Node* tail;
  int items_count;
};

void insert_item(struct Warehouse* warehouse, struct Item* item) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->item = *item;
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

void search_item(struct Warehouse* warehouse, char* name) {
  struct Node* current_node = warehouse->head;

  while (current_node) {
    if (strcmp(current_node->item.name, name) == 0) {
      printf("Item name: %s, Quantity: %d, Price: %.2f\n", current_node->item.name, current_node->item.quantity, current_node->item.price);
      break;
    }
    current_node = current_node->next;
  }

  if (current_node == NULL) {
    printf("Item not found.\n");
  }
}

int main() {
  struct Warehouse warehouse;
  warehouse.head = NULL;
  warehouse.tail = NULL;
  warehouse.items_count = 0;

  struct Item item1;
  item1.name[0] = 'A';
  item1.quantity = 10;
  item1.price = 10.00;
  insert_item(&warehouse, &item1);

  struct Item item2;
  item2.name[0] = 'B';
  item2.quantity = 20;
  item2.price = 20.00;
  insert_item(&warehouse, &item2);

  search_item(&warehouse, "A");
  search_item(&warehouse, "B");

  return 0;
}