//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct Node {
  double value;
  struct Node* next;
} Node;

Node* createNode(double value) {
  Node* newNode = malloc(sizeof(Node));
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}

void insertNode(Node* head, double value) {
  Node* newNode = createNode(value);
  if (head == NULL) {
    head = newNode;
  } else {
    newNode->next = head;
    head = newNode;
  }
}

double calculateCircuit(Node* head) {
  double totalResistance = 0.0;
  double totalVoltage = 0.0;
  double current = 0.0;

  while (head) {
    double resistance = head->value;
    totalResistance += resistance;
    head = head->next;
  }

  totalVoltage = 12.0;
  current = totalVoltage / totalResistance;

  return current;
}

int main() {
  Node* head = createNode(2.0);
  insertNode(head, 4.0);
  insertNode(head, 6.0);

  double current = calculateCircuit(head);

  printf("The current flowing through the circuit is: %.2f amperes", current);

  return 0;
}