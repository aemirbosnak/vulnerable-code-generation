//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
  char name[50];
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
  while (head) {
    printf("%s: %d\n", head->name, head->quantity);
    head = head->next;
  }
}

int main() {
  Item* head = NULL;

  // Paranoid code begins
  head = addItem(head, "Nuclear Missile", 10);
  head = addItem(head, "Bioweapon", 5);
  head = addItem(head, "Doomsday Device", 2);

  checkInventory(head);

  // Check for suspicious activity
  if (strcmp(head->name, "Doomsday Device") == 0) {
    printf("WARNING: Doomsday Device detected!\n");
  }

  // Lock down the warehouse
  printf("Please enter the secret password to secure the warehouse:");
  char password[20];
  scanf("%s", password);

  if (strcmp(password, "Armageddon") == 0) {
    printf("Access granted. The warehouse is safe.\n");
  } else {
    printf("Invalid password. The warehouse is under lockdown.\n");
  }

  return 0;
}