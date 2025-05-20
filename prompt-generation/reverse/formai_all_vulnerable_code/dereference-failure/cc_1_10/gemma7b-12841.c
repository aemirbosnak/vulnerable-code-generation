//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INVENTORY_SIZE 100

typedef struct Item {
  char name[20];
  int quantity;
  struct Item* next;
} Item;

Item* insertItem(Item* head, char* name, int quantity) {
  Item* newNode = malloc(sizeof(Item));
  strcpy(newNode->name, name);
  newNode->quantity = quantity;
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

  return head;
}

void printInventory(Item* head) {
  Item* temp = head;
  while (temp) {
    printf("%s: %d\n", temp->name, temp->quantity);
    temp = temp->next;
  }
}

int main() {
  Item* inventory = NULL;

  // Paranoia begins
  inventory = insertItem(inventory, "Paranoia Pills", 10);
  inventory = insertItem(inventory, "Trust Issues", 5);
  inventory = insertItem(inventory, "Fear of Flying", 2);
  inventory = insertItem(inventory, "The Cold", 3);
  inventory = insertItem(inventory, "A Healthy Mind", 0);

  printInventory(inventory);

  return 0;
}