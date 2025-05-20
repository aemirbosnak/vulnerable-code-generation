//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// structure to represent a vertex in the graph
typedef struct vertex {
    int data;
    int color;
    struct vertex* adjacent[10]; // max 10 adjacent vertices allowed
} Vertex;

// function to initialize a new vertex with given data
Vertex* initVertex(int data) {
    Vertex* newVertex = malloc(sizeof(Vertex));
    newVertex->data = data;
    newVertex->color = 0;
    memset(newVertex->adjacent, 0, sizeof(newVertex->adjacent));
    return newVertex;
}

// function to add an edge between two vertices
void addEdge(Vertex* v1, Vertex* v2) {
    int i;
    for (i = 0; i < 10; i++) {
        if (v1->adjacent[i] == NULL) {
            v1->adjacent[i] = v2;
            break;
        }
    }
    for (i = 0; i < 10; i++) {
        if (v2->adjacent[i] == NULL) {
            v2->adjacent[i] = v1;
            break;
        }
    }
}

// function to print the graph for debugging
void printGraph(Vertex** graph, int numVertices) {
    int i, j;
    for (i = 0; i < numVertices; i++) {
        printf("%d: ", graph[i]->data);
        for (j = 0; j < 10; j++) {
            if (graph[i]->adjacent[j] != NULL) {
                printf("%d ", graph[i]->adjacent[j]->data);
            }
        }
        printf("\n");
    }
}

// function to check if the adjacent vertices of a vertex have the same color
bool areAdjacentVerticesColored(Vertex* vertex) {
    int i;
    for (i = 0; i < 10; i++) {
        if (vertex->adjacent[i] != NULL && vertex->adjacent[i]->color == vertex->color) {
            return true;
        }
    }
    return false;
}

// function to check if the graph is colored correctly
bool isGraphColoredCorrectly(Vertex** graph, int numVertices) {
    int i;
    for (i = 0; i < numVertices; i++) {
        if (areAdjacentVerticesColored(graph[i])) {
            return false;
        }
    }
    return true;
}

// function to check if all the vertices in the graph are colored
bool areAllVerticesColored(Vertex** graph, int numVertices) {
    int i;
    for (i = 0; i < numVertices; i++) {
        if (graph[i]->color == 0) {
            return false;
        }
    }
    return true;
}

// function to color the graph
void colorGraph(Vertex** graph, int numVertices) {
    int i, j, k;
    bool assignedColor;
    // loop through each vertex
    for (i = 0; i < numVertices; i++) {
        assignedColor = false;
        // loop through each color
        for (j = 1; j <= 4; j++) {
            graph[i]->color = j;
            if (!areAdjacentVerticesColored(graph[i])) {
                assignedColor = true;
                break;
            }
        }
        if (!assignedColor) {
            printf("Unable to color the graph with 4 colors.\n");
            exit(1);
        }
    }
}

int main() {
    int numVertices, i, v1Data, v2Data;
    Vertex** graph;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);
    graph = malloc(numVertices * sizeof(Vertex*));
    // initialize the vertices
    for (i = 0; i < numVertices; i++) {
        printf("Enter the data for vertex %d: ", i + 1);
        scanf("%d", &v1Data);
        graph[i] = initVertex(v1Data);
    }
    // add the edges between the vertices
    while (true) {
        printf("Enter the vertices to add an edge between (e.g. 1 2), or enter 0 to stop adding edges: ");
        scanf("%d %d", &v1Data, &v2Data);
        if (v1Data == 0 || v2Data == 0) {
            break;
        }
        Vertex* v1 = NULL;
        Vertex* v2 = NULL;
        // find the vertices with the given data
        for (i = 0; i < numVertices; i++) {
            if (graph[i]->data == v1Data) {
                v1 = graph[i];
            }
            if (graph[i]->data == v2Data) {
                v2 = graph[i];
            }
            if (v1 != NULL && v2 != NULL) {
                break;
            }
        }
        // add the edge between the vertices
        addEdge(v1, v2);
    }
    printf("Graph:\n");
    printGraph(graph, numVertices);
    // color the graph
    colorGraph(graph, numVertices);
    if (isGraphColoredCorrectly(graph, numVertices)) {
        printf("The graph has been successfully colored with 4 colors.\n");
    } else {
        printf("The graph has not been colored correctly.\n");
    }
    free(graph);
    return 0;
}