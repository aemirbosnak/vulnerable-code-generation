//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
  char name[20];
  int quantity;
  struct Item* next;
} Item;

void initialize_inventory(Item** inventory) {
  *inventory = NULL;
}

void add_item(Item** inventory, char* name, int quantity) {
  Item* new_item = malloc(sizeof(Item));
  strcpy(new_item->name, name);
  new_item->quantity = quantity;
  new_item->next = NULL;

  if (*inventory == NULL) {
    *inventory = new_item;
  } else {
    ((*inventory)->next = new_item)->next = *inventory;
    *inventory = new_item;
  }
}

void print_inventory(Item* inventory) {
  Item* current_item = inventory;
  printf("Inventory:\n");
  while (current_item) {
    printf("%s: %d\n", current_item->name, current_item->quantity);
    current_item = current_item->next;
  }
}

int main() {
  Item* inventory = NULL;
  initialize_inventory(&inventory);

  add_item(&inventory, "Energy Cell", 20);
  add_item(&inventory, "Laser Pistol", 1);
  add_item(&inventory, "Plasma Cutter", 0);

  print_inventory(inventory);

  return 0;
}