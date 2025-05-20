//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Item {
  char name[20];
  int quantity;
  float price;
};

struct Node {
  struct Item item;
  struct Node* next;
};

typedef struct Node Node;

void insertAtTail(Node** head, struct Item item) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->item = item;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void printItems(Node* head) {
  while (head) {
    printf("%s - %d - %.2f\n", head->item.name, head->item.quantity, head->item.price);
    head = head->next;
  }
}

int main() {
  Node* head = NULL;

  struct Item item1 = {"Item 1", 10, 20.0};
  insertAtTail(&head, item1);

  struct Item item2 = {"Item 2", 20, 30.0};
  insertAtTail(&head, item2);

  struct Item item3 = {"Item 3", 30, 40.0};
  insertAtTail(&head, item3);

  printItems(head);

  return 0;
}