//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item {
  char name[20];
  int quantity;
  float price;
  struct Item* next;
};

struct Warehouse {
  struct Item* head;
  int items_count;
  float total_value;
  struct Warehouse* next;
};

void insert_item(struct Warehouse* warehouse, char* name, int quantity, float price) {
  struct Item* new_item = malloc(sizeof(struct Item));
  strcpy(new_item->name, name);
  new_item->quantity = quantity;
  new_item->price = price;
  new_item->next = NULL;

  if (warehouse->head == NULL) {
    warehouse->head = new_item;
  } else {
    struct Item* current = warehouse->head;
    while (current->next) {
      current = current->next;
    }
    current->next = new_item;
  }

  warehouse->items_count++;
  warehouse->total_value += new_item->price * new_item->quantity;
}

void update_item_quantity(struct Warehouse* warehouse, char* name, int new_quantity) {
  struct Item* item = warehouse->head;
  while (item) {
    if (strcmp(item->name, name) == 0) {
      item->quantity = new_quantity;
      warehouse->total_value = warehouse->total_value - (item->price * (item->quantity - new_quantity));
      return;
    }
    item = item->next;
  }

  printf("Item not found.\n");
}

void delete_item(struct Warehouse* warehouse, char* name) {
  struct Item* item = warehouse->head;
  struct Item* previous = NULL;

  while (item) {
    if (strcmp(item->name, name) == 0) {
      if (previous) {
        previous->next = item->next;
      } else {
        warehouse->head = item->next;
      }
      warehouse->items_count--;
      warehouse->total_value -= item->price * item->quantity;
      free(item);
      return;
    }
    previous = item;
    item = item->next;
  }

  printf("Item not found.\n");
}

int main() {
  struct Warehouse* warehouse = malloc(sizeof(struct Warehouse));
  warehouse->head = NULL;
  warehouse->items_count = 0;
  warehouse->total_value = 0.0f;

  insert_item(warehouse, "Apple", 10, 1.2f);
  insert_item(warehouse, "Banana", 5, 0.8f);
  insert_item(warehouse, "Orange", 7, 0.9f);

  update_item_quantity(warehouse, "Apple", 15);
  delete_item(warehouse, "Banana");

  printf("Items:\n");
  struct Item* item = warehouse->head;
  while (item) {
    printf("%s - %d - %.2f\n", item->name, item->quantity, item->price);
    item = item->next;
  }

  printf("Total value: %.2f\n", warehouse->total_value);

  return 0;
}