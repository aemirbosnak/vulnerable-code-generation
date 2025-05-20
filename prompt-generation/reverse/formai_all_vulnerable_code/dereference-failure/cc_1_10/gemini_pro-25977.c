//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define the data structure for a graph
typedef struct Graph {
  int V;            // Number of vertices
  int E;            // Number of edges
  int **adj;        // Adjacency matrix
  double **weights; // Weight matrix
} Graph;

// Create a new graph with V vertices
Graph *createGraph(int V) {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->V = V;
  graph->E = 0;
  graph->adj = (int **)malloc(V * sizeof(int *));
  graph->weights = (double **)malloc(V * sizeof(double *));
  for (int i = 0; i < V; i++) {
    graph->adj[i] = (int *)malloc(V * sizeof(int));
    graph->weights[i] = (double *)malloc(V * sizeof(double));
    for (int j = 0; j < V; j++) {
      graph->adj[i][j] = 0;
      graph->weights[i][j] = 0.0;
    }
  }
  return graph;
}

// Add an edge to the graph
void addEdge(Graph *graph, int u, int v, double weight) {
  graph->adj[u][v] = 1;
  graph->weights[u][v] = weight;
  graph->E++;
}

// Print the adjacency matrix of the graph
void printAdjMatrix(Graph *graph) {
  for (int i = 0; i < graph->V; i++) {
    for (int j = 0; j < graph->V; j++) {
      printf("%d ", graph->adj[i][j]);
    }
    printf("\n");
  }
}

// Print the weight matrix of the graph
void printWeightMatrix(Graph *graph) {
  for (int i = 0; i < graph->V; i++) {
    for (int j = 0; j < graph->V; j++) {
      printf("%.2f ", graph->weights[i][j]);
    }
    printf("\n");
  }
}

// Generate a random graph with V vertices and E edges
Graph *generateRandomGraph(int V, int E) {
  Graph *graph = createGraph(V);
  srand(time(NULL));
  for (int i = 0; i < E; i++) {
    int u = rand() % V;
    int v = rand() % V;
    double weight = (double)(rand() % 100) / 100.0;
    addEdge(graph, u, v, weight);
  }
  return graph;
}

// Compute the mean edge weight of the graph
double computeMeanEdgeWeight(Graph *graph) {
  double sum = 0.0;
  for (int i = 0; i < graph->V; i++) {
    for (int j = 0; j < graph->V; j++) {
      sum += graph->weights[i][j];
    }
  }
  return sum / graph->E;
}

// Compute the standard deviation of the edge weights of the graph
double computeStdDevEdgeWeight(Graph *graph) {
  double mean = computeMeanEdgeWeight(graph);
  double sum = 0.0;
  for (int i = 0; i < graph->V; i++) {
    for (int j = 0; j < graph->V; j++) {
      sum += pow(graph->weights[i][j] - mean, 2.0);
    }
  }
  return sqrt(sum / graph->E);
}

// Print the statistical summary of the graph
void printGraphSummary(Graph *graph) {
  printf("Number of vertices: %d\n", graph->V);
  printf("Number of edges: %d\n", graph->E);
  printf("Mean edge weight: %.2f\n", computeMeanEdgeWeight(graph));
  printf("Standard deviation of edge weights: %.2f\n", computeStdDevEdgeWeight(graph));
}

// Free the memory allocated for the graph
void freeGraph(Graph *graph) {
  for (int i = 0; i < graph->V; i++) {
    free(graph->adj[i]);
    free(graph->weights[i]);
  }
  free(graph->adj);
  free(graph->weights);
  free(graph);
}

int main() {
  // Create a random graph with 10 vertices and 20 edges
  Graph *graph = generateRandomGraph(10, 20);

  // Print the adjacency matrix of the graph
  printf("Adjacency matrix:\n");
  printAdjMatrix(graph);

  // Print the weight matrix of the graph
  printf("Weight matrix:\n");
  printWeightMatrix(graph);

  // Print the statistical summary of the graph
  printf("Graph summary:\n");
  printGraphSummary(graph);

  // Free the memory allocated for the graph
  freeGraph(graph);

  return 0;
}