//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ITEMS 100

typedef struct Item {
  char name[20];
  int quantity;
  double price;
  struct Item* next;
} Item;

Item* head = NULL;

void addItem(char* name, int quantity, double price) {
  Item* newNode = (Item*)malloc(sizeof(Item));
  strcpy(newNode->name, name);
  newNode->quantity = quantity;
  newNode->price = price;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    Item* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void updateQuantity(char* name, int quantity) {
  Item* temp = head;
  while (temp) {
    if (strcmp(temp->name, name) == 0) {
      temp->quantity = quantity;
      return;
    }
    temp = temp->next;
  }
  printf("Item not found.\n");
}

void printInventory() {
  Item* temp = head;
  while (temp) {
    printf("%s: %d, $%.2lf\n", temp->name, temp->quantity, temp->price);
    temp = temp->next;
  }
}

int main() {
  addItem("Apple", 10, 1.25);
  addItem("Banana", 5, 0.89);
  addItem("Orange", 7, 1.49);
  addItem("Peach", 2, 1.65);

  updateQuantity("Banana", 12);

  printInventory();

  return 0;
}