//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: creative
// A Graph Representation in the Land of Candy

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the graph
struct Node {
  int data;  // value stored in the node
  struct Node* next; // pointer to the next node
};

// Function to create a new node
struct Node* newNode(int data) {
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  return node;
}

// Function to insert a node into the graph
void insertNode(struct Node** head_ref, int data) {
  struct Node* new_node = newNode(data);
  if (*head_ref == NULL) {
    *head_ref = new_node;
  } else {
    (*head_ref)->next = new_node;
  }
  (*head_ref)->next = new_node;
}

// Function to traverse the graph
void traverse(struct Node* head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
  struct Node* head = NULL;

  // Insert nodes into the graph
  insertNode(&head, 1);
  insertNode(&head, 2);
  insertNode(&head, 3);
  insertNode(&head, 4);
  insertNode(&head, 5);

  // Traverse the graph
  traverse(head);

  return 0;
}