//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct Item {
  char name[20];
  int quantity;
  struct Item* next;
} Item;

Item* head = NULL;

void insertItem(char* name, int quantity) {
  Item* newNode = (Item*)malloc(sizeof(Item));
  strcpy(newNode->name, name);
  newNode->quantity = quantity;
  newNode->next = head;
  head = newNode;
}

void updateQuantity(char* name, int newQuantity) {
  Item* currentItem = head;
  while (currentItem) {
    if (strcmp(currentItem->name, name) == 0) {
      currentItem->quantity = newQuantity;
      return;
    }
    currentItem = currentItem->next;
  }
  printf("Item not found.\n");
}

void printItems() {
  Item* currentItem = head;
  while (currentItem) {
    printf("%s: %d\n", currentItem->name, currentItem->quantity);
    currentItem = currentItem->next;
  }
}

int main() {
  insertItem("Apple", 10);
  insertItem("Banana", 5);
  insertItem("Orange", 20);
  printItems();

  updateQuantity("Apple", 15);
  printItems();

  return 0;
}