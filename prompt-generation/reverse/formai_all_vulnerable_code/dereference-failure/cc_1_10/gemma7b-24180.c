//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct Item {
  char name[50];
  int quantity;
  float price;
  struct Item* next;
} Item;

Item* head = NULL;

void addItem(char* name, int quantity, float price) {
  Item* newNode = malloc(sizeof(Item));

  strcpy(newNode->name, name);
  newNode->quantity = quantity;
  newNode->price = price;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }
}

void displayItems() {
  Item* currentItem = head;

  printf("Inventory:\n");
  while (currentItem) {
    printf("%s: %d @ $%.2f\n", currentItem->name, currentItem->quantity, currentItem->price);
    currentItem = currentItem->next;
  }
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

int main() {
  addItem("Plasma Rifle", 10, 200.0);
  addItem("Energy Shield", 5, 150.0);
  addItem("Nano Grenades", 2, 75.0);

  displayItems();

  updateQuantity("Plasma Rifle", 15);

  displayItems();

  return 0;
}