//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
  int id;
  int value;
  struct Node *next;
} Node;

// Define the Circuit structure
typedef struct Circuit {
  int numNodes;
  Node *nodes;
} Circuit;

// Function to create a new circuit
Circuit *createCircuit(int numNodes) {
  Circuit *circuit = malloc(sizeof(Circuit));
  circuit->numNodes = numNodes;
  circuit->nodes = malloc(sizeof(Node) * numNodes);
  for (int i = 0; i < numNodes; i++) {
    circuit->nodes[i].id = i;
    circuit->nodes[i].value = 0;
    circuit->nodes[i].next = NULL;
  }
  return circuit;
}

// Function to add a new node to the circuit
void addNode(Circuit *circuit, int id, int value) {
  Node *newNode = malloc(sizeof(Node));
  newNode->id = id;
  newNode->value = value;
  newNode->next = NULL;

  Node *currNode = circuit->nodes;
  while (currNode->next != NULL) {
    currNode = currNode->next;
  }
  currNode->next = newNode;
}

// Function to simulate the circuit
void simulate(Circuit *circuit) {
  for (int i = 0; i < circuit->numNodes; i++) {
    Node *currNode = &circuit->nodes[i];

    // Calculate the output value for the current node
    int outputValue = 0;
    Node *nextNode = currNode->next;
    while (nextNode != NULL) {
      outputValue += nextNode->value;
      nextNode = nextNode->next;
    }

    // Update the current node's value
    currNode->value = outputValue;

    // Print the current node's value
    printf("Node %d: %d\n", currNode->id, currNode->value);
  }
}

// Function to destroy the circuit
void destroyCircuit(Circuit *circuit) {
  Node *currNode = circuit->nodes;
  while (currNode != NULL) {
    Node *next = currNode->next;
    free(currNode);
    currNode = next;
  }
  free(circuit);
}

// Main function
int main() {
  // Create a new circuit with 5 nodes
  Circuit *circuit = createCircuit(5);

  // Add a new node to the circuit
  addNode(circuit, 0, 1);

  // Add a new node to the circuit
  addNode(circuit, 1, 2);

  // Add a new node to the circuit
  addNode(circuit, 2, 3);

  // Add a new node to the circuit
  addNode(circuit, 3, 4);

  // Add a new node to the circuit
  addNode(circuit, 4, 5);

  // Simulate the circuit
  simulate(circuit);

  // Destroy the circuit
  destroyCircuit(circuit);

  return 0;
}