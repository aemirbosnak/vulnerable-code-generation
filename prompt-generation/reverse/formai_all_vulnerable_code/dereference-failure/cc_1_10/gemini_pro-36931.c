//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COLORS 10
#define MAX_NODES 1000

typedef struct {
  int num_colors;
  int colors[MAX_COLORS];
} color_set_t;

typedef struct {
  int num_nodes;
  int nodes[MAX_NODES];
  int edges[MAX_NODES][MAX_NODES];
} graph_t;

color_set_t* create_color_set(int num_colors) {
  color_set_t* set = malloc(sizeof(color_set_t));
  set->num_colors = num_colors;
  for (int i = 0; i < num_colors; i++) {
    set->colors[i] = i;
  }
  return set;
}

graph_t* create_graph(int num_nodes) {
  graph_t* graph = malloc(sizeof(graph_t));
  graph->num_nodes = num_nodes;
  for (int i = 0; i < num_nodes; i++) {
    graph->nodes[i] = i;
    for (int j = 0; j < num_nodes; j++) {
      graph->edges[i][j] = 0;
    }
  }
  return graph;
}

void add_edge(graph_t* graph, int node1, int node2) {
  graph->edges[node1][node2] = 1;
  graph->edges[node2][node1] = 1;
}

int is_safe(graph_t* graph, color_set_t* set, int node, int color) {
  for (int i = 0; i < graph->num_nodes; i++) {
    if (graph->edges[node][i] == 1 && set->colors[i] == color) {
      return 0;
    }
  }
  return 1;
}

int color_graph(graph_t* graph, color_set_t* set) {
  if (graph->num_nodes == 0) {
    return 1;
  }
  int node = graph->nodes[0];
  for (int i = 0; i < set->num_colors; i++) {
    if (is_safe(graph, set, node, set->colors[i])) {
      set->colors[node] = set->colors[i];
      if (color_graph(graph, set)) {
        return 1;
      }
      set->colors[node] = -1;
    }
  }
  return 0;
}

void print_graph(graph_t* graph) {
  for (int i = 0; i < graph->num_nodes; i++) {
    printf("Node %d: ", graph->nodes[i]);
    for (int j = 0; j < graph->num_nodes; j++) {
      printf("%d ", graph->edges[i][j]);
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));

  int num_nodes = rand() % MAX_NODES + 1;
  int num_colors = rand() % MAX_COLORS + 1;

  graph_t* graph = create_graph(num_nodes);
  color_set_t* set = create_color_set(num_colors);

  for (int i = 0; i < num_nodes; i++) {
    for (int j = i + 1; j < num_nodes; j++) {
      if (rand() % 2 == 0) {
        add_edge(graph, i, j);
      }
    }
  }

  print_graph(graph);

  if (color_graph(graph, set)) {
    printf("Graph colored successfully.\n");
    for (int i = 0; i < graph->num_nodes; i++) {
      printf("Node %d: %d\n", graph->nodes[i], set->colors[i]);
    }
  } else {
    printf("Graph cannot be colored with %d colors.\n", num_colors);
  }

  free(graph);
  free(set);

  return 0;
}