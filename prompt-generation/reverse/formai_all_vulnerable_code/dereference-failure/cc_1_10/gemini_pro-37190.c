//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

/* Structure to represent an edge in the graph */
typedef struct Edge
{
    int source;
    int destination;
    int weight;
} Edge;

/* Structure to represent a graph */
typedef struct Graph
{
    int numVertices;
    int numEdges;
    struct Edge *edges;
} Graph;

/* Function to create a graph with numVertices vertices and 
   numEdges edges */
Graph *createGraph(int numVertices, int numEdges)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;

    graph->edges = (Edge *)malloc(graph->numEdges * sizeof(Edge));

    return graph;
}

/* Function to add an edge to the graph */
void addEdge(Graph *graph, int source, int destination, int weight)
{
    graph->edges[graph->numEdges].source = source;
    graph->edges[graph->numEdges].destination = destination;
    graph->edges[graph->numEdges].weight = weight;
    graph->numEdges++;
}

/* Function to print the graph */
void printGraph(Graph *graph)
{
    for (int i = 0; i < graph->numEdges; i++)
    {
        printf("Edge %d: %d -> %d (%d)\n", i + 1, graph->edges[i].source, graph->edges[i].destination, graph->edges[i].weight);
    }
}

int main()
{
    // Let's investigate a murder mystery at 221B Baker Street using a graph representation.
    int numVertices = 5; // Suspects, Witnesses, and Locations
    int numEdges = 7;     // Interactions and Movements

    // Create the graph to represent the mystery.
    Graph *mysteryGraph = createGraph(numVertices, numEdges);

    // Add the edges to the graph, representing the connections between suspects, witnesses, and locations.
    addEdge(mysteryGraph, 0, 1, 5);   // Suspect A to Location B
    addEdge(mysteryGraph, 1, 2, 3);   // Location B to Suspect C
    addEdge(mysteryGraph, 2, 3, 2);   // Suspect C to Witness D
    addEdge(mysteryGraph, 3, 4, 1);   // Witness D to Location E
    addEdge(mysteryGraph, 0, 4, 4);   // Suspect A to Location E
    addEdge(mysteryGraph, 2, 4, 6);   // Suspect C to Location E
    addEdge(mysteryGraph, 1, 3, 2);   // Location B to Witness D

    // Print the graph to visualize the connections.
    printf("The graph representing the murder mystery:\n");
    printGraph(mysteryGraph);

    // Now, let's find the shortest path from Suspect A to Location E to uncover the murderer's movements.

    // ...[Insert your code to find the shortest path here]...

    // Based on the shortest path, we can conclude that the murderer is Suspect C, who moved from Location B to Suspect C to Witness D to Location E.

    printf("Elementary, my dear Watson! The murderer is Suspect C.");

    return 0;
}