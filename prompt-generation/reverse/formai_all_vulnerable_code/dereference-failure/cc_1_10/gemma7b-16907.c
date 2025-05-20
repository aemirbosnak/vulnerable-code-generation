//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: mind-bending
#include <stdio.h>
#include <math.h>

#define pi 3.14159

typedef struct node {
  int type;
  double value;
  struct node* next;
} node;

void sim_circuit(node* head) {
  node* current = head;
  while (current) {
    switch (current->type) {
      case 1:
        printf("Node type: Voltage source, value: %.2lf\n", current->value);
        break;
      case 2:
        printf("Node type: Resistor, value: %.2lf\n", current->value);
        break;
      case 3:
        printf("Node type: Capacitor, value: %.2lfF\n", current->value);
        break;
      case 4:
        printf("Node type: Indactor, value: %.2lfH\n", current->value);
        break;
      default:
        printf("Unknown node type\n");
        break;
    }
    current = current->next;
  }
}

int main() {
  node* head = NULL;
  node* new_node = NULL;

  new_node = malloc(sizeof(node));
  new_node->type = 1;
  new_node->value = 10.0;
  new_node->next = NULL;

  head = new_node;

  new_node = malloc(sizeof(node));
  new_node->type = 2;
  new_node->value = 2.0;
  new_node->next = NULL;

  head->next = new_node;

  new_node = malloc(sizeof(node));
  new_node->type = 3;
  new_node->value = 1.0F;
  new_node->next = NULL;

  head->next->next = new_node;

  sim_circuit(head);

  return 0;
}