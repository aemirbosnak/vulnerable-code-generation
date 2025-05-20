//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>

struct Node {
  char name[20];
  int quantity;
  struct Node* next;
};

struct Node* insertAtTail(struct Node* head, char name, int quantity) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
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

struct Node* searchByName(struct Node* head, char name) {
  struct Node* current = head;

  while (current) {
    if (strcmp(current->name, name) == 0) {
      return current;
    }
    current = current->next;
  }

  return NULL;
}

int main() {
  struct Node* head = NULL;

  insertAtTail(head, "Apple", 10);
  insertAtTail(head, "Orange", 15);
  insertAtTail(head, "Banana", 20);

  struct Node* foundNode = searchByName(head, "Orange");

  if (foundNode) {
    printf("Found node: %s, quantity: %d", foundNode->name, foundNode->quantity);
  } else {
    printf("Node not found");
  }

  return 0;
}