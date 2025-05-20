//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NUM 100
#define MAX_LOCATION 10

typedef struct Item {
  char name[50];
  int quantity;
  struct Item* next;
} Item;

typedef struct Location {
  int row;
  int column;
  struct Location* next;
} Location;

Item* addItem(Item* head, char* name, int quantity) {
  Item* newItem = (Item*)malloc(sizeof(Item));
  strcpy(newItem->name, name);
  newItem->quantity = quantity;
  newItem->next = head;
  return newItem;
}

Location* addLocation(Location* head, int row, int column) {
  Location* newLocation = (Location*)malloc(sizeof(Location));
  newLocation->row = row;
  newLocation->column = column;
  newLocation->next = head;
  return newLocation;
}

void printInventory(Item* head) {
  Item* currentItem = head;
  while (currentItem) {
    printf("%s: %d\n", currentItem->name, currentItem->quantity);
    currentItem = currentItem->next;
  }
}

void printLocation(Location* head) {
  Location* currentLocation = head;
  while (currentLocation) {
    printf("(%d, %d)\n", currentLocation->row, currentLocation->column);
    currentLocation = currentLocation->next;
  }
}

int main() {
  Item* inventory = NULL;
  Location* locations = NULL;

  // Add some items to the inventory
  addItem(inventory, "Apple", 10);
  addItem(inventory, "Banana", 5);
  addItem(inventory, "Orange", 7);

  // Add some locations to the warehouse
  addLocation(locations, 1, 2);
  addLocation(locations, 2, 3);
  addLocation(locations, 3, 4);

  // Print the inventory
  printInventory(inventory);

  // Print the locations
  printLocation(locations);

  return 0;
}