//FormAI DATASET v1.0 Category: Graph representation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node* Graph;

Graph createGraph(int numVertices) {
    Graph graph = (Graph)malloc(numVertices * sizeof(struct Node));
    for(int i = 0; i < numVertices; i++) {
        graph[i].data = i+1;
        graph[i].next = NULL;
    }
    return graph;
}

void addEdge(Graph graph, int source, int destination) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = destination;
    newNode->next = graph[source-1].next;
    graph[source-1].next = newNode;    
}

void printGraph(Graph graph, int numVertices) {
    for(int i = 0; i < numVertices; i++) {
        printf("\nVertex %d: ", i+1);
        struct Node* edge = graph[i].next;
        while(edge != NULL) {
            printf("%d -> ", edge->data);
            edge = edge->next;
        }
        printf("NULL");
    }
}

int main() {
    int numVertices = 5;
    Graph graph = createGraph(numVertices);
    
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    
    printGraph(graph, numVertices);
    
    return 0;
}