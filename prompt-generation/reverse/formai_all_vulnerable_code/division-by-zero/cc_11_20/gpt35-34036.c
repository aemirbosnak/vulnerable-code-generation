//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 10
#define MAX_EDGES 20
#define COLORS 3

typedef struct {
    int node1;
    int node2;
} Edge;

typedef struct {
    int node;
    int color;
} NodeColor;

int main() {
    Edge edges[MAX_EDGES];
    NodeColor nodeColors[MAX_NODES];
    int numNodes, numEdges, i, j, k;
    
    printf("Welcome to the Cyberpunk Graph Coloring Problem!\n");
    printf("Please enter the number of nodes: ");
    scanf("%d", &numNodes);
    printf("Please enter the number of edges: ");
    scanf("%d", &numEdges);
    
    // Generate random edges
    srand(time(NULL));
    for (i = 0; i < numEdges; i++) {
        edges[i].node1 = rand() % numNodes;
        edges[i].node2 = rand() % numNodes;
    }
    
    // Initialize node colors to -1 (unassigned)
    for (i = 0; i < numNodes; i++) {
        nodeColors[i].node = i;
        nodeColors[i].color = -1;
    }
    
    // Try to assign colors to nodes
    for (i = 0; i < numNodes; i++) {
        // Check which colors are already assigned to neighboring nodes
        int usedColors[COLORS] = {0};
        for (j = 0; j < numEdges; j++) {
            if (edges[j].node1 == i) {
                int neighbor = edges[j].node2;
                if (nodeColors[neighbor].color != -1) {
                    usedColors[nodeColors[neighbor].color] = 1;
                }
            }
            if (edges[j].node2 == i) {
                int neighbor = edges[j].node1;
                if (nodeColors[neighbor].color != -1) {
                    usedColors[nodeColors[neighbor].color] = 1;
                }
            }
        }
        // Assign the first unused color to the node
        for (k = 0; k < COLORS; k++) {
            if (!usedColors[k]) {
                nodeColors[i].color = k;
                break;
            }
        }
    }
    
    // Print the results
    printf("\nNode Colors:\n");
    for (i = 0; i < numNodes; i++) {
        printf("Node %d: Color %d\n", nodeColors[i].node, nodeColors[i].color);
    }
    
    return 0;
}