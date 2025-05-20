//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_LOCATIONS 10

typedef struct Item {
  char name[50];
  int quantity;
  struct Location *location;
} Item;

typedef struct Location {
  int number;
  struct Item **items;
} Location;

Location **locations = NULL;

void initialize_warehouse() {
  locations = (Location **)malloc(MAX_LOCATIONS * sizeof(Location));
  for (int i = 0; i < MAX_LOCATIONS; i++) {
    locations[i] = NULL;
  }
}

void add_item(char *name, int quantity, int location_number) {
  Item *item = (Item *)malloc(sizeof(Item));
  strcpy(item->name, name);
  item->quantity = quantity;
  item->location = locations[location_number];

  if (locations[location_number] == NULL) {
    locations[location_number] = (Location *)malloc(sizeof(Location));
    locations[location_number]->number = location_number;
    locations[location_number]->items = NULL;
  }

  locations[location_number]->items = (Item **)realloc(locations[location_number]->items, (locations[location_number]->items ? locations[location_number]->items : 0) + 1);
  locations[location_number]->items[0] = item;
}

void print_inventory() {
  for (int i = 0; i < MAX_LOCATIONS; i++) {
    if (locations[i] != NULL) {
      printf("Location %d:\n", locations[i]->number);
      for (int j = 0; locations[i]->items[j] != NULL; j++) {
        printf("%s - %d\n", locations[i]->items[j]->name, locations[i]->items[j]->quantity);
      }
    }
  }
}

int main() {
  initialize_warehouse();

  add_item("Apple", 10, 1);
  add_item("Banana", 5, 1);
  add_item("Orange", 7, 2);
  add_item("Grapes", 3, 2);

  print_inventory();

  return 0;
}