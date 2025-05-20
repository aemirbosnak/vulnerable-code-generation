//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORK_SIZE 100

typedef struct Node {
  int index;
  struct Node* next;
  struct Node* prev;
  char name[MAX_NETWORK_SIZE];
} Node;

typedef struct Network {
  int size;
  struct Node** nodes;
  struct Network* next;
  struct Network* prev;
} Network;

Network* createNetwork() {
  Network* network = (Network*)malloc(sizeof(Network));
  network->size = 0;
  network->nodes = NULL;
  network->next = NULL;
  network->prev = NULL;
  return network;
}

void addNode(Network* network, char* name) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->index = network->size++;
  strcpy(node->name, name);
  node->next = network->nodes;
  network->nodes = node;
}

void mapNetwork(Network* network) {
  for (Node* node = network->nodes; node; node = node->next) {
    printf("%d - %s\n", node->index, node->name);
  }
}

int main() {
  Network* network = createNetwork();
  addNode(network, "John");
  addNode(network, "Mary");
  addNode(network, "Bob");
  mapNetwork(network);

  return 0;
}