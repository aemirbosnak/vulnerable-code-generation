//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_ Shelves 20

typedef struct Item {
  char name[20];
  int quantity;
  struct Item* next;
} Item;

typedef struct Shelf {
  Item* items;
  struct Shelf* next;
} Shelf;

Shelf* head = NULL;

void insertItem(char* name, int quantity) {
  Item* newItem = (Item*)malloc(sizeof(Item));
  strcpy(newItem->name, name);
  newItem->quantity = quantity;
  newItem->next = NULL;

  if (head == NULL) {
    head = (Shelf*)malloc(sizeof(Shelf));
    head->items = newItem;
    head->next = NULL;
  } else {
    Shelf* currentShelf = head;
    while (currentShelf->next) {
      currentShelf = currentShelf->next;
    }
    currentShelf->next = (Shelf*)malloc(sizeof(Shelf));
    currentShelf = currentShelf->next;
    currentShelf->items = newItem;
    currentShelf->next = NULL;
  }
}

void showItems() {
  Shelf* currentShelf = head;
  while (currentShelf) {
    Item* currentItem = currentShelf->items;
    while (currentItem) {
      printf("%s - %d\n", currentItem->name, currentItem->quantity);
      currentItem = currentItem->next;
    }
    currentShelf = currentShelf->next;
  }
}

int main() {
  insertItem("Apple", 10);
  insertItem("Banana", 5);
  insertItem("Orange", 7);
  insertItem("Peach", 2);
  insertItem("Pear", 3);

  showItems();

  return 0;
}