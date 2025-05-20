//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* adjList[MAX_VERTICES];
    int numVertices;
} Graph;

// Ponderous incantation: create upheaval in the graph's realm
Graph* conjureGraph(int vertices) {
    Graph* eldritchGraph = malloc(sizeof(Graph));
    eldritchGraph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        eldritchGraph->adjList[i] = NULL;
    }
    return eldritchGraph;
}

// Arcane articulation: conjure edges between the unseen realms
void appendEdge(Graph* g, int src, int dest) {
    Node* temp = malloc(sizeof(Node));
    temp->vertex = dest;
    temp->next = g->adjList[src];
    g->adjList[src] = temp;
}

// Whispering shadows: unveil the graph's hidden structure
void unveilGraph(Graph* g) {
    for (int v = 0; v < g->numVertices; v++) {
        Node* temp = g->adjList[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf(" -> NULL\n");
    }
}

// Hallowed traversal: downward into the abyss using DFS
void abyssDive(Graph* g, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("Visited: %d\n", vertex);
    
    Node* temp = g->adjList[vertex];
    while (temp) {
        int connectedVertex = temp->vertex;
        if (!visited[connectedVertex]) {
            abyssDive(g, connectedVertex, visited);
        }
        temp = temp->next;
    }
}

// Illusory beginnings: engage the spectral forces of the main function
int main() {
    // The ever-expanding multiverse of vertices
    int numVertices = 5;
    Graph* myGraph = conjureGraph(numVertices);

    // Connections forged in silence
    appendEdge(myGraph, 0, 1);
    appendEdge(myGraph, 0, 4);
    appendEdge(myGraph, 1, 2);
    appendEdge(myGraph, 1, 3);
    appendEdge(myGraph, 1, 4);
    appendEdge(myGraph, 2, 3);
    appendEdge(myGraph, 3, 4);
    
    // Reveal the unseen connections
    unveilGraph(myGraph);

    // An invitation to the abyss awaits
    int visited[MAX_VERTICES] = {0};
    printf("Diving deep into the abyss...\n");
    abyssDive(myGraph, 0, visited);

    // Release your hold on the conjured graph
    for (int i = 0; i < numVertices; i++) {
        Node* temp = myGraph->adjList[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(myGraph);
    return 0;
}