//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NODES 10 // Number of nodes(vertices) in the graph
#define COLORS 3 // Number of colors available for coloring the graph

/* Structure to represent an edge in the graph */
typedef struct {
    int u, v;
} Edge;

/* Structure to represent a node in the graph */
typedef struct {
    int id;
    int color;
    int degree;
    int adj[NODES];
} Node;

/* Function to initialize the graph with random edges */
void initializeGraph(Node* nodes, int* numEdges) {
    int i, j, n = 0;
    Edge e;
    srand(time(NULL));
    for (i = 0; i < NODES; i++) {
        nodes[i].id = i;
        nodes[i].color = -1;
        nodes[i].degree = 0;
        for (j = 0; j < NODES; j++) {
            if (i != j) {
                if (rand() % 2) {
                    e.u = i;
                    e.v = j;
                    nodes[i].adj[n++] = j;
                    nodes[j].adj[n++] = i;
                    *numEdges += 1;
                }
            }
        }
        nodes[i].degree = n;
        n = 0;
    }
}

/* Function to print the graph */
void printGraph(Node* nodes) {
    int i, j;
    printf("Graph:\n");
    for (i = 0; i < NODES; i++) {
        printf("Node %d: ", nodes[i].id);
        for (j = 0; j < nodes[i].degree; j++) {
            printf("%d ", nodes[i].adj[j]);
        }
        printf("\n");
    }
}

/* Function to check if a node is a valid candidate for coloring with a given color */
int isValid(Node* nodes, int nodeId, int color) {
    int i;
    for (i = 0; i < nodes[nodeId].degree; i++) { // Check if any neighbor has same color as given color
        if (nodes[nodes[nodeId].adj[i]].color == color) {
            return 0;
        }
    }
    return 1;
}

/* Function to find a valid color for a node */
void findValidColor(Node* nodes, int nodeId) {
    int i;
    for (i = 0; i < COLORS; i++) {
        if (isValid(nodes, nodeId, i)) {
            nodes[nodeId].color = i;
            break;
        }
    }
}

/* Function to color the graph using backtracking */
int colorGraph(Node* nodes, int nodeId) {
    int i;
    if (nodeId == NODES) { // If all nodes are colored, return success
        return 1;
    }
    for (i = 0; i < COLORS; i++) {
        if (isValid(nodes, nodeId, i)) { // Check if node can be colored with color i
            nodes[nodeId].color = i;
            if (colorGraph(nodes, nodeId + 1)) { // Color the next node
                return 1;
            }
            nodes[nodeId].color = -1; // Backtrack to previous state
        }
    }
    return 0;
}

/* Function to print the colors of each node */
void printColors(Node* nodes) {
    int i;
    printf("Node Colors:\n");
    for (i = 0; i < NODES; i++) {
        printf("Node %d: %d\n", nodes[i].id, nodes[i].color);
    }
}

int main() {
    Node nodes[NODES];
    int numEdges = 0;
    initializeGraph(nodes, &numEdges);
    printf("Graph created with %d edges\n", numEdges);
    printGraph(nodes);

    if (colorGraph(nodes, 0)) {
        printf("Graph successfully colored\n");
        printColors(nodes);
    }
    else {
        printf("Graph could not be colored with %d colors\n", COLORS);
    }

    return 0;
}