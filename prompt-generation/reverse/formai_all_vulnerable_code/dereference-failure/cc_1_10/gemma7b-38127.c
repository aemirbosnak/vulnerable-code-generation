//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

typedef struct Node {
  int index;
  struct Node* next;
} Node;

typedef struct Graph {
  Node** graph;
  int numVertices;
  int numEdges;
} Graph;

Graph* createGraph() {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->graph = (Node**)malloc(MAX_VERTICES * sizeof(Node*));
  graph->numVertices = 0;
  graph->numEdges = 0;
  return graph;
}

void addVertex(Graph* graph) {
  graph->numVertices++;
  graph->graph[graph->numVertices - 1] = (Node*)malloc(sizeof(Node));
  graph->graph[graph->numVertices - 1]->index = graph->numVertices - 1;
  graph->graph[graph->numVertices - 1]->next = NULL;
}

void addEdge(Graph* graph, int source, int destination) {
  graph->numEdges++;
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->index = destination;
  newNode->next = NULL;
  graph->graph[source]->next = newNode;
}

void traverseGraph(Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    Node* current = graph->graph[i];
    while (current) {
      printf("Vertex: %d, Edge: %d\n", graph->graph[i]->index, current->index);
      current = current->next;
    }
  }
}

int main() {
  Graph* graph = createGraph();
  addVertex(graph);
  addVertex(graph);
  addEdge(graph, 0, 1);
  addEdge(graph, 1, 2);
  traverseGraph(graph);

  return 0;
}