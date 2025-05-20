//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NODES 10  // maximum number of nodes in the graph

// Define the node struct
typedef struct node {
  int id;
  struct node* next;
} Node;

// Define the graph struct
typedef struct graph {
  Node* nodes[MAX_NODES];
} Graph;

// Function to add a new node to the graph
void addNode(Graph* G, int n) {
  Node* newNode = malloc(sizeof(Node));
  newNode->id = n;
  newNode->next = NULL;

  G->nodes[n] = newNode;
}

// Function to add a new edge to the graph
void addEdge(Graph* G, int n1, int n2) {
  Node* curr = G->nodes[n1];

  while (curr->next != NULL) {
    curr = curr->next;
  }

  Node* newNode = malloc(sizeof(Node));
  newNode->id = n2;
  newNode->next = NULL;

  curr->next = newNode;
}

// Function to print the graph as a visual representation
void printGraph(Graph* G) {
  printf("\n");

  for (int i = 0; i < MAX_NODES; i++) {
    printf("%d: ", i);

    if (G->nodes[i] != NULL) {
      Node* curr = G->nodes[i]->next;

      while (curr != NULL) {
        printf("%d ", curr->id);
        curr = curr->next;
      }
    }

    printf("\n");
  }
}

int main() {
  Graph G;
  srand(time(NULL));

  // Add nodes to the graph
  for (int i = 0; i < MAX_NODES; i++) {
    addNode(&G, i);
  }

  // Add edges to the graph
  for (int i = 0; i < MAX_NODES; i++) {
    for (int j = 0; j < MAX_NODES; j++) {
      if (i != j) {
        int randNum = rand() % 3;

        if (randNum == 1) {
          addEdge(&G, i, j);
        }
      }
    }
  }

  // Print the graph as a visual representation
  printGraph(&G);

  return 0;
}