//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph
typedef struct Graph {
  int V;  // Number of vertices
  int E;  // Number of edges
  int **adj;  // Adjacency matrix
} Graph;

// Function to create a new graph
Graph *createGraph(int V, int E) {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->V = V;
  graph->E = E;
  graph->adj = (int **)malloc(V * sizeof(int *));
  for (int i = 0; i < V; i++) {
    graph->adj[i] = (int *)malloc(V * sizeof(int));
    for (int j = 0; j < V; j++) { graph->adj[i][j] = 0; }
  }
  return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int u, int v) { graph->adj[u][v] = 1; }

// Function to print the graph
void printGraph(Graph *graph) {
  for (int i = 0; i < graph->V; i++) {
    for (int j = 0; j < graph->V; j++) { printf("%d ", graph->adj[i][j]); }
    printf("\n");
  }
}

// Function to check if the graph is bipartite
int isBipartite(Graph *graph) {
  // Create a color array to store the colors assigned to each vertex
  int *color = (int *)malloc(graph->V * sizeof(int));
  for (int i = 0; i < graph->V; i++) { color[i] = -1; }

  // Initialize a queue to store the vertices
  int queue[graph->V];
  int front = 0, rear = 0;
  queue[rear++] = 0;  // Add the first vertex to the queue

  // Assign color to the first vertex
  color[0] = 0;

  // While the queue is not empty
  while (front != rear) {
    // Dequeue a vertex from the queue
    int u = queue[front++];

    // Iterate over all the adjacent vertices of the dequeued vertex
    for (int v = 0; v < graph->V; v++) {
      // If the adjacent vertex is not visited
      if (graph->adj[u][v] && color[v] == -1) {
        // Assign a color to the adjacent vertex
        color[v] = 1 - color[u];

        // Add the adjacent vertex to the queue
        queue[rear++] = v;
      }

      // If the adjacent vertex is already visited and has the same color
      // as the current vertex
      else if (graph->adj[u][v] && color[v] == color[u]) { return 0; }
    }
  }

  // If all the vertices are colored and there is no conflict
  return 1;
}

// Driver code to test the above functions
int main() {
  // Create a graph
  Graph *graph = createGraph(4, 4);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);

  // Print the graph
  printf("Graph:\n");
  printGraph(graph);

  // Check if the graph is bipartite
  int result = isBipartite(graph);
  if (result)
    printf("The graph is bipartite\n");
  else
    printf("The graph is not bipartite\n");

  return 0;
}