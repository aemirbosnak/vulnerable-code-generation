//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure to represent a vertex in the graph
typedef struct Vertex {
    char name[30];
    struct Vertex** connections;
    int degree;
} Vertex;

// Structure to represent a graph
typedef struct Graph {
    Vertex** vertices;
    int numVertices;
} Graph;

// Function to create a new vertex
Vertex* createVertex(const char* name) {
    Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex));
    strcpy(newVertex->name, name);
    newVertex->connections = NULL;
    newVertex->degree = 0;
    return newVertex;
}

// Function to initialize a graph
Graph* createGraph(int maxVertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->vertices = (Vertex**)malloc(maxVertices * sizeof(Vertex*));
    g->numVertices = 0;
    return g;
}

// Function to add a vertex to the graph
void addVertex(Graph* g, const char* name) {
    Vertex* v = createVertex(name);
    g->vertices[g->numVertices++] = v;
}

// Function to find a vertex in the graph
Vertex* findVertex(Graph* g, const char* name) {
    for (int i = 0; i < g->numVertices; i++) {
        if (strcmp(g->vertices[i]->name, name) == 0) {
            return g->vertices[i];
        }
    }
    return NULL;
}

// Function to add an edge (connection) between two vertices
void addEdge(Graph* g, const char* srcName, const char* destName) {
    Vertex* src = findVertex(g, srcName);
    Vertex* dest = findVertex(g, destName);

    if (src && dest) {
        src->connections = (Vertex**)realloc(src->connections, (src->degree + 1) * sizeof(Vertex*));
        src->connections[src->degree++] = dest;

        dest->connections = (Vertex**)realloc(dest->connections, (dest->degree + 1) * sizeof(Vertex*));
        dest->connections[dest->degree++] = src;
    }
}

// Function to print the graph in a post-apocalyptic style
void printGraph(Graph* g) {
    printf("\nSurvivors' Territories and Connections:\n");
    for (int i = 0; i < g->numVertices; i++) {
        Vertex* v = g->vertices[i];
        printf("Territory: %s | Allies: ", v->name);
        for (int j = 0; j < v->degree; j++) {
            printf("%s", v->connections[j]->name);
            if (j < v->degree - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

// Function to free the memory allocated for the graph
void freeGraph(Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        free(g->vertices[i]->connections);
        free(g->vertices[i]);
    }
    free(g->vertices);
    free(g);
}

// Main function to demonstrate the graph
int main() {
    Graph* g = createGraph(10);
    
    addVertex(g, "Echo Base");
    addVertex(g, "Scavenger Camp");
    addVertex(g, "Radio Tower");
    addVertex(g, "Fortress of Resilience");

    addEdge(g, "Echo Base", "Scavenger Camp");
    addEdge(g, "Echo Base", "Radio Tower");
    addEdge(g, "Scavenger Camp", "Fortress of Resilience");
    addEdge(g, "Radio Tower", "Fortress of Resilience");

    // Introduce a survivor message
    printf("In a world ravaged by chaos, the survivors have banded together...\n");
    printGraph(g);

    // Clean up memory
    freeGraph(g);
    
    return 0;
}