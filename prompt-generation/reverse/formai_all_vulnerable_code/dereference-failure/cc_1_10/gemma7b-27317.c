//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_SHELVES 20

typedef struct item {
  char name[50];
  int quantity;
  struct item* next;
} item_t;

typedef struct shelf {
  item_t* head;
  struct shelf* next;
} shelf_t;

shelf_t* create_shelf() {
  shelf_t* new_shelf = malloc(sizeof(shelf_t));
  new_shelf->head = NULL;
  new_shelf->next = NULL;
  return new_shelf;
}

void add_item(shelf_t* shelf, item_t* new_item) {
  if (shelf->head == NULL) {
    shelf->head = new_item;
  } else {
    shelf->head->next = new_item;
    shelf->head = new_item;
  }
}

item_t* find_item(shelf_t* shelf, char* item_name) {
  item_t* current_item = shelf->head;
  while (current_item) {
    if (strcmp(current_item->name, item_name) == 0) {
      return current_item;
    }
    current_item = current_item->next;
  }
  return NULL;
}

void update_item_quantity(item_t* item, int new_quantity) {
  item->quantity = new_quantity;
}

void print_items(shelf_t* shelf) {
  item_t* current_item = shelf->head;
  while (current_item) {
    printf("%s - %d\n", current_item->name, current_item->quantity);
    current_item = current_item->next;
  }
}

int main() {
  shelf_t* shelves = create_shelf();
  item_t* new_item = malloc(sizeof(item_t));
  strcpy(new_item->name, "Apple");
  new_item->quantity = 10;
  add_item(shelves, new_item);

  new_item = malloc(sizeof(item_t));
  strcpy(new_item->name, "Banana");
  new_item->quantity = 20;
  add_item(shelves, new_item);

  new_item = malloc(sizeof(item_t));
  strcpy(new_item->name, "Orange");
  new_item->quantity = 30;
  add_item(shelves, new_item);

  print_items(shelves);

  item_t* item = find_item(shelves, "Apple");
  if (item) {
    update_item_quantity(item, 15);
  }

  print_items(shelves);

  return 0;
}