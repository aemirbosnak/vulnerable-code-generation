//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ITEMS 100
#define MAX_ITEM_NAME_LENGTH 255

typedef struct Item {
  char name[MAX_ITEM_NAME_LENGTH];
  int quantity;
  struct Item* next;
} Item;

Item* item_list = NULL;

void add_item(char* name, int quantity) {
  Item* new_item = malloc(sizeof(Item));
  strcpy(new_item->name, name);
  new_item->quantity = quantity;
  new_item->next = NULL;

  if (item_list == NULL) {
    item_list = new_item;
  } else {
    item_list->next = new_item;
    item_list = new_item;
  }
}

void check_item(char* name) {
  Item* current_item = item_list;

  while (current_item) {
    if (strcmp(current_item->name, name) == 0) {
      printf("Quantity: %d\n", current_item->quantity);
      return;
    }
    current_item = current_item->next;
  }

  printf("Item not found.\n");
}

void update_item(char* name, int new_quantity) {
  Item* current_item = item_list;

  while (current_item) {
    if (strcmp(current_item->name, name) == 0) {
      current_item->quantity = new_quantity;
      return;
    }
    current_item = current_item->next;
  }

  printf("Item not found.\n");
}

void delete_item(char* name) {
  Item* current_item = item_list;
  Item* previous_item = NULL;

  while (current_item) {
    if (strcmp(current_item->name, name) == 0) {
      if (previous_item) {
        previous_item->next = current_item->next;
      } else {
        item_list = current_item->next;
      }
      free(current_item);
      return;
    }
    previous_item = current_item;
    current_item = current_item->next;
  }

  printf("Item not found.\n");
}

int main() {
  add_item("Gold Coin", 10);
  add_item("Silver Coin", 5);
  add_item("Copper Coin", 2);

  check_item("Gold Coin");
  update_item("Silver Coin", 10);
  delete_item("Copper Coin");

  check_item("Gold Coin");
  check_item("Silver Coin");

  return 0;
}