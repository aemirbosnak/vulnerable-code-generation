//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of nodes
#define MAX_NODES 10

// Define the structure of a node
typedef struct Node {
  int node_id;
  struct Node* next_node;
} Node;

// Function to create a new node
Node* createNode(int node_id) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->node_id = node_id;
  new_node->next_node = NULL;
  return new_node;
}

// Function to insert a new node at the end
void insertNode(Node* head, int node_id) {
  Node* new_node = createNode(node_id);
  if (head == NULL) {
    head = new_node;
  } else {
    Node* temp = head;
    while (temp->next_node) {
      temp = temp->next_node;
    }
    temp->next_node = new_node;
  }
}

// Function to traverse the network topology
void traverseNetwork(Node* head) {
  printf("Traversing the network topology...\n");
  while (head) {
    printf("Node ID: %d\n", head->node_id);
    head = head->next_node;
  }
}

int main() {
  // Create a new network topology
  Node* head = createNode(0);
  insertNode(head, 1);
  insertNode(head, 2);
  insertNode(head, 3);
  insertNode(head, 4);

  // Traverse the network topology
  traverseNetwork(head);

  return 0;
}