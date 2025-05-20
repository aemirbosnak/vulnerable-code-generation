//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTS 10

typedef struct Vertex {
  char name[20];
  int connections[MAX_VERTS];
  struct Vertex* next;
} Vertex;

Vertex* createVertex(char* name) {
  Vertex* vertex = malloc(sizeof(Vertex));
  strcpy(vertex->name, name);
  vertex->next = NULL;
  for (int i = 0; i < MAX_VERTS; i++) {
    vertex->connections[i] = -1;
  }
  return vertex;
}

void addConnection(Vertex* vertex, Vertex* other) {
  for (int i = 0; i < MAX_VERTS; i++) {
    if (vertex->connections[i] == -1) {
      vertex->connections[i] = other;
      break;
    }
  }
}

int main() {
  Vertex* vertexA = createVertex("A");
  Vertex* vertexB = createVertex("B");
  Vertex* vertexC = createVertex("C");
  Vertex* vertexD = createVertex("D");

  addConnection(vertexA, vertexB);
  addConnection(vertexA, vertexC);
  addConnection(vertexB, vertexD);

  printf("Vertex A's connections:");
  for (Vertex* connection = vertexA->connections; connection; connection = connection->next) {
    printf(" - %s", connection->name);
  }

  printf("\n");

  return 0;
}