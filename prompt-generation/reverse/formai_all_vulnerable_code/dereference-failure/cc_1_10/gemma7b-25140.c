//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the circuit parameters
#define R1 100
#define R2 220
#define C1 0.01

// Define the circuit elements
typedef struct Node {
  double voltage;
  struct Node* next;
} Node;

// Create the circuit
Node* createCircuit() {
  Node* head = malloc(sizeof(Node));
  head->voltage = 0;
  head->next = NULL;

  Node* tail = head;

  // Add the other nodes
  tail->next = malloc(sizeof(Node));
  tail = tail->next;
  tail->voltage = 5.0;
  tail->next = NULL;

  return head;
}

// Simulate the circuit
void simulateCircuit(Node* head) {
  double time = 0;
  double dt = 0.01;

  // Calculate the voltage across the capacitor
  double v_cap = head->voltage * (1 - exp(-time / (R1 * C1)));

  // Print the voltage across the capacitor
  printf("Time: %.2f, Voltage across C1: %.2f\n", time, v_cap);

  // Update the time
  time += dt;
}

int main() {
  // Create the circuit
  Node* head = createCircuit();

  // Simulate the circuit
  simulateCircuit(head);

  return 0;
}