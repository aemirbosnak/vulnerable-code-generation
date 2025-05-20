//Gemma-7B DATASET v1.0 Category: System boot optimizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef DEBUG
#define PRINTF(x) printf(x)
#else
#define PRINTF(x)
#endif

#define MAX_HEIRLOOM_ITEMS 10

typedef struct Item {
  char name[20];
  int value;
  struct Item* next;
} Item;

Item* inventory = NULL;
Item* blacksmith = NULL;

void initialize_game() {
  inventory = NULL;
  blacksmith = NULL;
  srand(time(NULL));
}

void acquire_item(char* name, int value) {
  Item* item = malloc(sizeof(Item));
  strcpy(item->name, name);
  item->value = value;
  item->next = inventory;
  inventory = item;
}

void craft_item(char* name, int value) {
  Item* item = malloc(sizeof(Item));
  strcpy(item->name, name);
  item->value = value;
  item->next = blacksmith;
  blacksmith = item;
}

int main() {
  initialize_game();

  acquire_item("Sword", 20);
  acquire_item("Shield", 15);
  craft_item("Bow", 10);
  craft_item("Arrows", 5);

  printf("Inventory:");
  for (Item* item = inventory; item; item = item->next) {
    printf(" - %s (%d)", item->name, item->value);
  }

  printf("\nBlacksmith:");
  for (Item* item = blacksmith; item; item = item->next) {
    printf(" - %s (%d)", item->name, item->value);
  }

  return 0;
}