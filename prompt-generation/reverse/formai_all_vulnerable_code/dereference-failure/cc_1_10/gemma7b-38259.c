//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int item_id;
  struct Node* next;
};

typedef struct Node Node;

void insert(Node** head, int item_id) {
  Node* newNode = malloc(sizeof(Node));
  newNode->item_id = item_id;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

int search(Node* head, int item_id) {
  while (head) {
    if (head->item_id == item_id) {
      return 1;
    } else {
      head = head->next;
    }
  }

  return 0;
}

int main() {
  Node* head = NULL;

  insert(&head, 10);
  insert(&head, 20);
  insert(&head, 30);
  insert(&head, 40);

  if (search(head, 30)) {
    printf("Item 30 found.\n");
  } else {
    printf("Item 30 not found.\n");
  }

  return 0;
}