//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct GraphNode {
  int data;
  struct GraphNode* next;
} GraphNode;

typedef struct Graph {
  GraphNode** nodes;
  int size;
} Graph;

Graph* graph_create(int size) {
  Graph* g = malloc(sizeof(Graph));
  g->nodes = malloc(size * sizeof(GraphNode*));
  g->size = size;
  return g;
}

void graph_add_node(Graph* g, int data) {
  GraphNode* node = malloc(sizeof(GraphNode));
  node->data = data;
  node->next = NULL;

  if (g->nodes[0] == NULL) {
    g->nodes[0] = node;
  } else {
    g->nodes[g->size - 1]->next = node;
  }
  g->size++;
}

void graph_print(Graph* g) {
  for (int i = 0; i < g->size; i++) {
    GraphNode* node = g->nodes[i];
    printf("%d ", node->data);
  }
  printf("\n");
}

int main() {
  Graph* g = graph_create(5);
  graph_add_node(g, 10);
  graph_add_node(g, 20);
  graph_add_node(g, 30);
  graph_add_node(g, 40);
  graph_add_node(g, 50);

  graph_print(g);

  return 0;
}