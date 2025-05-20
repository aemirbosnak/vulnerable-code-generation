//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
  char name[50];
  int quantity;
  float price;
  struct Item* next;
} Item;

Item* head = NULL;

void insertItem(char* name, int quantity, float price) {
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
      break;
    }
    temp = temp->next;
  }
}

void printInventory() {
  Item* temp = head;
  printf("Inventory:\n");
  while (temp) {
    printf("%s: %d, $%.2f\n", temp->name, temp->quantity, temp->price);
    temp = temp->next;
  }
}

int main() {
  insertItem("Apple", 10, 1.20);
  insertItem("Banana", 5, 1.50);
  insertItem("Orange", 7, 1.30);
  updateQuantity("Apple", 12);
  printInventory();

  return 0;
}