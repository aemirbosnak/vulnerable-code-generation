//FormAI DATASET v1.0 Category: Graph representation ; Style: accurate
#include<stdio.h>
#include<stdlib.h>

#define MAX_EDGE 10
#define MAX_VERTEX 9

typedef struct edge {
   int source, dest, weight;
} Edge;

typedef struct graph {
   int V;
   int E;
   Edge* edge[MAX_EDGE];
} Graph;

Graph* createGraph();
void addEdge(Graph*, int, int, int);
void printGraph(Graph*);

int main() {
   Graph* graph = createGraph();
    
   addEdge(graph, 0, 1, 4);
   addEdge(graph, 0, 7, 8);
   addEdge(graph, 1, 2, 8);
   addEdge(graph, 1, 7, 11);
   addEdge(graph, 2, 3, 7);
   addEdge(graph, 2, 8, 2);
   
   printGraph(graph);
   
   return 0;
}

Graph* createGraph() {
   Graph* graph = (Graph*) malloc(sizeof(Graph));
   graph->V = MAX_VERTEX;
   graph->E = 0;
   
   for(int i = 0; i < MAX_EDGE; i++) {
      graph->edge[i] = NULL;
   }
   return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
   Edge* edge = (Edge*) malloc(sizeof(Edge));
   edge->source = src;
   edge->dest = dest;
   edge->weight = weight;
   
   graph->edge[graph->E] = edge;
   graph->E++;
}

void printGraph(Graph* graph) {
   printf("Number of vertices: %d\n", graph->V);
   printf("Number of edges: %d\n", graph->E);
   
   printf("Edges:\n");
   for(int i = 0; i < graph->E; i++) {
      printf("(%d,%d) Weight: %d\n", graph->edge[i]->source, graph->edge[i]->dest, graph->edge[i]->weight);
   }
}