//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: Cyberpunk
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

Item* insertItem(Item* head, char* name, int quantity, double price) {
  Item* newNode = malloc(sizeof(Item));
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

  return head;
}

void printInventory(Item* head) {
  Item* temp = head;
  printf("Inventory:\n");
  while (temp) {
    printf("%s: %d @ $%.2lf\n", temp->name, temp->quantity, temp->price);
    temp = temp->next;
  }
}

int main() {
  Item* head = NULL;

  head = insertItem(head, "Cybernetic Rifle", 10, 200.0);
  insertItem(head, "Nano-Blades", 5, 150.0);
  insertItem(head, "Bio-Helmet", 2, 50.0);

  printInventory(head);

  return 0;
}