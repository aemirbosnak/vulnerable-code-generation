//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Struct to represent a graph edge
typedef struct Edge
{
    int source;      // Source vertex of the edge
    int destination; // Destination vertex of the edge
    int weight;       // Weight of the edge
} Edge;

// Struct to represent a graph
typedef struct Graph
{
    int num_vertices; // Number of vertices in the graph
    struct Edge *edges; // Array of edges in the graph
    int num_edges;     // Number of edges in the graph
} Graph;

// Function to create a new graph
Graph *create_graph(int num_vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    graph->edges = (Edge *)malloc(num_vertices * num_vertices * sizeof(Edge));
    return graph;
}

// Function to add an edge to a graph
void add_edge(Graph *graph, int source, int destination, int weight)
{
    assert(source >= 0 && source < graph->num_vertices);
    assert(destination >= 0 && destination < graph->num_vertices);

    graph->edges[graph->num_edges].source = source;
    graph->edges[graph->num_edges].destination = destination;
    graph->edges[graph->num_edges].weight = weight;
    graph->num_edges++;
}

// Function to print a graph
void print_graph(Graph *graph)
{
    for (int i = 0; i < graph->num_edges; i++)
    {
        printf("Edge %d: (%d, %d, %d)\n", i, graph->edges[i].source, graph->edges[i].destination, graph->edges[i].weight);
    }
}

// Main function
int main()
{
    // Create a new graph with 5 vertices
    Graph *graph = create_graph(5);

    // Add edges to the graph
    add_edge(graph, 0, 1, 10);
    add_edge(graph, 0, 2, 20);
    add_edge(graph, 1, 2, 30);
    add_edge(graph, 1, 3, 40);
    add_edge(graph, 1, 4, 50);
    add_edge(graph, 2, 3, 60);
    add_edge(graph, 2, 4, 70);
    add_edge(graph, 3, 4, 80);

    // Print the graph
    print_graph(graph);

    return 0;
}