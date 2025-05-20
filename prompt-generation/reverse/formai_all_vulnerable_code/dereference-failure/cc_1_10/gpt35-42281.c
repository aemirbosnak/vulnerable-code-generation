//FormAI DATASET v1.0 Category: Graph representation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int vertices = 0;
int edges = 0;

typedef struct Graph {
  int matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph* createGraph(void) {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  
  for(int i = 0; i < vertices; i++) {
    for(int j = 0; j < vertices; j++) {
      graph->matrix[i][j] = 0;
    }
  }
  
  return graph;
}

void addEdge(Graph* graph, int u, int v) {
  edges++;
  graph->matrix[u][v] = 1;
  graph->matrix[v][u] = 1;
}

void printMatrix(Graph* graph) {
  for(int i = 0; i < vertices; i++) {
    for(int j = 0; j < vertices; j++) {
      printf("%d ", graph->matrix[i][j]);
    }
    
    printf("\n");
  }
}

void printGraphDetails(Graph* graph) {
  printf("Number of vertices in the graph: %d\n", vertices);
  printf("Number of edges in the graph: %d\n", edges);
}

int main(void) {
  int choice, u, v;
  Graph* graph;

  printf("Enter the number of vertices: ");
  scanf("%d", &vertices);

  graph = createGraph();

  while(1) {
    printf("1. Add Edge\n");
    printf("2. Print Graph Matrix\n");
    printf("3. Print Graph Details\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice) {
      case 1:
        printf("Enter edge vertices: ");
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
        break;

      case 2:
        printf("Graph Matrix:\n");
        printMatrix(graph);
        break;

      case 3:
        printGraphDetails(graph);
        break;

      case 4:
        printf("Exiting...\n");
        exit(0);
        break;

      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}