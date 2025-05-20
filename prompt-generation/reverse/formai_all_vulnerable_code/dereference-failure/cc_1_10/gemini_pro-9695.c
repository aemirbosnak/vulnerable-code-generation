//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: shape shifting
// A polymorphic linked list implementation
//
// The core idea here is to have a "shape-shifting" linked list, where each node can
// dynamically change its type to represent different data types. This allows us to
// store a heterogeneous collection of data in a single linked list.
//
// To achieve this, we define a generic "Node" struct that contains a pointer to the
// next node and a pointer to the actual data. The data pointer is type-erased, so it
// can point to data of any type.
//
// Each node also has a "type" field that indicates the type of data that is stored
// in the node. This allows us to safely cast the data pointer to the correct type
// when we need to access the data.
//
// The linked list itself is implemented as a pointer to the head node. We provide a
// set of functions to insert, delete, and search for nodes in the linked list.
//
// Here is the code:

#include <stdio.h>
#include <stdlib.h>

// A generic node struct
typedef struct Node {
  struct Node *next;
  void *data;
  int type;
} Node;

// A pointer to the head node of the linked list
Node *head = NULL;

// Function to insert a new node at the beginning of the linked list
void insert_node(int type, void *data) {
  // Allocate memory for the new node
  Node *new_node = malloc(sizeof(Node));

  // Set the data pointer and type of the new node
  new_node->data = data;
  new_node->type = type;

  // Insert the new node at the beginning of the linked list
  new_node->next = head;
  head = new_node;
}

// Function to delete a node from the linked list
void delete_node(Node *node) {
  // If the node is the head node, simply update the head pointer
  if (node == head) {
    head = node->next;
  } else {
    // Otherwise, find the previous node and update its next pointer
    Node *prev = head;
    while (prev->next != node) {
      prev = prev->next;
    }
    prev->next = node->next;
  }

  // Free the memory for the deleted node
  free(node);
}

// Function to search for a node in the linked list
Node *search_node(int type, void *data) {
  // Iterate over the linked list and compare each node's data and type
  Node *current = head;
  while (current != NULL) {
    if (current->type == type && current->data == data) {
      return current;
    }
    current = current->next;
  }

  // If the node was not found, return NULL
  return NULL;
}

// Function to print the linked list
void print_list() {
  // Iterate over the linked list and print each node's data and type
  Node *current = head;
  while (current != NULL) {
    switch (current->type) {
      case 0:
        printf("Node %p: int %d\n", current, *(int *)current->data);
        break;
      case 1:
        printf("Node %p: float %f\n", current, *(float *)current->data);
        break;
      case 2:
        printf("Node %p: string %s\n", current, (char *)current->data);
        break;
      default:
        printf("Node %p: unknown type\n", current);
        break;
    }
    current = current->next;
  }
}

// Example usage
int main() {
  // Insert a few nodes into the linked list
  int i = 10;
  float f = 3.14;
  char *s = "Hello";
  insert_node(0, &i);
  insert_node(1, &f);
  insert_node(2, s);

  // Print the linked list
  print_list();

  // Search for a node in the linked list
  Node *node = search_node(2, s);
  if (node != NULL) {
    printf("Found node: %s\n", (char *)node->data);
  } else {
    printf("Node not found\n");
  }

  // Delete a node from the linked list
  delete_node(node);

  // Print the linked list
  print_list();

  return 0;
}