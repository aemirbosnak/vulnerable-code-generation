//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NODES 1000

typedef struct node {
  int id;
  int degree;
  int *neighbors;
} Node;

typedef struct network {
  int num_nodes;
  Node nodes[MAX_NODES];
} Network;

void add_edge(Network *network, int node1, int node2) {
  network->nodes[node1].neighbors = (int *) realloc(network->nodes[node1].neighbors, (network->nodes[node1].degree+1)*sizeof(int));
  network->nodes[node1].neighbors[network->nodes[node1].degree] = node2;
  network->nodes[node1].degree++;
  
  network->nodes[node2].neighbors = (int *) realloc(network->nodes[node2].neighbors, (network->nodes[node2].degree+1)*sizeof(int));
  network->nodes[node2].neighbors[network->nodes[node2].degree] = node1;
  network->nodes[node2].degree++;
}

void print_network(Network network) {
  for (int i = 0; i < network.num_nodes; i++) {
    printf("Node %d:\n", i);
    printf("\tDegree: %d\n", network.nodes[i].degree);
    printf("\tNeighbors: ");
    for (int j = 0; j < network.nodes[i].degree; j++) {
      printf("%d ", network.nodes[i].neighbors[j]);
    }
    printf("\n");
  }
}

int main() {
  Network network;
  network.num_nodes = 5;
  
  for (int i = 0; i < network.num_nodes; i++) {
    network.nodes[i].id = i;
    network.nodes[i].degree = 0;
    network.nodes[i].neighbors = NULL;
  }
  
  add_edge(&network, 0, 1);
  add_edge(&network, 0, 3);
  add_edge(&network, 1, 2);
  add_edge(&network, 2, 3);
  add_edge(&network, 2, 4);
  
  print_network(network);
  
  return 0;
}