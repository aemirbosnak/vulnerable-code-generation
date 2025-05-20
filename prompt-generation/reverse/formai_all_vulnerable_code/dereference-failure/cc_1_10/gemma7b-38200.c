//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
  char name[20];
  int quantity;
  double price;
  struct Item* next;
};

struct Node {
  struct Item* item;
  struct Node* next;
};

struct Warehouse {
  struct Node* head;
  struct Node* tail;
  int totalItems;
  double totalValue;
};

void insertItem(struct Warehouse* warehouse, char* name, int quantity, double price) {
  struct Item* newItem = (struct Item*)malloc(sizeof(struct Item));
  strcpy(newItem->name, name);
  newItem->quantity = quantity;
  newItem->price = price;
  newItem->next = NULL;

  if (warehouse->head == NULL) {
    warehouse->head = warehouse->tail = newItem;
  } else {
    warehouse->tail->next = newItem;
    warehouse->tail = newItem;
  }

  warehouse->totalItems++;
  warehouse->totalValue += quantity * price;
}

void removeItem(struct Warehouse* warehouse, char* name) {
  struct Node* previousNode = NULL;
  struct Node* currentNode = warehouse->head;

  while (currentNode) {
    if (strcmp(currentNode->item->name, name) == 0) {
      if (previousNode) {
        previousNode->next = currentNode->next;
        warehouse->tail = previousNode;
      } else {
        warehouse->head = warehouse->tail = NULL;
      }

      warehouse->totalItems--;
      warehouse->totalValue -= currentNode->item->quantity * currentNode->item->price;
      free(currentNode->item);
      free(currentNode);
      return;
    }

    previousNode = currentNode;
    currentNode = currentNode->next;
  }

  printf("Item not found.\n");
}

void displayItems(struct Warehouse* warehouse) {
  struct Node* currentNode = warehouse->head;

  printf("Items in the warehouse:\n");
  while (currentNode) {
    printf("%s - %d - %.2lf\n", currentNode->item->name, currentNode->item->quantity, currentNode->item->price);
  }

  printf("Total items: %d\n", warehouse->totalItems);
  printf("Total value: %.2lf\n", warehouse->totalValue);
}

int main() {
  struct Warehouse* warehouse = (struct Warehouse*)malloc(sizeof(struct Warehouse));
  warehouse->head = warehouse->tail = NULL;
  warehouse->totalItems = 0;
  warehouse->totalValue = 0.0;

  insertItem(warehouse, "Apple", 10, 1.20);
  insertItem(warehouse, "Banana", 20, 0.80);
  insertItem(warehouse, "Orange", 30, 0.90);
  insertItem(warehouse, "Grape", 40, 1.00);

  displayItems(warehouse);

  removeItem(warehouse, "Banana");

  displayItems(warehouse);

  free(warehouse);

  return 0;
}