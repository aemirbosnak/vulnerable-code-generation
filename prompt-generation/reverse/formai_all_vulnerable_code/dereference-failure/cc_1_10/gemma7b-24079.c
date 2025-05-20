//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
  int data;
  struct Node* next;
} Node;

struct Index {
  int key;
  struct Node* node;
};

void insert(struct Index** head, int data) {
  struct Index* newNode = malloc(sizeof(struct Index));
  newNode->key = data;
  newNode->node = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    ((*head)->node)->next = newNode;
  }

  (*head)->node = newNode;
}

void search(struct Index* head, int key) {
  while (head) {
    if (head->key == key) {
      printf("Data: %d\n", head->node->data);
    }
    head = head->node->next;
  }
}

int main() {
  struct Index* head = NULL;

  insert(&head, 10);
  insert(&head, 20);
  insert(&head, 30);
  insert(&head, 40);
  insert(&head, 50);

  search(head, 30);
  search(head, 50);

  return 0;
}