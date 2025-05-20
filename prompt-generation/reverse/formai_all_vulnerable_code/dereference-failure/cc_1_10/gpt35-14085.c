//FormAI DATASET v1.0 Category: Graph representation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_V 10 // Maximum number of vertices in the graph

typedef struct edge { // Structure for edges in the graph
    int source;
    int destination;
} Edge;

typedef struct graph { // Structure for the graph itself
    int num_vertices;
    Edge* edges[MAX_V];
} Graph;

Graph* create_graph(int num_vertices) { // Function to create a new graph
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;

    for (int i = 0; i < num_vertices; i++) {
        graph->edges[i] = NULL;
    }

    return graph;
}

void add_edge(Graph* graph, int source, int destination) { // Function to add a new edge to the graph
    Edge* edge = (Edge*) malloc(sizeof(Edge));
    edge->source = source;
    edge->destination = destination;

    graph->edges[source] = edge;
}

void print_graph(Graph* graph) { // Function to print out the graph in a grid-like fashion
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            if (graph->edges[i] != NULL && graph->edges[i]->destination == j) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    printf("You find yourself at the edge of a cliff, staring down into a lush valley below...\n\n");

    Graph* graph = create_graph(6); // Create a graph with 6 vertices

    printf("You decide to climb down the cliff and explore the valley...\n");
    printf("You come across a winding path that leads deeper into the valley.\n");
    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3); // Add some edges to the graph to represent the path
    printf("You follow the path and come across a river that cuts through the valley.\n");
    add_edge(graph, 3, 4);
    printf("You cross the river and continue on your journey.\n");
    printf("Eventually, you reach the heart of the valley and find a hidden treasure trove!\n");
    add_edge(graph, 4, 5); // Add some more edges to the graph to represent the treasure trove

    printf("\nYou pull out your map and sketch out the path you took:\n");
    print_graph(graph); // Print out the graph to visualize the path

    return 0;
}