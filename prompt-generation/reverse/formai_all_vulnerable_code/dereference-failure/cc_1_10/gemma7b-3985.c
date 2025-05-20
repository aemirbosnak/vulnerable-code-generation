//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_NETWORK_SIZE 100

typedef struct Node {
  int index;
  struct Node* next;
} Node;

void createNetwork(Node**, int*);

void printNetwork(Node*);

int main() {
  Node* network = NULL;
  int numNodes = 0;

  createNetwork(&network, &numNodes);
  printNetwork(network);

  return 0;
}

void createNetwork(Node** network, int* numNodes) {
  *network = NULL;
  *numNodes = 0;

  printf("Enter the number of nodes: ");
  scanf("%d", numNodes);

  for (int i = 0; i < *numNodes; i++) {
    *network = malloc(sizeof(Node));
    (*network)->index = i;
    (*network)->next = NULL;
    *network = (*network)->next;
  }
}

void printNetwork(Node* network) {
  printf("Network topology:\n");

  while (network) {
    printf("Node %d is connected to:", network->index);

    if (network->next) {
      printf(" Node %d", network->next->index);
    } else {
      printf(" No other nodes");
    }

    printf("\n");
    network = network->next;
  }
}