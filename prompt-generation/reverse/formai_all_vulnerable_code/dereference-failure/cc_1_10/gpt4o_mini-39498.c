//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure for the graph
typedef struct Graph {
    int numVertices;
    int **adjMatrix;
} Graph;

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    
    // Allocate Memory for adjacency matrix
    graph->adjMatrix = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int *)malloc(vertices * sizeof(int));
    }

    // Initialize adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0; // No path yet, just like my love life!
        }
    }
    return graph;
}

// Function to add edges to the graph (aka making friends)
void addEdge(Graph *graph, int from, int to) {
    graph->adjMatrix[from][to] = 1; // You are now connected! Wohoo!
    graph->adjMatrix[to][from] = 1; // Friend-in, friend-out logic!
}

// Function to print the adjacency matrix (let’s see who’s connected to whom)
void printGraph(Graph *graph) {
    printf("Here's the connection matrix! (may contain awkward moments)\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free the allocated memory (time to clean up after the party!)
void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

// Function to simulate a party (or a LinkedIn meetup)
void graphParty(int numPeople) {
    Graph *mySocialGraph = createGraph(numPeople);
    
    // Let's add some 'connections' (or people we totally forgot we met)
    addEdge(mySocialGraph, 0, 1); // Person 0 met Person 1
    addEdge(mySocialGraph, 0, 2); // Person 0 met Person 2
    addEdge(mySocialGraph, 1, 2); // Person 1 met Person 2
    addEdge(mySocialGraph, 2, 3); // Person 2 met Person 3
    addEdge(mySocialGraph, 3, 4); // Person 3 met Person 4
    
    // Print the social matrix (not to be confused with the social anxiety matrix)
    printGraph(mySocialGraph);
    
    // Cleaning up after our mess
    freeGraph(mySocialGraph);
    printf("Party's over! Go home, folks!\n");
}

// Main function: The party starter
int main() {
    int numPeople = 5; // More than enough for a fun-filled evening!
    
    // Kick-off the fun
    graphParty(numPeople);
    
    return 0;
}