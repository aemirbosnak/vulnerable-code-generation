//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 10

typedef struct {
    int adjMatrix[MAX_NODES][MAX_NODES];
    int numNodes;
} Graph;

void initGraph(Graph *g, int numNodes) {
    g->numNodes = numNodes;
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1; // For undirected graph
}

void printGraph(Graph *g) {
    for (int i = 0; i < g->numNodes; i++) {
        printf("Node %d: ", i);
        for (int j = 0; j < g->numNodes; j++) {
            if (g->adjMatrix[i][j] == 1) {
                printf(" -> %d", j);
            }
        }
        printf("\n");
    }
}

void bfs(Graph *g, int startNode) {
    bool visited[MAX_NODES] = {false};
    int queue[MAX_NODES], front = -1, rear = -1;
    
    visited[startNode] = true;
    queue[++rear] = startNode;

    printf("BFS starting from node %d:\n", startNode);
    
    while (front != rear) {
        front++;
        int currentNode = queue[front];
        printf("Visited %d\n", currentNode);

        for (int i = 0; i < g->numNodes; i++) {
            if (g->adjMatrix[currentNode][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
}

void freeGraph(Graph *g) {
    // Currently, there's no dynamic memory to free, but in a more complex graph, 
    // this would be where you handle freeing any allocated memory.
}

int main() {
    Graph g;
    int numNodes;

    printf("Enter number of nodes in the network (max %d): ", MAX_NODES);
    scanf("%d", &numNodes);

    if (numNodes > MAX_NODES) {
        printf("Number of nodes exceeds the maximum allowed (%d).\n", MAX_NODES);
        return 1;
    }

    initGraph(&g, numNodes);

    int numEdges;
    printf("Enter number of edges: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        printf("Enter edge %d (src dest): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(&g, src, dest);
    }

    printf("\nNetwork Topology:\n");
    printGraph(&g);

    int startNode;
    printf("\nEnter starting node for BFS: ");
    scanf("%d", &startNode);

    if (startNode < 0 || startNode >= numNodes) {
        printf("Invalid starting node!\n");
        freeGraph(&g);
        return 1;
    }

    bfs(&g, startNode);

    freeGraph(&g);

    return 0;
}