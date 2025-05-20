//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct GraphNode {
  struct GraphNode* next;
  char* name;
  int value;
} GraphNode;

typedef struct Graph {
  GraphNode** nodes;
  int numNodes;
} Graph;

Graph* graphCreate(int numNodes) {
  Graph* graph = malloc(sizeof(Graph));
  graph->nodes = malloc(numNodes * sizeof(GraphNode*));
  graph->numNodes = numNodes;
  return graph;
}

void graphAddNode(Graph* graph, char* name, int value) {
  GraphNode* newNode = malloc(sizeof(GraphNode));
  newNode->name = strdup(name);
  newNode->value = value;
  newNode->next = NULL;

  if (graph->nodes[graph->numNodes - 1] != NULL) {
    graph->nodes[graph->numNodes - 1]->next = newNode;
  } else {
    graph->nodes[graph->numNodes - 1] = newNode;
  }

  graph->numNodes++;
}

void graphPrint(Graph* graph) {
  for (int i = 0; i < graph->numNodes; i++) {
    GraphNode* node = graph->nodes[i];
    printf("%s (value: %d) ", node->name, node->value);
  }
  printf("\n");
}

int main() {
  Graph* graph = graphCreate(5);
  graphAddNode(graph, "A", 10);
  graphAddNode(graph, "B", 20);
  graphAddNode(graph, "C", 30);
  graphAddNode(graph, "D", 40);
  graphAddNode(graph, "E", 50);

  graphPrint(graph);

  return 0;
}