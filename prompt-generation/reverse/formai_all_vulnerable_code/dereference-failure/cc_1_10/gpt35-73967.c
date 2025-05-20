//FormAI DATASET v1.0 Category: Graph representation ; Style: active
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100

struct Vertex {
    int val;
    struct Vertex* next;
};

struct Graph {
    struct Vertex* vertices[MAX_VERTICES];
};

struct Vertex* createVertex(int value) {
    struct Vertex* newVertex = (struct Vertex*)malloc(sizeof(struct Vertex));
    newVertex->val = value;
    newVertex->next = NULL;
    return newVertex;
}

void addEdge(struct Graph* graph, int startVertex, int endVertex) {
    struct Vertex* newVertex = createVertex(endVertex);
    newVertex->next = graph->vertices[startVertex];
    graph->vertices[startVertex] = newVertex;
}

void printGraph(struct Graph* graph) {
    int i;
    for(i=1; i<=MAX_VERTICES; i++) {
        if(graph->vertices[i] != NULL) {
            struct Vertex* temp = graph->vertices[i];
            printf("Vertex %d: ", i);
            while(temp != NULL) {
                printf("%d -> ", temp->val);
                temp = temp->next;
            }
            printf("NULL");
            printf("\n");
        }
    }
}

int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    int i;
    for(i=0; i<=MAX_VERTICES; i++) {
        graph->vertices[i] = NULL;
    }
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    printGraph(graph);
    return 0;
}