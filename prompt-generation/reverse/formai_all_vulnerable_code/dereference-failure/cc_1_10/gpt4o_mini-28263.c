//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Structure to represent a graph
typedef struct Graph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function prototypes
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);
void removeEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);
bool isEdge(Graph* graph, int src, int dest);
void freeGraph(Graph* graph);
void paranoidCheck(int src, int dest, Graph* graph);

// Main function to drive the program
int main() {
    int vertices, src, dest;
    char choice;
    
    printf("Welcome to the paranoid graph representation system.\n");
    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);

    if (vertices > MAX_VERTICES || vertices <= 0) {
        printf("Invalid number of vertices. Exiting...\n");
        return EXIT_FAILURE;
    }

    Graph* graph = createGraph(vertices);
    
    while (true) {
        printf("\nOptions:\n");
        printf("1. Add edge\n");
        printf("2. Remove edge\n");
        printf("3. Print Graph\n");
        printf("4. Check if an edge exists\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter source and destination of the edge: ");
                scanf("%d %d", &src, &dest);
                paranoidCheck(src, dest, graph);
                break;
            case '2':
                printf("Enter source and destination of the edge to remove: ");
                scanf("%d %d", &src, &dest);
                paranoidCheck(src, dest, graph);
                removeEdge(graph, src, dest);
                break;
            case '3':
                printGraph(graph);
                break;
            case '4':
                printf("Enter source and destination to check for an edge: ");
                scanf("%d %d", &src, &dest);
                if (isEdge(graph, src, dest)) {
                    printf("There is an edge from %d to %d.\n", src, dest);
                } else {
                    printf("No edge exists from %d to %d.\n", src, dest);
                }
                break;
            case '5':
                freeGraph(graph);
                printf("Exiting paranoid graph system.\n");
                return EXIT_SUCCESS;
            default:
                printf("Invalid option. Please choose again.\n");
        }
    }
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    if (src < 0 || src >= graph->numVertices || dest < 0 || dest >= graph->numVertices) {
        printf("Warning: Invalid edge [%d -> %d]. Out of bounds!\n", src, dest);
        return;
    }
    graph->adjMatrix[src][dest] = 1;
    printf("Edge added from %d to %d.\n", src, dest);
}

void removeEdge(Graph* graph, int src, int dest) {
    if (src < 0 || src >= graph->numVertices || dest < 0 || dest >= graph->numVertices) {
        printf("Warning: Attempted to remove an invalid edge [%d -> %d]. Ignoring command.\n", src, dest);
        return;
    }
    graph->adjMatrix[src][dest] = 0;
    printf("Edge removed from %d to %d.\n", src, dest);
}

void printGraph(Graph* graph) {
    printf("Graph adjacency matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

bool isEdge(Graph* graph, int src, int dest) {
    if (src < 0 || src >= graph->numVertices || dest < 0 || dest >= graph->numVertices) {
        printf("Warning: Checking invalid edge [%d -> %d].\n", src, dest);
        return false;
    }
    return graph->adjMatrix[src][dest] == 1;
}

void freeGraph(Graph* graph) {
    if (graph) {
        free(graph);
        printf("Graph memory freed.\n");
    }
}

void paranoidCheck(int src, int dest, Graph* graph) {
    printf("Performing paranoid check for edge [%d -> %d]...\n", src, dest);
    if (isEdge(graph, src, dest)) {
        printf("Warning: Edge already exists from %d to %d!\n", src, dest);
    } else {
        addEdge(graph, src, dest);
    }
}