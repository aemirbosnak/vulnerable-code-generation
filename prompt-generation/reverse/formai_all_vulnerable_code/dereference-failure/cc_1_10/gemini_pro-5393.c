//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
  int id;
  int type;
  int num_inputs;
  int num_outputs;
  int *inputs;
  int *outputs;
} Node;

typedef struct {
  int id;
  int source;
  int destination;
} Edge;

typedef struct {
  int num_nodes;
  int num_edges;
  Node *nodes;
  Edge *edges;
} Circuit;

Circuit *create_circuit(int num_nodes, int num_edges) {
  Circuit *circuit = malloc(sizeof(Circuit));
  circuit->num_nodes = num_nodes;
  circuit->num_edges = num_edges;
  circuit->nodes = malloc(sizeof(Node) * num_nodes);
  circuit->edges = malloc(sizeof(Edge) * num_edges);
  return circuit;
}

void destroy_circuit(Circuit *circuit) {
  free(circuit->nodes);
  free(circuit->edges);
  free(circuit);
}

void add_node(Circuit *circuit, int id, int type, int num_inputs, int num_outputs) {
  Node *node = &circuit->nodes[id];
  node->id = id;
  node->type = type;
  node->num_inputs = num_inputs;
  node->num_outputs = num_outputs;
  node->inputs = malloc(sizeof(int) * num_inputs);
  node->outputs = malloc(sizeof(int) * num_outputs);
}

void add_edge(Circuit *circuit, int id, int source, int destination) {
  Edge *edge = &circuit->edges[id];
  edge->id = id;
  edge->source = source;
  edge->destination = destination;
}

void print_circuit(Circuit *circuit) {
  printf("Circuit:\n");
  printf("  Number of nodes: %d\n", circuit->num_nodes);
  printf("  Number of edges: %d\n", circuit->num_edges);
  for (int i = 0; i < circuit->num_nodes; i++) {
    Node *node = &circuit->nodes[i];
    printf("  Node %d:\n", node->id);
    printf("    Type: %d\n", node->type);
    printf("    Number of inputs: %d\n", node->num_inputs);
    printf("    Number of outputs: %d\n", node->num_outputs);
    printf("    Inputs: ");
    for (int j = 0; j < node->num_inputs; j++) {
      printf("%d ", node->inputs[j]);
    }
    printf("\n");
    printf("    Outputs: ");
    for (int j = 0; j < node->num_outputs; j++) {
      printf("%d ", node->outputs[j]);
    }
    printf("\n");
  }
  for (int i = 0; i < circuit->num_edges; i++) {
    Edge *edge = &circuit->edges[i];
    printf("  Edge %d:\n", edge->id);
    printf("    Source: %d\n", edge->source);
    printf("    Destination: %d\n", edge->destination);
  }
}

int main() {
  Circuit *circuit = create_circuit(5, 6);

  add_node(circuit, 0, 0, 1, 1);
  add_node(circuit, 1, 1, 1, 1);
  add_node(circuit, 2, 2, 1, 1);
  add_node(circuit, 3, 3, 2, 1);
  add_node(circuit, 4, 4, 1, 1);

  add_edge(circuit, 0, 0, 1);
  add_edge(circuit, 1, 1, 2);
  add_edge(circuit, 2, 2, 3);
  add_edge(circuit, 3, 3, 4);
  add_edge(circuit, 4, 4, 0);
  add_edge(circuit, 5, 0, 3);

  print_circuit(circuit);

  destroy_circuit(circuit);

  return 0;
}