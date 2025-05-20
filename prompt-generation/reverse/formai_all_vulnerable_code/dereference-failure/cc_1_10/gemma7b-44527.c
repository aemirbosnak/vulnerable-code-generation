//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item_t {
  char name[20];
  int quantity;
  float price;
  struct item_t* next;
};

struct warehouse_t {
  struct item_t* head;
  struct warehouse_t* next;
};

void insert_item(struct warehouse_t* warehouse, char* name, int quantity, float price) {
  struct item_t* new_item = malloc(sizeof(struct item_t));
  strcpy(new_item->name, name);
  new_item->quantity = quantity;
  new_item->price = price;
  new_item->next = NULL;

  if (warehouse->head == NULL) {
    warehouse->head = new_item;
  } else {
    struct item_t* current_item = warehouse->head;
    while (current_item->next != NULL) {
      current_item = current_item->next;
    }
    current_item->next = new_item;
  }
}

void print_items(struct warehouse_t* warehouse) {
  struct item_t* current_item = warehouse->head;
  while (current_item) {
    printf("%s: %d, $%.2f\n", current_item->name, current_item->quantity, current_item->price);
    current_item = current_item->next;
  }
}

int main() {
  struct warehouse_t* warehouse = malloc(sizeof(struct warehouse_t));
  warehouse->head = NULL;
  warehouse->next = NULL;

  insert_item(warehouse, "Bananas", 10, 0.99);
  insert_item(warehouse, "Apples", 20, 1.29);
  insert_item(warehouse, "Grapes", 15, 1.49);

  print_items(warehouse);

  return 0;
}