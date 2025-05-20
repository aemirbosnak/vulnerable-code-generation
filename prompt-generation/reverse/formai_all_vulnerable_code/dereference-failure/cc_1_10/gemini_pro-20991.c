//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

// Structure to store the network topology
typedef struct {
  int num_nodes;
  int **edges;
} NetworkTopology;

// Function to create a new network topology
NetworkTopology *create_network_topology(int num_nodes) {
  NetworkTopology *topology = malloc(sizeof(NetworkTopology));
  topology->num_nodes = num_nodes;
  topology->edges = malloc(sizeof(int *) * num_nodes);
  for (int i = 0; i < num_nodes; i++) {
    topology->edges[i] = malloc(sizeof(int) * num_nodes);
    for (int j = 0; j < num_nodes; j++) {
      topology->edges[i][j] = 0;
    }
  }
  return topology;
}

// Function to destroy a network topology
void destroy_network_topology(NetworkTopology *topology) {
  for (int i = 0; i < topology->num_nodes; i++) {
    free(topology->edges[i]);
  }
  free(topology->edges);
  free(topology);
}

// Function to add an edge to a network topology
void add_edge(NetworkTopology *topology, int node1, int node2) {
  if (node1 < 0 || node1 >= topology->num_nodes ||
      node2 < 0 || node2 >= topology->num_nodes) {
    printf("Invalid node numbers.\n");
    return;
  }
  topology->edges[node1][node2] = 1;
  topology->edges[node2][node1] = 1;
}

// Function to print a network topology
void print_network_topology(NetworkTopology *topology) {
  printf("Network Topology:\n");
  for (int i = 0; i < topology->num_nodes; i++) {
    for (int j = 0; j < topology->num_nodes; j++) {
      printf("%d ", topology->edges[i][j]);
    }
    printf("\n");
  }
}

// Function to generate a random network topology
NetworkTopology *generate_random_network_topology(int num_nodes, int num_edges) {
  NetworkTopology *topology = create_network_topology(num_nodes);
  while (num_edges > 0) {
    int node1 = rand() % num_nodes;
    int node2 = rand() % num_nodes;
    if (node1 != node2 && topology->edges[node1][node2] == 0) {
      add_edge(topology, node1, node2);
      num_edges--;
    }
  }
  return topology;
}

// Main function
int main() {
  // Create a random network topology with 10 nodes and 20 edges
  NetworkTopology *topology = generate_random_network_topology(10, 20);

  // Print the network topology
  print_network_topology(topology);

  // Destroy the network topology
  destroy_network_topology(topology);

  return 0;
}