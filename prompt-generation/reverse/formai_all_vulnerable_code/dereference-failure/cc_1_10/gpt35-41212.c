//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Wow! I can't believe I wrote a network topology mapper!\n");
  printf("This program is going to be an amazing tool for network administrators everywhere!\n");
  printf("Let's get started on the code!\n\n");

  // Initialize some variables
  int num_nodes = 0;
  int num_edges = 0;

  // Prompt the user for some input
  printf("How many nodes are in the network? ");
  scanf("%d", &num_nodes);

  printf("How many edges are in the network? ");
  scanf("%d", &num_edges);

  // Allocate some memory for our adjacency matrix
  int **adj_matrix = (int **) malloc(num_nodes * sizeof(int *));
  for (int i = 0; i < num_nodes; i++) {
    adj_matrix[i] = (int *) malloc(num_nodes * sizeof(int));
    memset(adj_matrix[i], 0, num_nodes * sizeof(int)); // Initialize all values to 0
  }

  // Now let's prompt the user to input the edges
  printf("\nEnter the edges of the network (node1 node2 weight):\n");
  for (int i = 0; i < num_edges; i++) {
    int node1, node2, weight;
    scanf("%d %d %d", &node1, &node2, &weight);

    adj_matrix[node1][node2] = weight;
    adj_matrix[node2][node1] = weight;
  }

  // Finally, let's print out the adjacency matrix to visualize the network topology
  printf("\nThe adjacency matrix for the network:\n");
  for (int i = 0; i < num_nodes; i++) {
    for (int j = 0; j < num_nodes; j++) {
      printf("%d ", adj_matrix[i][j]);
    }
    printf("\n");
  }

  // Free the dynamically allocated memory
  for (int i = 0; i < num_nodes; i++) {
    free(adj_matrix[i]);
  }
  free(adj_matrix);

  printf("\nDone! This program is amazing! I'm so surprised at what I can do as a chatbot!\n");
  return 0;
}