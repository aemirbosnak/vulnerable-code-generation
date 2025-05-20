//FormAI DATASET v1.0 Category: Graph representation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for representing a node in the graph
struct Node {
    int data;
    int isVisited;
    struct Node* next;
};

// Structure for representing the graph
struct Graph {
    struct Node* vertices[MAX_SIZE];
    int numVertices;
    int directed;
};

// Function to create a new node
struct Node* getNewNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->isVisited = 0;
    newNode->next = NULL;
    return newNode;
}

// Function to add edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = getNewNode(dest);
    newNode->next = graph->vertices[src];
    graph->vertices[src] = newNode;
}

// Function to print graph
void printGraph(struct Graph* graph) {
    struct Node* current;
    for(int i=0; i<graph->numVertices; i++) {
        current = graph->vertices[i];
        printf("Adjacency list of vertex %d\n", i);
        while(current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// Function to DFS traversal of the graph
void DFS(struct Graph* graph, int v) {
    printf("%d ", v);
    graph->vertices[v]->isVisited = 1;
    struct Node* current = graph->vertices[v];
    while(current != NULL) {
        if(!graph->vertices[current->data]->isVisited) {
            DFS(graph, current->data);
        }
        current = current->next;
    }
}

int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = 5;
    graph->directed = 0;

    for(int i=0; i<graph->numVertices; i++) {
        graph->vertices[i] = NULL;
    }

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    printf("DFS traversal: ");
    DFS(graph, 0);
    printf("\n");

    free(graph);

    return 0;
}