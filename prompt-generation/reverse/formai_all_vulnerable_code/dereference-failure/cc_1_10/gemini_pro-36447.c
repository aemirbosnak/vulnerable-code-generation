//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Graph {
    int numVertices;
    struct Node **adjLists;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int numVertices) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjLists = (struct Node **)malloc(numVertices * sizeof(struct Node *));
    for (int i = 0; i < numVertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest) {
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void printGraph(struct Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node *temp = graph->adjLists[i];
        printf("Adjacency list of vertex %d:\n", i);
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    struct Graph *graph = createGraph(numVertices);
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        printf("Enter the source and destination vertices for edge %d: ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    printGraph(graph);
    return 0;
}