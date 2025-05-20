//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100

typedef struct Item {
  char name[50];
  int quantity;
  double price;
  struct Item* next;
} Item;

typedef struct Warehouse {
  Item* head;
  int items_count;
  time_t last_updated;
} Warehouse;

void initialize_warehouse(Warehouse* warehouse) {
  warehouse->head = NULL;
  warehouse->items_count = 0;
  warehouse->last_updated = time(NULL);
}

void add_item(Warehouse* warehouse, char* name, int quantity, double price) {
  Item* new_item = malloc(sizeof(Item));
  strcpy(new_item->name, name);
  new_item->quantity = quantity;
  new_item->price = price;
  new_item->next = warehouse->head;
  warehouse->head = new_item;
  warehouse->items_count++;
}

void update_item(Warehouse* warehouse, char* name, int new_quantity, double new_price) {
  Item* item = warehouse->head;
  while (item) {
    if (strcmp(item->name, name) == 0) {
      item->quantity = new_quantity;
      item->price = new_price;
      warehouse->last_updated = time(NULL);
      return;
    }
    item = item->next;
  }
  printf("Item not found.\n");
}

void list_items(Warehouse* warehouse) {
  Item* item = warehouse->head;
  while (item) {
    printf("Name: %s, Quantity: %d, Price: %.2lf\n", item->name, item->quantity, item->price);
    item = item->next;
  }
}

int main() {
  Warehouse warehouse;
  initialize_warehouse(&warehouse);

  add_item(&warehouse, "Apple", 10, 1.20);
  add_item(&warehouse, "Banana", 5, 0.80);
  add_item(&warehouse, "Orange", 7, 1.00);

  list_items(&warehouse);

  update_item(&warehouse, "Banana", 8, 0.90);

  list_items(&warehouse);

  return 0;
}