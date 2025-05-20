//FormAI DATASET v1.0 Category: Graph representation ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

struct node {
   int vertex;
   struct node* next;
};

struct Graph {
   int numVertices;
   struct node** adjLists;
};

struct node* createNode(int);

struct Graph* createGraph(int vertices) {
   struct Graph* graph = malloc(sizeof(struct Graph));

   graph->numVertices = vertices;

   graph->adjLists = malloc(vertices * sizeof(struct node*));

   int i;
   for (i = 0; i < vertices; i++)
      graph->adjLists[i] = NULL;

   return graph;
}

void addEdge(struct Graph* graph, int s, int d) {

   struct node* newNode = createNode(d);
   newNode->next = graph->adjLists[s];
   graph->adjLists[s] = newNode;

   newNode = createNode(s);
   newNode->next = graph->adjLists[d];
   graph->adjLists[d] = newNode;
}

struct node* createNode(int v) {
   struct node* newNode = malloc(sizeof(struct node));
   newNode->vertex = v;
   newNode->next = NULL;
   return newNode;
}

void printGraph(struct Graph* graph) {
   int v;
   for (v = 0; v < graph->numVertices; v++) {
      struct node* temp = graph->adjLists[v];
      printf("\n Vertex %d: ", v);
      while (temp) {
         printf("%d -> ", temp->vertex);
         temp = temp->next;
      }
      printf("\n");
   }
}

int main() {
   struct Graph* graph = createGraph(5);
   addEdge(graph, 0, 1);
   addEdge(graph, 0, 4);
   addEdge(graph, 1, 2);
   addEdge(graph, 1, 3);
   addEdge(graph, 1, 4);
   addEdge(graph, 2, 3);
   addEdge(graph, 3, 4);

   printGraph(graph);

   return 0;
}