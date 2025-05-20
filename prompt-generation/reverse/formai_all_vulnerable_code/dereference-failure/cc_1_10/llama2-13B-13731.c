//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a node in the graph
struct Node {
  int data; // data stored in the node
  struct Node* next; // pointer to the next node in the list
  struct Node* prev; // pointer to the previous node in the list
};

// Define a function to create a new node
struct Node* newNode(int data) {
  struct Node* node = malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

// Define a function to insert a node into the graph
void insertNode(struct Node** head_ref, int data) {
  struct Node* new_node = newNode(data);
  if (*head_ref == NULL) {
    *head_ref = new_node;
  } else {
    struct Node* current = *head_ref;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
  }
}

// Define a function to traverse the graph
void traverse(struct Node* node) {
  if (node != NULL) {
    printf("Node data: %d\n", node->data);
    traverse(node->next);
    traverse(node->prev);
  }
}

int main() {
  struct Node* head = NULL;

  // Insert nodes into the graph
  insertNode(&head, 1);
  insertNode(&head, 2);
  insertNode(&head, 3);
  insertNode(&head, 4);

  // Traverse the graph
  traverse(head);

  return 0;
}