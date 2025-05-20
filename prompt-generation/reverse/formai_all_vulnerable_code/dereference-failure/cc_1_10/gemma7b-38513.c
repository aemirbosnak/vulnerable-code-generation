//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct Item {
  char name[20];
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

int main() {
  Item* head = NULL;

  // Paranoia begins here
  head = addItem(head, "Paranoia Pills", 10, 2.99);
  head = addItem(head, "Anti-Paranoid Pills", 20, 3.29);
  head = addItem(head, "Trust Pills", 1, 4.99);

  // Check for hidden trackers
  for (Item* current = head; current; current = current->next) {
    if (strcmp(current->name, "Trust Pills") == 0) {
      printf("DANGER! Trust Pills detected!\n");
      exit(1);
    }
  }

  // Destroy all pills
  for (Item* current = head; current; current = current->next) {
    free(current);
  }

  // You're safe now
  printf("All pills destroyed. You are safe.\n");

  return 0;
}