//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  int quantity;
  struct Node* next;
} InventoryItem;

typedef struct Node {
  InventoryItem item;
  struct Node* next;
} Node;

Node* head = NULL;

void addItemToInventory(char* name, int quantity) {
  Node* newNode = (Node*) malloc(sizeof(Node));
  InventoryItem* newItem = &newNode->item;
  strcpy(newItem->name, name);
  newItem->quantity = quantity;
  newItem->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    Node* current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }
}

void displayInventory() {
  Node* current = head;
  while (current != NULL) {
    printf("%s: %d\n", current->item.name, current->item.quantity);
    current = current->next;
  }
}

int main() {
  addItemToInventory("Book", 10);
  addItemToInventory("Laptop", 5);
  addItemToInventory("Monitor", 3);
  displayInventory();

  return 0;
}