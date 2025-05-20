//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_NODES 100
#define MAX_COLOURS 8

typedef struct {
    int node;
    int colour;
} Node;

int graph_coloring(Node* graph, int size, int colour) {
    // Create a color array of size MAX_COLOURS
    int* colours = malloc(MAX_COLOURS * sizeof(int));

    // Initialize all colours to -1
    memset(colours, -1, MAX_COLOURS * sizeof(int));

    // Set the first colour to 0
    colours[0] = 0;

    // Perform a depth-first search to assign colours
    int* visited = malloc(MAX_NODES * sizeof(int));
    memset(visited, 0, MAX_NODES * sizeof(int));

    int* neighbours = malloc(MAX_NODES * sizeof(int));
    for (int i = 0; i < size; i++) {
        neighbours[i] = graph[i].node;
    }

    // Assign colours to nodes in a depth-first search
    int current_node = 0;
    while (visited[current_node] == 0) {
        int colour_found = -1;
        for (int i = 0; i < MAX_COLOURS; i++) {
            if (colours[i] == -1 &&!visited[i]) {
                colour_found = i;
                break;
            }
        }
        if (colour_found!= -1) {
            colours[colour_found] = colour;
            visited[colour_found] = 1;
        } else {
            for (int i = 0; i < MAX_COLOURS; i++) {
                if (colours[i] == -1) {
                    colours[i] = colour;
                    visited[i] = 1;
                    current_node = neighbours[current_node];
                    break;
                }
            }
        }
    }

    // Free memory
    free(colours);
    free(visited);
    free(neighbours);

    return 0;
}

int main() {
    // Create a graph with 4 nodes
    Node graph[MAX_NODES] = {
        {1, -1},
        {2, -1},
        {3, -1},
        {4, -1}
    };

    // Perform a graph coloring
    int colour = graph_coloring(graph, MAX_NODES, 1);

    // Print the result
    printf("Graph Coloring:\n");
    for (int i = 0; i < MAX_NODES; i++) {
        if (graph[i].colour!= -1) {
            printf("%d %d\n", graph[i].node, graph[i].colour);
        }
    }

    return 0;
}