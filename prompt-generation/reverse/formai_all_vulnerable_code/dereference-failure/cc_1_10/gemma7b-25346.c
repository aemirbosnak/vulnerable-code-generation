//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_ITEMS 100

typedef struct Item {
  char name[50];
  int quantity;
  double price;
  struct Item* next;
} Item;

Item* addItem(Item* head, char* name, int quantity, double price) {
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

  return head;
}

void updateQuantity(Item* head, char* name, int newQuantity) {
  Item* currentItem = head;

  while (currentItem) {
    if (strcmp(currentItem->name, name) == 0) {
      currentItem->quantity = newQuantity;
      break;
    }
    currentItem = currentItem->next;
  }
}

double calculateTotalCost(Item* head) {
  double totalCost = 0;

  Item* currentItem = head;

  while (currentItem) {
    totalCost += currentItem->quantity * currentItem->price;
    currentItem = currentItem->next;
  }

  return totalCost;
}

int main() {
  Item* head = NULL;

  // Add items to the inventory
  addItem(head, "Sword", 10, 100.0);
  addItem(head, "Shield", 5, 50.0);
  addItem(head, "Potion", 20, 20.0);

  // Update the quantity of the Sword
  updateQuantity(head, "Sword", 15);

  // Calculate the total cost of the inventory
  double totalCost = calculateTotalCost(head);

  // Print the total cost
  printf("Total cost: $%.2lf\n", totalCost);

  return 0;
}