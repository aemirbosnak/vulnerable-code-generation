//FormAI DATASET v1.0 Category: Graph representation ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

// Structure for adjacency list node
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// Structure for adjacency list
struct AdjList {
    struct AdjListNode *head;
};

// Structure for graph
struct Graph {
    int V;
    struct AdjList* array;
};

// Function to create an adjacency list node
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* node = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    node->dest = dest;
    node->next = NULL;
    return node;
}

// Function to create a graph of V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    for(int i = 0; i < V; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// Function to add an edge in an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct AdjListNode* node = newAdjListNode(dest);
    node->next = graph->array[src].head;
    graph->array[src].head = node;

    node = newAdjListNode(src);
    node->next = graph->array[dest].head;
    graph->array[dest].head = node;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for(int i = 0; i < graph->V; i++) {
        struct AdjListNode* temp = graph->array[i].head;
        printf("Adjacency list of vertex %d\nhead", i);
        while(temp != NULL) {
            printf(" -> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);
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