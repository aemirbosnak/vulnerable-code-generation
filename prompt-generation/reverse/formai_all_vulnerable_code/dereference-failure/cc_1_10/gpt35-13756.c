//FormAI DATASET v1.0 Category: Graph representation ; Style: thoughtful
#include <stdio.h>
#define MAX_NODES 100

// Graph representation using adjacency list
struct Graph {
    int V; // number of vertices
    struct node* head[MAX_NODES];
};
 
// Linked list node structure to store adjacent vertices
struct node {
    int dest;
    struct node* next;
};

// Create a new node
struct node* createNode(int dest) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
 
// Add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Create a new node for the destination vertex
    struct node* newNode = createNode(dest);
    // Insert the new node at the beginning of the linked list
    newNode->next = graph->head[src];
    graph->head[src] = newNode;
}

// Print the graph adjacency list
void printGraph(struct Graph* graph) {
    int i;
    for (i = 0; i < graph->V; i++) {
        struct node* temp = graph->head[i];
        printf("\nAdjacency list of vertex %d:\nhead", i);
        while (temp != NULL) {
            printf(" -> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    // Create a graph with 5 vertices
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = 5;
    int i;
    for (i = 0; i < graph->V; i++) {
        graph->head[i] = NULL;
    }
    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    // Print the graph adjacency list
    printGraph(graph);
    return 0;
}