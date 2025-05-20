//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Edge {
    int source;
    int destination;
    char *emotion; // Represents the emotion between the nodes
} Edge;

typedef struct Graph {
    int numVertices;
    int numEdges;
    Edge edges[MAX * MAX];
} Graph;

// A romantic character to enchant
typedef struct Character {
    char *name;
    int age;
} Character;

Graph* createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->numEdges = 0;
    return graph;
}

void addEdge(Graph *graph, int source, int destination, const char *emotion) {
    if (graph->numEdges < MAX * MAX) {
        graph->edges[graph->numEdges].source = source;
        graph->edges[graph->numEdges].destination = destination;
        graph->edges[graph->numEdges].emotion = strdup(emotion); // Copy the emotion string
        graph->numEdges++;
    }
}

void displayLoveConnections(Graph *graph, Character *characters) {
    printf("Love Connections in Our Romantic Tale:\n");
    for (int i = 0; i < graph->numEdges; i++) {
        printf("%s and %s share a tender feeling of %s.\n",
               characters[graph->edges[i].source].name,
               characters[graph->edges[i].destination].name,
               graph->edges[i].emotion);
    }
}

void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->numEdges; i++) {
        free(graph->edges[i].emotion); // Freeing emotion strings
    }
    free(graph);
}

int main() {
    // Characters in our story
    Character characters[MAX] = {
        {"Romeo", 22},
        {"Juliet", 21},
        {"Helena", 24},
        {"Damon", 23},
        {"Catherine", 22}
    };
    
    // Create a romantic graph
    Graph *loveGraph = createGraph(5);

    // Adding edges with emotions
    addEdge(loveGraph, 0, 1, "undying love");
    addEdge(loveGraph, 1, 0, "passion");
    addEdge(loveGraph, 0, 3, "friendship");
    addEdge(loveGraph, 2, 3, "longing");
    addEdge(loveGraph, 4, 0, "admiration");
    addEdge(loveGraph, 1, 2, "jealousy");

    // Displaying the love connections between characters
    displayLoveConnections(loveGraph, characters);

    // Free allocated memory for the graph
    freeGraph(loveGraph);
    
    return 0;
}