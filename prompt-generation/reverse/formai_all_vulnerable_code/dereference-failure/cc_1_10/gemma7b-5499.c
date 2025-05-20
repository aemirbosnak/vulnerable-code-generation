//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

struct Item {
  char name[50];
  int quantity;
  float price;
  struct Item* next;
};

struct Warehouse {
  struct Item* head;
  struct Item* tail;
  int items_count;
  float total_cost;
};

void insert_item(struct Warehouse* warehouse, char* name, int quantity, float price) {
  struct Item* new_item = (struct Item*)malloc(sizeof(struct Item));
  new_item->quantity = quantity;
  new_item->price = price;
  strcpy(new_item->name, name);
  new_item->next = NULL;

  if (warehouse->head == NULL) {
    warehouse->head = new_item;
    warehouse->tail = new_item;
  } else {
    warehouse->tail->next = new_item;
    warehouse->tail = new_item;
  }

  warehouse->items_count++;
  warehouse->total_cost += new_item->quantity * new_item->price;
}

void remove_item(struct Warehouse* warehouse, char* name) {
  struct Item* current_item = warehouse->head;
  struct Item* previous_item = NULL;

  while (current_item) {
    if (strcmp(current_item->name, name) == 0) {
      if (previous_item) {
        previous_item->next = current_item->next;
        warehouse->tail = previous_item;
      } else {
        warehouse->head = current_item->next;
        warehouse->tail = warehouse->head;
      }

      warehouse->items_count--;
      warehouse->total_cost -= current_item->quantity * current_item->price;
      free(current_item);
      return;
    }

    previous_item = current_item;
    current_item = current_item->next;
  }

  printf("Item not found.\n");
}

void list_items(struct Warehouse* warehouse) {
  struct Item* current_item = warehouse->head;

  printf("Items:\n");
  while (current_item) {
    printf("%s - %d - %.2f\n", current_item->name, current_item->quantity, current_item->price);
    current_item = current_item->next;
  }
}

int main() {
  struct Warehouse warehouse;
  warehouse.head = NULL;
  warehouse.tail = NULL;
  warehouse.items_count = 0;
  warehouse.total_cost = 0.0f;

  insert_item(&warehouse, "Apple", 10, 1.2f);
  insert_item(&warehouse, "Banana", 20, 0.8f);
  insert_item(&warehouse, "Orange", 30, 0.9f);
  insert_item(&warehouse, "Grape", 40, 1.5f);

  list_items(&warehouse);

  remove_item(&warehouse, "Banana");

  list_items(&warehouse);

  printf("Total cost: %.2f\n", warehouse.total_cost);

  return 0;
}