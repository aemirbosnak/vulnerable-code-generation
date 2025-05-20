//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Node structure for a singly linked list
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// Function to create a new node
Node* create_node(int data) {
  Node *new_node = (Node*)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Function to visualize the linked list
void visualize_linked_list(Node *head) {
  // Create a visualization string
  char *visualization = (char*)malloc(100 * sizeof(char));
  strcpy(visualization, "");

  // Iterate through the linked list and add each node's data to the visualization string
  Node *current_node = head;
  while (current_node != NULL) {
    char *node_data = (char*)malloc(10 * sizeof(char));
    sprintf(node_data, "%d", current_node->data);
    strcat(visualization, node_data);
    strcat(visualization, " -> ");
    current_node = current_node->next;
  }

  // Add a NULL pointer to the end of the visualization string
  strcat(visualization, "NULL");

  // Print the visualization string
  printf("%s\n", visualization);

  // Free the visualization string
  free(visualization);
}

// Main function
int main() {
  // Create a linked list
  Node *head = create_node(1);
  head->next = create_node(2);
  head->next->next = create_node(3);
  head->next->next->next = create_node(4);
  head->next->next->next->next = create_node(5);

  // Visualize the linked list
  visualize_linked_list(head);

  return 0;
}