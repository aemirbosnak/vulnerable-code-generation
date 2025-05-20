//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node {
  char data;
  struct Node* next;
} Node;

struct Node* insert(struct Node* head, char data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void findPath(struct Node* head, char target) {
  struct Node* current = head;

  while (current) {
    if (current->data == target) {
      printf("Path found!\n");
      return;
    } else if (current->next) {
      findPath(current->next, target);
    }
    current = current->next;
  }

  printf("Target not found.\n");
}

int main() {
  struct Node* head = NULL;

  insert(head, 'a');
  insert(head, 'b');
  insert(head, 'c');
  insert(head, 'd');
  insert(head, 'e');

  findPath(head, 'c');

  return 0;
}