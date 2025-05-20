//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

struct Item {
  char name[50];
  int quantity;
  float price;
};

struct Node {
  struct Item item;
  struct Node* next;
};

void insert(struct Node** head, struct Item item) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->item = item;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void search(struct Node* head, char* name) {
  while (head) {
    if (strcmp(head->item.name, name) == 0) {
      printf("Item name: %s, Quantity: %d, Price: %.2f\n", head->item.name, head->item.quantity, head->item.price);
      return;
    }
    head = head->next;
  }
  printf("Item not found.\n");
}

int main() {
  struct Node* head = NULL;

  struct Item item1 = {"Apple", 10, 2.50};
  insert(&head, item1);

  struct Item item2 = {"Banana", 5, 3.00};
  insert(&head, item2);

  struct Item item3 = {"Orange", 7, 2.75};
  insert(&head, item3);

  search(head, "Apple");

  search(head, "Banana");

  search(head, "Orange");

  search(head, "Kiwi");

  return 0;
}