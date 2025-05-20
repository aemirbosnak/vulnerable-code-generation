//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

void initializeGraph(Graph* graph, int vertices) {
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* graph, int startVertex, int endVertex) {
    graph->adjacencyMatrix[startVertex][endVertex] = 1;
    graph->adjacencyMatrix[endVertex][startVertex] = 1; // For undirected graph
}

void removeEdge(Graph* graph, int startVertex, int endVertex) {
    graph->adjacencyMatrix[startVertex][endVertex] = 0;
    graph->adjacencyMatrix[endVertex][startVertex] = 0; // For undirected graph
}

void displayGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjacencyMatrix[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph graph;
    int numVertices, choice, startVertex, endVertex;

    printf("Enter the number of vertices in the graph (max %d): ", MAX_VERTICES);
    scanf("%d", &numVertices);
    if (numVertices > MAX_VERTICES) {
        printf("Too many vertices! Max allowed is %d.\n", MAX_VERTICES);
        return 1;
    }

    initializeGraph(&graph, numVertices);
    
    while (1) {
        printf("\nGraph Menu:\n");
        printf("1. Add Edge\n");
        printf("2. Remove Edge\n");
        printf("3. Display Graph\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter start vertex and end vertex: ");
                scanf("%d %d", &startVertex, &endVertex);
                if (startVertex < numVertices && endVertex < numVertices) {
                    addEdge(&graph, startVertex, endVertex);
                    printf("Edge added between %d and %d.\n", startVertex, endVertex);
                } else {
                    printf("Invalid vertex numbers!\n");
                }
                break;
            case 2:
                printf("Enter start vertex and end vertex: ");
                scanf("%d %d", &startVertex, &endVertex);
                if (startVertex < numVertices && endVertex < numVertices) {
                    removeEdge(&graph, startVertex, endVertex);
                    printf("Edge removed between %d and %d.\n", startVertex, endVertex);
                } else {
                    printf("Invalid vertex numbers!\n");
                }
                break;
            case 3:
                printf("Current Graph Representation:\n");
                displayGraph(&graph);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}