//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct InventoryItem {
  char name[20];
  int quantity;
  double price;
  struct InventoryItem* nextItem;
};

struct Inventory {
  struct InventoryItem* head;
  struct InventoryItem* tail;
  int size;
};

void insertItem(struct Inventory* inventory, char* name, int quantity, double price) {
  struct InventoryItem* newNode = (struct InventoryItem*)malloc(sizeof(struct InventoryItem));
  strcpy(newNode->name, name);
  newNode->quantity = quantity;
  newNode->price = price;
  newNode->nextItem = NULL;

  if (inventory->head == NULL) {
    inventory->head = newNode;
    inventory->tail = newNode;
  } else {
    inventory->tail->nextItem = newNode;
    inventory->tail = newNode;
  }

  inventory->size++;
}

void printInventory(struct Inventory* inventory) {
  struct InventoryItem* currentItem = inventory->head;
  while (currentItem) {
    printf("%s: %d, $%.2lf\n", currentItem->name, currentItem->quantity, currentItem->price);
    currentItem = currentItem->nextItem;
  }
}

int main() {
  struct Inventory* inventory = (struct Inventory*)malloc(sizeof(struct Inventory));
  inventory->head = NULL;
  inventory->tail = NULL;
  inventory->size = 0;

  insertItem(inventory, "Cog", 10, 20.0);
  insertItem(inventory, "Sprocket", 5, 10.0);
  insertItem(inventory, "Fuzzy Wuzzy", 2, 5.0);
  insertItem(inventory, "Bananaphone", 3, 15.0);

  printInventory(inventory);

  return 0;
}