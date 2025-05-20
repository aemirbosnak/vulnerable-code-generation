//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

typedef struct Node {
  char data;
  struct Node* next;
  struct Node* prev;
} Node;

void insert(Node** head, char data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->prev = newNode;
    (*head) = newNode;
  }
}

void findRoute(Node* head, char target) {
  while (head) {
    if (head->data == target) {
      printf("Route found!\n");
      return;
    } else if (head->next) {
      findRoute(head->next, target);
    } else {
      printf("Target not found.\n");
      return;
    }
  }
}

int main() {
  Node* head = NULL;
  insert(&head, 'a');
  insert(&head, 'b');
  insert(&head, 'c');
  insert(&head, 'd');
  insert(&head, 'e');

  findRoute(head, 'c');

  return 0;
}