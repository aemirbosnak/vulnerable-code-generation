//FormAI DATASET v1.0 Category: Graph representation ; Style: brave
#include<stdio.h>
#include<stdlib.h>

/* Definition of linked list node */
typedef struct GraphNode {
    int vertex;
    struct GraphNode* next;
}GraphNode;

/* Create a graph of n vertices */
GraphNode** createGraph(int n) {
    GraphNode** graph = (GraphNode**)malloc(n*sizeof(GraphNode*));
    int i;
    for(i=0;i<n;i++) {
        graph[i] = NULL;
    }
    return graph;
}

/* Function to add an edge to an undirected graph */
void addEdge(GraphNode** graph, int src, int dest) {
    GraphNode* newNode = (GraphNode*)malloc(sizeof(GraphNode));
    newNode->vertex = dest;
    newNode->next = graph[src];
    graph[src] = newNode;

    newNode = (GraphNode*)malloc(sizeof(GraphNode));
    newNode->vertex = src;
    newNode->next = graph[dest];
    graph[dest] = newNode;
}

/* Function to print the created graph */
void printGraph(GraphNode** graph, int n) {
    int i;
    for(i=0;i<n;i++) {
        GraphNode* current = graph[i];
        printf("Vertex %d: ", i);
        while(current != NULL) {
            printf("%d -> ", current->vertex);
            current = current->next;
        }
        printf("NULL\n");
    }
}

/* Driver program */
int main() {
    int n = 5;
    GraphNode** graph = createGraph(n);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3); 
    addEdge(graph, 1, 4); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 4);

    printf("Graph representation:\n");
    printGraph(graph, n);

    return 0;
}