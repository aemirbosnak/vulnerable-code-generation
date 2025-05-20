//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: happy
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

typedef struct Item Item;
typedef struct Node Node;

void insert(Node** head, Item item) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->item = item;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void search(Node* head, char* name) {
  while (head) {
    if (strcmp(head->item.name, name) == 0) {
      printf("Item: %s, Quantity: %d, Price: %.2f\n", head->item.name, head->item.quantity, head->item.price);
      return;
    }
    head = head->next;
  }
  printf("Item not found.\n");
}

int main() {
  Node* head = NULL;

  Item item1 = {"Panadol", 20, 50.0};
  insert(&head, item1);

  Item item2 = {"Brufen", 15, 40.0};
  insert(&head, item2);

  Item item3 = {"Tylenol", 10, 30.0};
  insert(&head, item3);

  search(head, "Panadol");

  search(head, "Brufen");

  search(head, "Tylenol");

  return 0;
}