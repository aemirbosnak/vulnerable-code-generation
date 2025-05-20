//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct item_t {
  char name[20];
  int quantity;
  struct item_t* next;
} item_t;

item_t* inventory = NULL;

void add_item(char* name, int quantity) {
  item_t* new_item = malloc(sizeof(item_t));
  strcpy(new_item->name, name);
  new_item->quantity = quantity;
  new_item->next = NULL;

  if (inventory == NULL) {
    inventory = new_item;
  } else {
    inventory->next = new_item;
    inventory = new_item;
  }
}

void use_item(char* name) {
  item_t* item = inventory;

  while (item) {
    if (strcmp(item->name, name) == 0) {
      item->quantity--;
      if (item->quantity == 0) {
        free(item);
        item = NULL;
      }
      break;
    }
    item = item->next;
  }

  if (item == NULL) {
    printf("Item not found.\n");
  } else {
    printf("Item used.\n");
  }
}

int main() {
  add_item("Water", 10);
  add_item("Food", 5);
  add_item("Medkit", 2);

  use_item("Water");
  use_item("Food");
  use_item("Medkit");

  return 0;
}