//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the data structures used to represent the circuit.
typedef struct Node {
  char *name;
  int value;
  struct Node *next;
} Node;

// Define the function used to create a new node in the circuit.
Node *create_node(char *name, int value) {
  Node *node = malloc(sizeof(Node));
  if (node == NULL) {
    fprintf(stderr, "Error: Could not allocate memory for node.\n");
    exit(EXIT_FAILURE);
  }
  node->name = name;
  node->value = value;
  node->next = NULL;
  return node;
}

// Define the function used to add a new node to the circuit.
void add_node(Node **head, char *name, int value) {
  Node *node = create_node(name, value);
  if (*head == NULL) {
    *head = node;
  } else {
    node->next = *head;
    *head = node;
  }
}

// Define the function used to free the memory allocated for the circuit.
void free_circuit(Node *head) {
  Node *current = head;
  while (current != NULL) {
    Node *next = current->next;
    free(current->name);
    free(current);
    current = next;
  }
}

// Define the function used to print the circuit.
void print_circuit(Node *head) {
  Node *current = head;
  while (current != NULL) {
    printf("%s = %d\n", current->name, current->value);
    current = current->next;
  }
}

// Define the main function.
int main() {
  // Create the circuit.
  Node *head = NULL;
  add_node(&head, "A", 0);
  add_node(&head, "B", 0);
  add_node(&head, "C", 0);
  add_node(&head, "D", 0);

  // Print the circuit.
  print_circuit(head);

  // Free the memory allocated for the circuit.
  free_circuit(head);

  return 0;
}