//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

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
    return newNode;
  }

  head->next = newNode;
  return newNode;
}

int getItemQuantity(Item* head, char* name) {
  Item* currentItem = head;

  while (currentItem) {
    if (strcmp(currentItem->name, name) == 0) {
      return currentItem->quantity;
    }

    currentItem = currentItem->next;
  }

  return -1;
}

int main() {
  Item* head = NULL;

  insertItem(&head, "Apple", 10);
  insertItem(&head, "Banana", 20);
  insertItem(&head, "Orange", 30);

  int quantity = getItemQuantity(head, "Banana");

  if (quantity != -1) {
    printf("The quantity of Banana is: %d", quantity);
  } else {
    printf("Item not found.");
  }

  return 0;
}