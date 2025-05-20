//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

struct Node {
  char name[20];
  int quantity;
  struct Node* next;
};

typedef struct Node Node;

void insert(Node** head, char name, int quantity) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->quantity = quantity;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void search(Node* head, char name) {
  while (head) {
    if (strcmp(head->name, name) == 0) {
      printf("Quantity: %d\n", head->quantity);
      return;
    }
    head = head->next;
  }
  printf("Item not found.\n");
}

void update(Node* head, char name, int quantity) {
  while (head) {
    if (strcmp(head->name, name) == 0) {
      head->quantity = quantity;
      return;
    }
    head = head->next;
  }
  printf("Item not found.\n");
}

void delete(Node* head, char name) {
  Node* prev = NULL;
  while (head) {
    if (strcmp(head->name, name) == 0) {
      if (prev) {
        prev->next = head->next;
      } else {
        head = head->next;
      }
      free(head);
      return;
    }
    prev = head;
    head = head->next;
  }
  printf("Item not found.\n");
}

int main() {
  Node* head = NULL;

  insert(&head, "Apple", 10);
  insert(&head, "Banana", 20);
  insert(&head, "Orange", 30);

  search(head, "Apple");
  update(head, "Banana", 30);
  delete(head, "Orange");

  search(head, "Apple");

  return 0;
}