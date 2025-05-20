//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_INPUTS 10
#define MAX_OUTPUTS 10

typedef struct node {
  int id;
  int type;
  int num_inputs;
  int num_outputs;
  int *inputs;
  int *outputs;
} node;

typedef struct circuit {
  int num_nodes;
  int num_inputs;
  int num_outputs;
  node *nodes;
} circuit;

circuit *create_circuit(int num_nodes, int num_inputs, int num_outputs) {
  circuit *c = malloc(sizeof(circuit));
  c->num_nodes = num_nodes;
  c->num_inputs = num_inputs;
  c->num_outputs = num_outputs;
  c->nodes = malloc(sizeof(node) * num_nodes);
  return c;
}

void destroy_circuit(circuit *c) {
  for (int i = 0; i < c->num_nodes; i++) {
    free(c->nodes[i].inputs);
    free(c->nodes[i].outputs);
  }
  free(c->nodes);
  free(c);
}

node *create_node(int id, int type, int num_inputs, int num_outputs) {
  node *n = malloc(sizeof(node));
  n->id = id;
  n->type = type;
  n->num_inputs = num_inputs;
  n->num_outputs = num_outputs;
  n->inputs = malloc(sizeof(int) * num_inputs);
  n->outputs = malloc(sizeof(int) * num_outputs);
  return n;
}

void destroy_node(node *n) {
  free(n->inputs);
  free(n->outputs);
  free(n);
}

void add_node(circuit *c, node *n) {
  c->nodes[c->num_nodes++] = *n;
}

void connect_nodes(circuit *c, int node1, int input1, int node2, int output1) {
  c->nodes[node1].outputs[c->nodes[node1].num_outputs++] = output1;
  c->nodes[node2].inputs[c->nodes[node2].num_inputs++] = input1;
}

void print_circuit(circuit *c) {
  for (int i = 0; i < c->num_nodes; i++) {
    printf("Node %d: type %d, %d inputs, %d outputs\n", c->nodes[i].id, c->nodes[i].type, c->nodes[i].num_inputs, c->nodes[i].num_outputs);
    for (int j = 0; j < c->nodes[i].num_inputs; j++) {
      printf("  Input %d: node %d\n", j, c->nodes[i].inputs[j]);
    }
    for (int j = 0; j < c->nodes[i].num_outputs; j++) {
      printf("  Output %d: node %d\n", j, c->nodes[i].outputs[j]);
    }
  }
}

int main() {
  circuit *c = create_circuit(5, 2, 1);

  node *n1 = create_node(0, 0, 0, 2);
  node *n2 = create_node(1, 1, 2, 1);
  node *n3 = create_node(2, 0, 1, 1);
  node *n4 = create_node(3, 1, 1, 1);
  node *n5 = create_node(4, 2, 1, 0);

  add_node(c, n1);
  add_node(c, n2);
  add_node(c, n3);
  add_node(c, n4);
  add_node(c, n5);

  connect_nodes(c, 0, 0, 1, 0);
  connect_nodes(c, 0, 1, 1, 1);
  connect_nodes(c, 2, 0, 1, 2);
  connect_nodes(c, 3, 0, 1, 3);
  connect_nodes(c, 4, 0, 2, 4);

  print_circuit(c);

  destroy_circuit(c);

  return 0;
}