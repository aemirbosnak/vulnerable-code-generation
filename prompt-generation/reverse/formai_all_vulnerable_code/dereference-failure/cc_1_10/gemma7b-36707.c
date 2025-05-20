//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: ephemeral
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_VERTICES 10

typedef struct Vertex {
  char name[MAX_VERTICES];
  struct Edge **edges;
  int visited;
} Vertex;

typedef struct Edge {
  Vertex *source;
  Vertex *destination;
  struct Edge *next;
} Edge;

Vertex **graph_create() {
  Vertex **vertices = malloc(MAX_VERTICES * sizeof(Vertex));
  for (int i = 0; i < MAX_VERTICES; i++) {
    vertices[i] = NULL;
  }
  return vertices;
}

void graph_add_vertex(Vertex **vertices, char name) {
  for (int i = 0; i < MAX_VERTICES; i++) {
    if (vertices[i] == NULL) {
      vertices[i] = malloc(sizeof(Vertex));
      vertices[i]->name[0] = name;
      vertices[i]->edges = NULL;
      vertices[i]->visited = 0;
      return;
    }
  }
  printf("Error: Graph is full.\n");
}

void graph_add_edge(Vertex **vertices, char source, char destination) {
  Vertex *source_vertex = NULL;
  Vertex *destination_vertex = NULL;

  for (int i = 0; i < MAX_VERTICES; i++) {
    if (vertices[i] && vertices[i]->name[0] == source) {
      source_vertex = vertices[i];
    }
    if (vertices[i] && vertices[i]->name[0] == destination) {
      destination_vertex = vertices[i];
    }
  }

  if (source_vertex && destination_vertex) {
    Edge **edges = source_vertex->edges;
    Edge *new_edge = malloc(sizeof(Edge));
    new_edge->source = source_vertex;
    new_edge->destination = destination_vertex;
    new_edge->next = edges;
    source_vertex->edges = new_edge;
  } else {
    printf("Error: Vertex not found.\n");
  }
}

void graph_traverse(Vertex **vertices, char name) {
  Vertex *vertex = NULL;
  for (int i = 0; i < MAX_VERTICES; i++) {
    if (vertices[i] && vertices[i]->name[0] == name) {
      vertex = vertices[i];
    }
  }

  if (vertex) {
    vertex->visited = 1;

    printf("%s ", vertex->name);

    Edge **edges = vertex->edges;
    for (Edge *edge = edges; edge; edge = edge->next) {
      if (!edge->destination->visited) {
        graph_traverse(vertices, edge->destination->name);
      }
    }
  } else {
    printf("Error: Vertex not found.\n");
  }
}

int main() {
  Vertex **vertices = graph_create();

  graph_add_vertex(vertices, 'a');
  graph_add_vertex(vertices, 'b');
  graph_add_vertex(vertices, 'c');
  graph_add_vertex(vertices, 'd');

  graph_add_edge(vertices, 'a', 'b');
  graph_add_edge(vertices, 'a', 'c');
  graph_add_edge(vertices, 'b', 'c');
  graph_add_edge(vertices, 'c', 'd');

  graph_traverse(vertices, 'a');

  return 0;
}