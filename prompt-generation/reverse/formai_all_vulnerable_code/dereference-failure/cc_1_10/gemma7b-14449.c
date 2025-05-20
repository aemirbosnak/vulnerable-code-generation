//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
  char name[20];
  int quantity;
  struct Item* next;
} Item;

void createItem(Item** head) {
  *head = malloc(sizeof(Item));
  (*head)->name[0] = '\0';
  (*head)->quantity = 0;
  (*head)->next = NULL;
}

void addItem(Item** head, char name, int quantity) {
  Item* newNode = malloc(sizeof(Item));
  newNode->name[0] = '\0';
  newNode->quantity = quantity;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    ((*head)->next)->next = newNode;
  }
}

void showItems(Item* head) {
  Item* current = head;
  printf("Items:\n");
  while (current) {
    printf("%s: %d\n", current->name, current->quantity);
    current = current->next;
  }
}

int main() {
  Item* inventory = NULL;

  // Create a few items
  createItem(&inventory);
  addItem(&inventory, "Plasma Cutter", 3);
  addItem(&inventory, "Energy Shield", 2);
  addItem(&inventory, "Nanobot Suit", 1);

  // Show the items in the inventory
  showItems(inventory);

  // Use the items
  printf("You use your Plasma Cutter to cut a hole in a wall.\n");
  printf("You activate your Energy Shield to protect yourself from danger.\n");
  printf("You put on your Nanobot Suit to explore the galaxy.\n");

  return 0;
}