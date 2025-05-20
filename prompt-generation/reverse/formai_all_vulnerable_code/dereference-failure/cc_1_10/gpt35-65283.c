//FormAI DATASET v1.0 Category: Graph representation ; Style: innovative
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void addEdge(struct Node* array[], int source, int destination) {
    // Adding edge between the given source and destination vertices
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = destination;
    newNode->next = array[source];
    array[source] = newNode;
}

void printGraph(struct Node* array[], int vertices) {
    // Printing the graph
    printf("Graph Representation using Linked List:\n");
    for(int i = 0; i < vertices; i++) {
        printf("Vertex [%d] -->", i);
        struct Node* temp = array[i];
        while(temp != NULL) {
            printf(" %d ->", temp->data);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}

int main() {
    // Creating Graph vertices and edges using Linked List
    int vertices, edges;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);
    struct Node* array[vertices];
    for(int i = 0; i < vertices; i++) {
        array[i] = NULL;
    }
    int source, destination;
    for(int i = 0; i < edges; i++) {
        printf("Enter source and destination vertices of edge [%d]: ", i);
        scanf("%d%d", &source, &destination);
        addEdge(array, source, destination);
    }
    printGraph(array, vertices);
    return 0;
}