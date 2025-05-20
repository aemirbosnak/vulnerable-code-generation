//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
  char name[50];
  int quantity;
  double price;
  struct Item* next;
} Item;

Item* head = NULL;

void insertItem(char* name, int quantity, double price) {
  Item* newItem = malloc(sizeof(Item));
  strcpy(newItem->name, name);
  newItem->quantity = quantity;
  newItem->price = price;
  newItem->next = NULL;

  if (head == NULL) {
    head = newItem;
  } else {
    Item* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newItem;
  }
}

void displayItems() {
  Item* temp = head;
  printf("Items:\n");
  while (temp) {
    printf("%s - %d - %.2lf\n", temp->name, temp->quantity, temp->price);
    temp = temp->next;
  }
}

void updateQuantity(char* name, int newQuantity) {
  Item* temp = head;
  while (temp) {
    if (strcmp(temp->name, name) == 0) {
      temp->quantity = newQuantity;
      return;
    }
    temp = temp->next;
  }
  printf("Item not found.\n");
}

int main() {
  insertItem("Apple", 10, 1.2);
  insertItem("Banana", 5, 1.5);
  insertItem("Orange", 7, 1.3);
  displayItems();
  updateQuantity("Banana", 8);
  displayItems();

  return 0;
}