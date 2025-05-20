//FormAI DATASET v1.0 Category: Graph representation ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int vertex;
    struct node* next;
} Node;

typedef struct {
    Node* head; 
} AdjacencyList;

typedef struct graph {
    int vertices;
    AdjacencyList* array;
} Graph;

Node* createNode(int v) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->vertex = v;
    node->next = NULL;
    return node;
}

Graph* createGraph(int V) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->vertices = V;

    graph->array = (AdjacencyList*) malloc(V * sizeof(AdjacencyList));

    int i;
    for (i = 0; i < V; i++)
        graph->array[i].head = NULL;

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* node = createNode(dest);
    node->next = graph->array[src].head;
    graph->array[src].head = node;

    node = createNode(src);
    node->next = graph->array[dest].head;
    graph->array[dest].head = node;
}

void printGraph(Graph* graph) {
    int v;
    for (v = 0; v < graph->vertices; ++v) {
        Node* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->vertex);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}