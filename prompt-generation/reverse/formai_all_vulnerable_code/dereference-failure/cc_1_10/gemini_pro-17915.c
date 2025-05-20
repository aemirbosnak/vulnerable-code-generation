//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_COLORS 10
#define MAX_NODES 100

typedef struct Graph {
  int num_nodes;
  int num_edges;
  int** adjacency_matrix;
} Graph;

typedef struct Node {
  int color;
  bool visited;
} Node;

Graph* create_graph(int num_nodes, int num_edges) {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->num_nodes = num_nodes;
  graph->num_edges = num_edges;
  graph->adjacency_matrix = (int**)malloc(num_nodes * sizeof(int*));
  for (int i = 0; i < num_nodes; i++) {
    graph->adjacency_matrix[i] = (int*)malloc(num_nodes * sizeof(int));
    for (int j = 0; j < num_nodes; j++) {
      graph->adjacency_matrix[i][j] = 0;
    }
  }
  return graph;
}

void add_edge(Graph* graph, int node1, int node2) {
  graph->adjacency_matrix[node1][node2] = 1;
  graph->adjacency_matrix[node2][node1] = 1;
}

void print_graph(Graph* graph) {
  for (int i = 0; i < graph->num_nodes; i++) {
    for (int j = 0; j < graph->num_nodes; j++) {
      printf("%d ", graph->adjacency_matrix[i][j]);
    }
    printf("\n");
  }
}

bool is_valid_coloring(Graph* graph, Node* nodes, int num_colors) {
  for (int i = 0; i < graph->num_nodes; i++) {
    for (int j = i + 1; j < graph->num_nodes; j++) {
      if (graph->adjacency_matrix[i][j] == 1 && nodes[i].color == nodes[j].color) {
        return false;
      }
    }
  }
  return true;
}

bool graph_coloring(Graph* graph, Node* nodes, int num_colors, int current_color) {
  if (current_color == num_colors) {
    return is_valid_coloring(graph, nodes, num_colors);
  }

  for (int i = 0; i < graph->num_nodes; i++) {
    if (!nodes[i].visited) {
      nodes[i].visited = true;
      nodes[i].color = current_color;
      if (graph_coloring(graph, nodes, num_colors, current_color + 1)) {
        return true;
      }
      nodes[i].visited = false;
    }
  }
  return false;
}

int main() {
  int num_nodes, num_edges;
  scanf("%d %d", &num_nodes, &num_edges);

  Graph* graph = create_graph(num_nodes, num_edges);

  for (int i = 0; i < num_edges; i++) {
    int node1, node2;
    scanf("%d %d", &node1, &node2);
    add_edge(graph, node1, node2);
  }

  Node* nodes = (Node*)malloc(num_nodes * sizeof(Node));

  for (int i = 0; i < num_nodes; i++) {
    nodes[i].visited = false;
    nodes[i].color = 0;
  }

  int num_colors;
  scanf("%d", &num_colors);

  if (graph_coloring(graph, nodes, num_colors, 1)) {
    printf("Graph is colorable with %d colors:\n", num_colors);
    for (int i = 0; i < num_nodes; i++) {
      printf("Node %d: Color %d\n", i, nodes[i].color);
    }
  } else {
    printf("Graph is not colorable with %d colors.\n", num_colors);
  }

  return 0;
}