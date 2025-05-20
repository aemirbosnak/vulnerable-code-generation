//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void greedy_algorithm(int **graph, int numVertices) {
  int i, j, k, minDistance, currentDistance, bestVertex, currentVertexIndex;
  int *distance = (int *)malloc(numVertices * sizeof(int));
  distance[0] = 0;
  for (i = 1; i < numVertices; i++) {
    distance[i] = MAX;
  }
  distance[0] = 0;
  for (i = 0; i < numVertices; i++) {
    currentDistance = distance[i] + 1;
    for (j = 0; j < numVertices; j++) {
      if (graph[i][j] && currentDistance < distance[j]) {
        distance[j] = currentDistance;
        bestVertex = j;
        currentVertexIndex = i;
      }
    }
  }
  printf("The shortest path is: ");
  for (i = currentVertexIndex; i != 0; i = graph[i][bestVertex]) {
    printf("%d ", bestVertex);
  }
  printf("%d ", currentVertexIndex);
  printf("\n");
  free(distance);
}

int main() {
  int numVertices, numEdges;
  int **graph;
  printf("Enter the number of vertices: ");
  scanf("%d", &numVertices);
  printf("Enter the number of edges: ");
  scanf("%d", &numEdges);

  graph = (int **)malloc(numVertices * sizeof(int *));
  for (int i = 0; i < numVertices; i++) {
    graph[i] = (int *)malloc(numVertices * sizeof(int));
  }

  for (int i = 0; i < numVertices; i++) {
    for (int j = 0; j < numVertices; j++) {
      graph[i][j] = 0;
    }
  }

  for (int i = 0; i < numEdges; i++) {
    int u, v, w;
    printf("Enter the source vertex: ");
    scanf("%d", &u);
    printf("Enter the destination vertex: ");
    scanf("%d", &v);
    printf("Enter the weight of the edge: ");
    scanf("%d", &w);
    graph[u][v] = w;
  }

  greedy_algorithm(graph, numVertices);

  return 0;
}