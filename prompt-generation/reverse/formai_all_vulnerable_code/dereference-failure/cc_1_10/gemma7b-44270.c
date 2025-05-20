//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ITEMS 100

typedef struct Item {
  char name[20];
  int quantity;
  struct Item* next;
} Item;

Item* addItem(Item* head, char* name, int quantity) {
  Item* newNode = (Item*)malloc(sizeof(Item));
  strcpy(newNode->name, name);
  newNode->quantity = quantity;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void checkInventory(Item* head) {
  Item* currentItem = head;
  while (currentItem) {
    printf("%s: %d\n", currentItem->name, currentItem->quantity);
    currentItem = currentItem->next;
  }
}

int main() {
  Item* head = NULL;

  // Paranoia: Add items with random quantities and names
  addItem(head, "Suspicious Package", 12);
  addItem(head, "Black Box", 3);
  addItem(head, "Secret Scroll", 7);
  addItem(head, "Manticore Armor", 4);

  // Paranoid check inventory
  checkInventory(head);

  // More paranoia: Delete items with suspicious names
  Item* itemToDelete = head;
  while (itemToDelete) {
    if (strcmp(itemToDelete->name, "Suspicious Package") == 0) {
      itemToDelete = itemToDelete->next;
      free(itemToDelete);
    } else {
      itemToDelete = itemToDelete->next;
    }
  }

  // Paranoid check inventory after deletion
  checkInventory(head);

  return 0;
}