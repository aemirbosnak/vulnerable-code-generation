//FormAI DATASET v1.0 Category: Graph representation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

struct Graph {
   int V; // Number of vertices
   int E; // Number of edges
   int **adjMatrix; // Adjacency matrix
};

struct Graph* createGraph(int numVertices) {
   struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
   graph -> V = numVertices;
   graph -> E = 0;
   graph -> adjMatrix = (int **) malloc(numVertices * sizeof(int*));
   for (int i = 0; i < numVertices; i++) {
      graph -> adjMatrix[i] = (int *) malloc(numVertices * sizeof(int));
      for (int j = 0; j < numVertices; j++)
         graph -> adjMatrix[i][j] = 0;
   }
   return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
   graph -> adjMatrix[src][dest] = 1;
   graph -> adjMatrix[dest][src] = 1;
   graph -> E++;
}

void printGraph(struct Graph* graph) {
   printf("\nGraph:\n\n");
   for (int i = 0; i < graph -> V; i++) {
      for (int j = 0; j < graph -> V; j++)
         printf("%d ", graph -> adjMatrix[i][j]);
      printf("\n");
   }
}

int main() {
   int V = 5; // Number of vertices
   struct Graph* graph = createGraph(V);
   addEdge(graph, 0, 1);
   addEdge(graph, 0, 4);
   addEdge(graph, 1, 2);
   addEdge(graph, 1, 3);
   addEdge(graph, 1, 4);
   addEdge(graph, 2, 3);
   addEdge(graph, 3, 4);
   printGraph(graph);
   return 0;
}