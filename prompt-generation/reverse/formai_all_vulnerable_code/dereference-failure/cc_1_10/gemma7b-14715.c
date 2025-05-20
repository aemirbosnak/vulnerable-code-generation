//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
  int src, dst;
  struct Edge* next;
} Edge;

typedef struct Node {
  int data;
  struct Node* next;
  Edge* edges;
} Node;

Node* newNode(int data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  node->edges = NULL;
  return node;
}

Edge* newEdge(int src, int dst) {
  Edge* edge = (Edge*)malloc(sizeof(Edge));
  edge->src = src;
  edge->dst = dst;
  edge->next = NULL;
  return edge;
}

void addEdge(Node* node, Edge* edge) {
  edge->next = node->edges;
  node->edges = edge;
}

void traverseGraph(Node* node) {
  printf("%d ", node->data);
  for (Edge* edge = node->edges; edge; edge = edge->next) {
    traverseGraph(newNode(edge->dst));
  }
}

int main() {
  Node* root = newNode(0);
  addEdge(root, newEdge(1, 2));
  addEdge(root, newEdge(1, 3));
  addEdge(root, newEdge(2, 4));
  addEdge(root, newEdge(3, 5));

  traverseGraph(root);

  return 0;
}