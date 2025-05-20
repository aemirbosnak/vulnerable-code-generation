//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTS 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct Graph {
  int numVertices;
  Node** adjList;
} Graph;

Graph* createGraph() {
  Graph* graph = malloc(sizeof(Graph));
  graph->numVertices = 0;
  graph->adjList = NULL;

  return graph;
}

void addVertex(Graph* graph) {
  graph->numVertices++;
  graph->adjList = realloc(graph->adjList, graph->numVertices * sizeof(Node*));

  graph->adjList[graph->numVertices - 1] = NULL;
}

void addEdge(Graph* graph, int src, int dest) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = dest;
  newNode->next = NULL;

  if (graph->adjList[src] == NULL) {
    addVertex(graph);
  }

  graph->adjList[src]->next = newNode;
}

void printGraph(Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    printf("Vertex %d: ", i);
    Node* current = graph->adjList[i];
    while (current) {
      printf("-> Vertex %d ", current->data);
      current = current->next;
    }
    printf("\n");
  }
}

int main() {
  Graph* graph = createGraph();
  addVertex(graph);
  addVertex(graph);
  addEdge(graph, 0, 1);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);

  printGraph(graph);

  return 0;
}