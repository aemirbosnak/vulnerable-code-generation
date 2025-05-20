//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: ultraprecise
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct _circuit_node circuit_node_t;
struct _circuit_node {
  char *label;
  int potential;
};

typedef struct _circuit_edge circuit_edge_t;
struct _circuit_edge {
  circuit_node_t *from;
  circuit_node_t *to;
  double resistance;
};

typedef struct _circuit circuit_t;
struct _circuit {
  size_t num_nodes;
  size_t num_edges;
  circuit_node_t **nodes;
  circuit_edge_t **edges;
};

circuit_node_t *circuit_node_create(const char *label) {
  circuit_node_t *node = malloc(sizeof(circuit_node_t));
  if (node == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }
  node->potential = INT_MIN;
  node->label = strdup(label);
  if (node->label == NULL) {
    perror("strdup");
    free(node);
    exit(EXIT_FAILURE);
  }
  return node;
}

void circuit_node_destroy(circuit_node_t *node) {
  free(node->label);
  free(node);
}

circuit_edge_t *circuit_edge_create(circuit_node_t *from, circuit_node_t *to, double resistance) {
  circuit_edge_t *edge = malloc(sizeof(circuit_edge_t));
  if (edge == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }
  edge->from = from;
  edge->to = to;
  edge->resistance = resistance;
  return edge;
}

void circuit_edge_destroy(circuit_edge_t *edge) {
  free(edge);
}

circuit_t *circuit_create(size_t num_nodes, size_t num_edges) {
  circuit_t *circuit = malloc(sizeof(circuit_t));
  if (circuit == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }
  circuit->num_nodes = num_nodes;
  circuit->num_edges = num_edges;
  circuit->nodes = malloc(sizeof(circuit_node_t *) * num_nodes);
  if (circuit->nodes == NULL) {
    perror("malloc");
    free(circuit);
    exit(EXIT_FAILURE);
  }
  circuit->edges = malloc(sizeof(circuit_edge_t *) * num_edges);
  if (circuit->edges == NULL) {
    perror("malloc");
    free(circuit->nodes);
    free(circuit);
    exit(EXIT_FAILURE);
  }
  return circuit;
}

void circuit_destroy(circuit_t *circuit) {
  for (size_t i = 0; i < circuit->num_nodes; i++) {
    circuit_node_destroy(circuit->nodes[i]);
  }
  free(circuit->nodes);
  for (size_t i = 0; i < circuit->num_edges; i++) {
    circuit_edge_destroy(circuit->edges[i]);
  }
  free(circuit->edges);
  free(circuit);
}

void circuit_print(circuit_t *circuit) {
  for (size_t i = 0; i < circuit->num_nodes; i++) {
    printf("%s: %d\n", circuit->nodes[i]->label, circuit->nodes[i]->potential);
  }
  for (size_t i = 0; i < circuit->num_edges; i++) {
    printf("%s -- %s: %f\n", circuit->edges[i]->from->label, circuit->edges[i]->to->label, circuit->edges[i]->resistance);
  }
}

int main(int argc, char **argv) {
  // Parse command line arguments
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  const char *input_file = argv[1];
  const char *output_file = argv[2];

  // Read circuit from input file
  FILE *input = fopen(input_file, "r");
  if (input == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }
  size_t num_nodes;
  size_t num_edges;
  fscanf(input, "%zu %zu\n", &num_nodes, &num_edges);
  circuit_t *circuit = circuit_create(num_nodes, num_edges);
  for (size_t i = 0; i < num_nodes; i++) {
    char label[32];
    fscanf(input, "%s\n", label);
    circuit->nodes[i] = circuit_node_create(label);
  }
  for (size_t i = 0; i < num_edges; i++) {
    char from[32];
    char to[32];
    double resistance;
    fscanf(input, "%s %s %lf\n", from, to, &resistance);
    circuit->edges[i] = circuit_edge_create(circuit->nodes[0], circuit->nodes[1], resistance);
  }
  fclose(input);

  // Simulate circuit
  // ...

  // Write circuit to output file
  FILE *output = fopen(output_file, "w");
  if (output == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }
  fprintf(output, "%zu %zu\n", circuit->num_nodes, circuit->num_edges);
  for (size_t i = 0; i < circuit->num_nodes; i++) {
    fprintf(output, "%s: %d\n", circuit->nodes[i]->label, circuit->nodes[i]->potential);
  }
  for (size_t i = 0; i < circuit->num_edges; i++) {
    fprintf(output, "%s -- %s: %f\n", circuit->edges[i]->from->label, circuit->edges[i]->to->label, circuit->edges[i]->resistance);
  }
  fclose(output);

  // Destroy circuit
  circuit_destroy(circuit);

  return EXIT_SUCCESS;
}