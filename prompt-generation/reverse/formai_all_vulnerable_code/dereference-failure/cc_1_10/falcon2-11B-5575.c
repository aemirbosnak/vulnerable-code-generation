//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 1000000000

// Define a structure to represent a node in the graph
typedef struct node {
    int vertex;
    struct node *next;
} node;

// Define a structure to represent a graph
typedef struct graph {
    node *head;
    int numVertices;
} graph;

// Function to add an edge between two vertices in the graph
void addEdge(graph *g, int u, int v) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->vertex = v;
    newNode->next = g->head;
    g->head = newNode;
    g->numVertices++;
}

// Function to color the vertices of the graph using the Minimum 3-Coloring algorithm
bool colorGraph(graph *g) {
    int colors[g->numVertices];
    int colorCount[g->numVertices];

    // Initialize all colors to -1
    for (int i = 0; i < g->numVertices; i++) {
        colors[i] = -1;
    }

    // Initialize colorCount to 0
    for (int i = 0; i < g->numVertices; i++) {
        colorCount[i] = 0;
    }

    // Run the Minimum 3-Coloring algorithm
    while (true) {
        int uncoloredVertices = 0;

        // Count the number of uncolored vertices
        for (int i = 0; i < g->numVertices; i++) {
            if (colors[i] == -1) {
                uncoloredVertices++;
            }
        }

        // If there are no uncolored vertices, the graph is already colored
        if (uncoloredVertices == 0) {
            return true;
        }

        // Otherwise, color each uncolored vertex with a different color
        for (int i = 0; i < uncoloredVertices; i++) {
            int vertex = -1;
            int color = -1;

            // Find an uncolored vertex
            for (int j = 0; j < g->numVertices; j++) {
                if (colors[j] == -1) {
                    vertex = j;
                    break;
                }
            }

            // Find a color that is not used by any adjacent vertices
            for (int k = 0; k < g->numVertices; k++) {
                if (colors[k]!= -1 && g->head->next!= NULL && g->head->next->vertex == vertex) {
                    color = colors[k];
                    break;
                }
            }

            // If no color is found, the graph is not 3-colorable
            if (color == -1) {
                return false;
            }

            // Color the vertex
            colors[vertex] = color;
            colorCount[color]++;
        }
    }
}

// Function to print the graph
void printGraph(graph *g) {
    node *current = g->head;

    printf("Graph: \n");
    while (current!= NULL) {
        printf("%d -> ", current->vertex);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int numVertices;
    scanf("%d", &numVertices);

    graph *g = (graph *)malloc(sizeof(graph));
    g->head = NULL;
    g->numVertices = 0;

    // Add edges to the graph
    for (int i = 0; i < numVertices - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(g, u, v);
    }

    // Color the vertices of the graph
    if (colorGraph(g)) {
        printf("Graph is 3-colorable.\n");
    } else {
        printf("Graph is not 3-colorable.\n");
    }

    // Print the graph
    printGraph(g);

    return 0;
}