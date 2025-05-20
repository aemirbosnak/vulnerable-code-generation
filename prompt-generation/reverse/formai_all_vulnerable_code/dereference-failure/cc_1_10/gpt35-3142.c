//FormAI DATASET v1.0 Category: Graph representation ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

struct Vertex{
  int value;
  struct Edge *edges;
  int visited;
};

struct Edge{
  struct Vertex *connection;
  struct Edge *next;
};

struct Graph{
  struct Vertex *vertices;
  int num_vertices;
};

void addEdge(struct Graph *g, int vertex1, int vertex2){
  struct Edge *new_edge = (struct Edge*)malloc(sizeof(struct Edge));
  new_edge->connection = &(g->vertices[vertex2]);
  new_edge->next = g->vertices[vertex1].edges;
  g->vertices[vertex1].edges = new_edge;
}

void depthFirstSearch(struct Graph *g, struct Vertex *v){
  v->visited = 1;
  printf("%d ", v->value);
  struct Edge *e = v->edges;
  while(e != NULL){
    if(!e->connection->visited){
      depthFirstSearch(g, e->connection);
    }
    e = e->next;
  }
}

int main(){
  struct Graph g;
  g.num_vertices = 6;
  g.vertices = (struct Vertex*)malloc(g.num_vertices * sizeof(struct Vertex));
  
  for(int i=0; i<g.num_vertices; i++){
    g.vertices[i].value = i;
    g.vertices[i].edges = NULL;
    g.vertices[i].visited = 0;
  }
  
  // Add edges
  addEdge(&g, 0, 1);
  addEdge(&g, 0, 2);
  addEdge(&g, 1, 3);
  addEdge(&g, 1, 4);
  addEdge(&g, 2, 4);
  addEdge(&g, 3, 5);
  addEdge(&g, 4, 5);
  
  // Perform DFS
  depthFirstSearch(&g, &(g.vertices[0]));
  
  return 0;
}