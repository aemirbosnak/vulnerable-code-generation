//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Item {
  char name[20];
  int quantity;
  double price;
};

struct Node {
  struct Item item;
  struct Node* next;
};

void insertNode(struct Node** head, struct Item item) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->item = item;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void searchItem(struct Node* head, char* name) {
  while (head) {
    if (strcmp(head->item.name, name) == 0) {
      printf("Item name: %s\n", head->item.name);
      printf("Quantity: %d\n", head->item.quantity);
      printf("Price: %.2lf\n", head->item.price);
      return;
    }
    head = head->next;
  }

  printf("Item not found.\n");
}

int main() {
  struct Node* head = NULL;

  struct Item item1 = {"Item 1", 10, 20.0};
  insertNode(&head, item1);

  struct Item item2 = {"Item 2", 20, 30.0};
  insertNode(&head, item2);

  struct Item item3 = {"Item 3", 30, 40.0};
  insertNode(&head, item3);

  searchItem(head, "Item 2");

  return 0;
}