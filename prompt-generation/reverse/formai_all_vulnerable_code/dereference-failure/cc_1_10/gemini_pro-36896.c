//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: visionary
// Embarking on a Graph Odyssey: A Journey to Abstract Connections

#include <stdlib.h>
#include <stdio.h>

// Ascending to the Vertex, a Haven for Nodes and Their Attributes
typedef struct Vertex {
  int value;
  struct Vertex *next;
} Vertex;

// Traversing the Sinuous Labyrinth: Edge, the Pathway of Connections
typedef struct Edge {
  Vertex *src;
  Vertex *dest;
  int weight;
  struct Edge *next;
} Edge;

// Embodying the Graph, a Tapestry of Interwoven Nodes and Connections
typedef struct Graph {
  int num_vertices;
  Vertex **vertices;
  Edge **edges;
} Graph;

// Genesis: Summoning a Graph from the Void
Graph *create_graph(int num_vertices) {
  Graph *graph = (Graph *) malloc(sizeof(Graph));
  graph->num_vertices = num_vertices;

  // Invoking the Vertex Pantheon
  graph->vertices = (Vertex **) malloc(sizeof(Vertex *) * num_vertices);
  for (int i = 0; i < num_vertices; i++) {
    graph->vertices[i] = (Vertex *) malloc(sizeof(Vertex));
    graph->vertices[i]->value = i;
    graph->vertices[i]->next = NULL;
  }

  // Forging the Edge Nexus
  graph->edges = (Edge **) malloc(sizeof(Edge *) * num_vertices * num_vertices);
  for (int i = 0; i < num_vertices; i++) {
    for (int j = 0; j < num_vertices; j++) {
      graph->edges[i * num_vertices + j] = NULL;
    }
  }

  return graph;
}

// A Divine Blessing: Adding an Edge to the Graph's Orchestration
void add_edge(Graph *graph, int src, int dest, int weight) {
  Edge *new_edge = (Edge *) malloc(sizeof(Edge));
  new_edge->src = graph->vertices[src];
  new_edge->dest = graph->vertices[dest];
  new_edge->weight = weight;
  new_edge->next = graph->edges[src * graph->num_vertices + dest];
  graph->edges[src * graph->num_vertices + dest] = new_edge;
}

// Unveiling the Graph's Majestic Design
void print_graph(Graph *graph) {
  printf("Behold, the Graph:\n");
  for (int i = 0; i < graph->num_vertices; i++) {
    Vertex *v = graph->vertices[i];
    printf("Vertex %d: ", i);
    while (v != NULL) {
      printf("%d -> ", v->value);
      v = v->next;
    }
    printf("\n");
  }
}

// Embarking on the Odyssey: A Journey of Discovery
int main() {
  // Enchanting a graph of ten vertices, ready for exploration
  Graph *graph = create_graph(10);

  // Weaving the tapestry of connections
  add_edge(graph, 0, 1, 5);
  add_edge(graph, 0, 2, 3);
  add_edge(graph, 1, 3, 7);
  add_edge(graph, 1, 4, 2);
  add_edge(graph, 2, 4, 1);
  add_edge(graph, 3, 5, 4);
  add_edge(graph, 4, 5, 6);
  add_edge(graph, 5, 6, 9);
  add_edge(graph, 6, 7, 8);
  add_edge(graph, 6, 8, 7);
  add_edge(graph, 7, 8, 2);
  add_edge(graph, 8, 9, 5);

  // Revealing the graph's intricate web
  print_graph(graph);

  return 0;
}