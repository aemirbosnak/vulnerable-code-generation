//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: Cyberpunk
// Cyberpunk Graph Coloring Problem

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
    int id;
    int color;
} Node;

typedef struct {
    int from;
    int to;
} Edge;

Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];
int numNodes, numEdges;

void initializeNodes() {
    srand(time(NULL));
    for (int i = 0; i < MAX_NODES; i++) {
        nodes[i].id = i + 1;
        nodes[i].color = rand() % 7; // Using 7 colors for simplicity
    }
}

void initializeEdges() {
    srand(time(NULL));
    for (int i = 0; i < MAX_EDGES; i++) {
        int from = rand() % numNodes;
        int to = rand() % numNodes;
        if (from == to) continue;
        edges[i].from = from;
        edges[i].to = to;
    }
}

int dfs(Node *node, int *colorUsed, int *numColors) {
    if (node->color!= -1) return 0; // Already colored

    int color = *colorUsed % 7; // Get next available color
    *numColors -= 1; // Update number of colors used
    node->color = color;

    *colorUsed += 1; // Increment color used counter
    int numUncoloredNeighbors = 0;

    for (int i = 0; i < numEdges; i++) {
        if (edges[i].from == node->id || edges[i].to == node->id) {
            Node *neighbor = &nodes[edges[i].from];
            if (neighbor->color == -1) {
                numUncoloredNeighbors += 1;
            }
        }
    }

    if (numUncoloredNeighbors > 0) {
        int maxColors = *numColors - 1;
        if (numUncoloredNeighbors > maxColors) {
            return 1; // Graph cannot be colored
        }
        for (int i = 0; i < numEdges; i++) {
            Node *neighbor = &nodes[edges[i].from];
            if (neighbor->color == -1) {
                dfs(neighbor, colorUsed, numColors);
            }
        }
    }

    return 0;
}

void printGraph() {
    printf("Graph:\n");
    for (int i = 0; i < numNodes; i++) {
        Node *node = &nodes[i];
        printf("Node %d (color %d): ", node->id, node->color);
        for (int j = 0; j < numEdges; j++) {
            if (edges[j].from == node->id || edges[j].to == node->id) {
                printf("%d ", edges[j].to);
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator
    initializeNodes(); // Initialize nodes
    initializeEdges(); // Initialize edges
    numNodes = MAX_NODES;
    numEdges = MAX_EDGES;

    int numColors = 7; // Number of colors available

    int *colorUsed = (int*)malloc(sizeof(int));
    *colorUsed = numColors;

    int result = 0;
    for (int i = 0; i < numNodes; i++) {
        if (nodes[i].color == -1) {
            result = dfs(&nodes[i], colorUsed, &numColors);
            if (result) break;
        }
    }

    if (result == 0) {
        printf("Graph can be colored!\n");
    } else {
        printf("Graph cannot be colored!\n");
    }

    printGraph();

    free(colorUsed);

    return 0;
}