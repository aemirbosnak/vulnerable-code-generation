//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: curious
#include <stdio.h>

#define GRAPH_SIZE 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct Graph {
  Node** adjacencyList;
  int numVertices;
} Graph;

Graph* createGraph() {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->adjacencyList = (Node**)malloc(GRAPH_SIZE * sizeof(Node*));
  graph->numVertices = 0;
  return graph;
}

void addVertex(Graph* graph, int data) {
  graph->numVertices++;
  graph->adjacencyList[data] = (Node*)malloc(sizeof(Node));
  graph->adjacencyList[data]->data = data;
  graph->adjacencyList[data]->next = NULL;
}

void addEdge(Graph* graph, int src, int dest) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = dest;
  newNode->next = NULL;
  graph->adjacencyList[src]->next = newNode;
}

void traverseGraph(Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    Node* current = graph->adjacencyList[i];
    while (current) {
      printf("(%d, %d)\n", i, current->data);
      current = current->next;
    }
  }
}

int main() {
  Graph* graph = createGraph();
  addVertex(graph, 0);
  addVertex(graph, 1);
  addVertex(graph, 2);
  addEdge(graph, 0, 1);
  addEdge(graph, 1, 2);
  traverseGraph(graph);
  return 0;
}