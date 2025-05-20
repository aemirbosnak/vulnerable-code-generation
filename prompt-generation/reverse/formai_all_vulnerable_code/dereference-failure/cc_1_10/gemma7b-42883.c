//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
  char name[MAX_SIZE];
  struct Node* next;
  struct Node* prev;
} Node;

void insert(Node* node, char name) {
  node = malloc(sizeof(struct Node));
  strcpy(node->name, name);
  node->next = NULL;
  node->prev = NULL;

  if (node->next) {
    node->next->prev = node;
  }

  return;
}

void findRoute(Node* head, char* start, char* end) {
  Node* current = head;
  while (strcmp(current->name, start) != 0) {
    current = current->next;
  }

  current = current->next;
  while (strcmp(current->name, end) != 0) {
    printf("%s -> ", current->name);
    current = current->next;
  }

  return;
}

int main() {
  Node* head = NULL;
  insert(head, "A");
  insert(head, "B");
  insert(head, "C");
  insert(head, "D");
  insert(head, "E");
  insert(head, "F");

  findRoute(head, "A", "F");

  return 0;
}