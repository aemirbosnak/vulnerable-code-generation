//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 10
#define MAX_NODES 100

typedef struct node {
  int id;
  int color;
  struct node *next;
} node;

typedef struct graph {
  int num_nodes;
  int num_edges;
  node *nodes;
} graph;

graph *create_graph(int num_nodes, int num_edges) {
  graph *g = (graph *)malloc(sizeof(graph));
  g->num_nodes = num_nodes;
  g->num_edges = num_edges;
  g->nodes = (node *)malloc(sizeof(node) * num_nodes);
  for (int i = 0; i < num_nodes; i++) {
    g->nodes[i].id = i;
    g->nodes[i].color = -1;
    g->nodes[i].next = NULL;
  }
  return g;
}

void add_edge(graph *g, int u, int v) {
  node *u_node = &g->nodes[u];
  node *v_node = &g->nodes[v];
  node *new_node = (node *)malloc(sizeof(node));
  new_node->id = v;
  new_node->color = -1;
  new_node->next = NULL;
  if (u_node->next == NULL) {
    u_node->next = new_node;
  } else {
    node *curr = u_node->next;
    while (curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = new_node;
  }
  if (v_node->next == NULL) {
    v_node->next = new_node;
  } else {
    node *curr = v_node->next;
    while (curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = new_node;
  }
}

int is_safe(graph *g, int node_id, int color) {
  node *curr = g->nodes[node_id].next;
  while (curr != NULL) {
    if (g->nodes[curr->id].color == color) {
      return 0;
    }
    curr = curr->next;
  }
  return 1;
}

int graph_coloring(graph *g, int k) {
  int i, j;
  for (i = 0; i < g->num_nodes; i++) {
    for (j = 0; j < k; j++) {
      if (is_safe(g, i, j)) {
        g->nodes[i].color = j;
        if (graph_coloring(g, k) == 1) {
          return 1;
        }
        g->nodes[i].color = -1;
      }
    }
  }
  return 0;
}

int main() {
  int num_nodes, num_edges, k;
  printf("Enter the number of nodes: ");
  scanf("%d", &num_nodes);
  printf("Enter the number of edges: ");
  scanf("%d", &num_edges);
  printf("Enter the number of colors: ");
  scanf("%d", &k);
  graph *g = create_graph(num_nodes, num_edges);
  for (int i = 0; i < num_edges; i++) {
    int u, v;
    printf("Enter the edges (u, v): ");
    scanf("%d %d", &u, &v);
    add_edge(g, u, v);
  }
  if (graph_coloring(g, k) == 1) {
    printf("The graph is colorable with %d colors.\n", k);
    for (int i = 0; i < num_nodes; i++) {
      printf("Node %d is colored %d.\n", g->nodes[i].id, g->nodes[i].color);
    }
  } else {
    printf("The graph is not colorable with %d colors.\n", k);
  }
  return 0;
}