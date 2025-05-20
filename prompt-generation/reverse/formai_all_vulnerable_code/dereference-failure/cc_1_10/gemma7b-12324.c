//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: introspective
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

typedef struct Node Node;

Node* insertAtTail(Node* head, struct Item item) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->item = item;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void displayItems(Node* head) {
  while (head) {
    printf("%s - %d - %.2f\n", head->item.name, head->item.quantity, head->item.price);
    head = head->next;
  }
}

int main() {
  struct Item item1 = {"Item 1", 10, 20.0};
  struct Item item2 = {"Item 2", 5, 30.0};
  struct Item item3 = {"Item 3", 15, 40.0};

  Node* head = insertAtTail(NULL, item1);
  head = insertAtTail(head, item2);
  head = insertAtTail(head, item3);

  displayItems(head);

  return 0;
}