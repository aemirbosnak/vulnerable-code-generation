//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char data;
  struct Node* next;
  struct Node** parents;
} Node;

void insertNode(Node* node, char data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->parents = NULL;

  if (node == NULL) {
    node = newNode;
  } else {
    node->next = newNode;
  }

  return;
}

void traverseGraph(Node* node) {
  printf("%c ", node->data);

  if (node->parents) {
    for (Node* parent = node->parents; parent; parent = parent->next) {
      printf("%c ", parent->data);
    }
  }

  traverseGraph(node->next);
}

int main() {
  Node* graph = NULL;

  insertNode(graph, 'a');
  insertNode(graph, 'b');
  insertNode(graph, 'c');
  insertNode(graph, 'd');
  insertNode(graph, 'e');

  traverseGraph(graph);

  return 0;
}