//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a node in a network topology.
typedef struct Node {
  char name[256];
  struct Node* next;
  struct Node* prev;
  struct Node* up;
  struct Node* down;
} Node;

// Function to create a new node in the network topology.
Node* newNode(char* name) {
  Node* node = (Node*)malloc(sizeof(Node));
  strcpy(node->name, name);
  node->next = NULL;
  node->prev = NULL;
  node->up = NULL;
  node->down = NULL;
  return node;
}

// Function to add a new node to the end of the list.
void addToEnd(Node* node, Node* newNode) {
  if (node == NULL) {
    node = newNode;
  } else {
    node->next = newNode;
    newNode->prev = node;
  }
  return;
}

// Function to traverse the network topology.
void traverseNetwork(Node* node) {
  printf("%s ", node->name);
  if (node->up) {
    printf("Up: %s ", node->up->name);
  }
  if (node->down) {
    printf("Down: %s ", node->down->name);
  }
  printf("\n");
  if (node->next) {
    traverseNetwork(node->next);
  }
  return;
}

int main() {
  // Create a new network topology.
  Node* head = newNode("A");
  addToEnd(head, newNode("B"));
  addToEnd(head, newNode("C"));
  addToEnd(head, newNode("D"));
  addToEnd(head, newNode("E"));

  // Traverse the network topology.
  traverseNetwork(head);

  return 0;
}