//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct item {
  char name[20];
  int quantity;
  struct item* next;
} item_t;

item_t* inventory = NULL;

void add_item(char* name, int quantity) {
  item_t* new_item = malloc(sizeof(item_t));
  new_item->name[0] = '\0';
  strcpy(new_item->name, name);
  new_item->quantity = quantity;
  new_item->next = inventory;
  inventory = new_item;
}

void use_item(char* name) {
  item_t* current_item = inventory;
  while (current_item) {
    if (strcmp(current_item->name, name) == 0) {
      current_item->quantity--;
      printf("You used %s.\n", current_item->name);
      if (current_item->quantity == 0) {
        item_t* item_to_remove = current_item;
        current_item = current_item->next;
        free(item_to_remove);
      }
      break;
    }
    current_item = current_item->next;
  }
  if (current_item == NULL) {
    printf("You do not have that item.\n");
  }
}

int main() {
  add_item("Sword", 5);
  add_item("Shield", 3);
  add_item("Potion", 2);

  use_item("Sword");
  use_item("Shield");
  use_item("Potion");

  return 0;
}