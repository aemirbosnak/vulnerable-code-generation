//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define the types of nodes
typedef enum {
  NODE_TYPE_INPUT,
  NODE_TYPE_OUTPUT,
  NODE_TYPE_AND,
  NODE_TYPE_OR,
  NODE_TYPE_NOT
} node_type;

// Define the structure of a node
typedef struct node {
  node_type type;
  int value;
  struct node *inputs[2];
  struct node *output;
} node;

// Create a new node
node *create_node(node_type type, int value) {
  node *new_node = malloc(sizeof(node));
  new_node->type = type;
  new_node->value = value;
  new_node->inputs[0] = NULL;
  new_node->inputs[1] = NULL;
  new_node->output = NULL;
  return new_node;
}

// Connect two nodes together
void connect_nodes(node *from, node *to) {
  if (to->type == NODE_TYPE_INPUT) {
    printf("Error: Cannot connect to an input node\n");
    return;
  }

  if (from->output != NULL) {
    printf("Error: Node already has an output\n");
    return;
  }

  from->output = to;
  to->inputs[0] = from;
}

// Evaluate a node
int evaluate_node(node *node) {
  switch (node->type) {
    case NODE_TYPE_INPUT:
      return node->value;
    case NODE_TYPE_OUTPUT:
      return node->inputs[0]->value;
    case NODE_TYPE_AND:
      return node->inputs[0]->value && node->inputs[1]->value;
    case NODE_TYPE_OR:
      return node->inputs[0]->value || node->inputs[1]->value;
    case NODE_TYPE_NOT:
      return !node->inputs[0]->value;
  }

  return 0;
}

// Print the circuit
void print_circuit(node *head) {
  printf("Circuit:\n");
  while (head != NULL) {
    printf("  %d: ", head->value);
    switch (head->type) {
      case NODE_TYPE_INPUT:
        printf("Input\n");
        break;
      case NODE_TYPE_OUTPUT:
        printf("Output\n");
        break;
      case NODE_TYPE_AND:
        printf("AND\n");
        break;
      case NODE_TYPE_OR:
        printf("OR\n");
        break;
      case NODE_TYPE_NOT:
        printf("NOT\n");
        break;
    }
    head = head->output;
  }
}

// Free the circuit
void free_circuit(node *head) {
  while (head != NULL) {
    node *next = head->output;
    free(head);
    head = next;
  }
}

int main() {
  // Create the nodes
  node *input1 = create_node(NODE_TYPE_INPUT, 1);
  node *input2 = create_node(NODE_TYPE_INPUT, 0);
  node *and1 = create_node(NODE_TYPE_AND, 0);
  node *output1 = create_node(NODE_TYPE_OUTPUT, 0);

  // Connect the nodes
  connect_nodes(input1, and1);
  connect_nodes(input2, and1);
  connect_nodes(and1, output1);

  // Print the circuit
  print_circuit(input1);

  // Evaluate the circuit
  int output = evaluate_node(output1);

  // Print the output
  printf("Output: %d\n", output);

  // Free the circuit
  free_circuit(input1);

  return 0;
}