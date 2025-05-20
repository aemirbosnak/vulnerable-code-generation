//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NETS  100

struct node {
  int id;
  char *name;
  int num_inputs;
  int num_outputs;
  int *inputs;
  int *outputs;
};

struct net {
  int id;
  char *name;
  int num_inputs;
  int num_outputs;
  int *inputs;
  int *outputs;
};

struct circuit {
  int num_nodes;
  struct node *nodes;
  int num_nets;
  struct net *nets;
};

struct circuit *new_circuit(void) {
  struct circuit *circuit = malloc(sizeof(struct circuit));
  circuit->num_nodes = 0;
  circuit->nodes = NULL;
  circuit->num_nets = 0;
  circuit->nets = NULL;
  return circuit;
}

void free_circuit(struct circuit *circuit) {
  for (int i = 0; i < circuit->num_nodes; i++) {
    free(circuit->nodes[i].name);
    free(circuit->nodes[i].inputs);
    free(circuit->nodes[i].outputs);
  }
  free(circuit->nodes);
  for (int i = 0; i < circuit->num_nets; i++) {
    free(circuit->nets[i].name);
    free(circuit->nets[i].inputs);
    free(circuit->nets[i].outputs);
  }
  free(circuit->nets);
  free(circuit);
}

struct node *new_node(struct circuit *circuit, char *name, int num_inputs, int num_outputs) {
  struct node *node = malloc(sizeof(struct node));
  node->id = circuit->num_nodes++;
  node->name = strdup(name);
  node->num_inputs = num_inputs;
  node->num_outputs = num_outputs;
  node->inputs = malloc(sizeof(int) * num_inputs);
  node->outputs = malloc(sizeof(int) * num_outputs);
  return node;
}

struct net *new_net(struct circuit *circuit, char *name, int num_inputs, int num_outputs) {
  struct net *net = malloc(sizeof(struct net));
  net->id = circuit->num_nets++;
  net->name = strdup(name);
  net->num_inputs = num_inputs;
  net->num_outputs = num_outputs;
  net->inputs = malloc(sizeof(int) * num_inputs);
  net->outputs = malloc(sizeof(int) * num_outputs);
  return net;
}

void connect_node_to_net(struct circuit *circuit, struct node *node, struct net *net) {
  node->outputs[node->num_outputs++] = net->id;
  net->inputs[net->num_inputs++] = node->id;
}

void simulate_circuit(struct circuit *circuit) {
  for (int i = 0; i < circuit->num_nodes; i++) {
    struct node *node = &circuit->nodes[i];
    for (int j = 0; j < node->num_outputs; j++) {
      struct net *net = &circuit->nets[node->outputs[j]];
      for (int k = 0; k < net->num_outputs; k++) {
        struct node *output_node = &circuit->nodes[net->outputs[k]];
        output_node->inputs[output_node->num_inputs++] = node->id;
      }
    }
  }
}

void print_circuit(struct circuit *circuit) {
  for (int i = 0; i < circuit->num_nodes; i++) {
    struct node *node = &circuit->nodes[i];
    printf("Node %s has %d inputs and %d outputs:\n", node->name, node->num_inputs, node->num_outputs);
    for (int j = 0; j < node->num_inputs; j++) {
      printf("  Input %d: %s\n", j, circuit->nodes[node->inputs[j]].name);
    }
    for (int j = 0; j < node->num_outputs; j++) {
      printf("  Output %d: %s\n", j, circuit->nets[node->outputs[j]].name);
    }
  }
}

int main(void) {
  struct circuit *circuit = new_circuit();

  struct node *node1 = new_node(circuit, "node1", 2, 1);
  struct node *node2 = new_node(circuit, "node2", 1, 2);
  struct node *node3 = new_node(circuit, "node3", 2, 1);

  struct net *net1 = new_net(circuit, "net1", 1, 2);
  struct net *net2 = new_net(circuit, "net2", 2, 1);

  connect_node_to_net(circuit, node1, net1);
  connect_node_to_net(circuit, node2, net1);
  connect_node_to_net(circuit, node3, net1);
  connect_node_to_net(circuit, node2, net2);
  connect_node_to_net(circuit, node3, net2);

  simulate_circuit(circuit);
  print_circuit(circuit);

  free_circuit(circuit);
  return 0;
}