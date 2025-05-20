//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 50

void dfs(int node, int graph[MAX_NODES][MAX_NODES], int visited[MAX_NODES], int num_nodes) {
    int i;
    visited[node] = 1;

    printf("Node %d visited. Connections: ", node);
    for (i = 0; i < num_nodes; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            printf("%d ", i);
            dfs(i, graph, visited, num_nodes);
        }
    }
}

int main() {
    int graph[MAX_NODES][MAX_NODES];
    int visited[MAX_NODES];
    int num_nodes, i, j;

    printf("Enter the number of nodes in the network topology: ");
    scanf("%d", &num_nodes);

    // Initialize the graph
    for (i = 0; i < num_nodes; i++) {
        for (j = 0; j < num_nodes; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    // Get the connections between nodes
    char input[10];
    int node1, node2;
    do {
        printf("Enter a connection between two nodes (or 'q' to quit): ");
        scanf("%s", input);
        if (strcmp(input, "q") != 0) {
            node1 = atoi(strtok(input, ","));
            node2 = atoi(strtok(NULL, ","));
            graph[node1][node2] = 1;
            graph[node2][node1] = 1;
        }
    } while (strcmp(input, "q") != 0);

    // Print out the connections
    printf("\nNetwork Topology:\n");
    for (i = 0; i < num_nodes; i++) {
        printf("Node %d: ", i);
        for (j = 0; j < num_nodes; j++) {
            if (graph[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    // Start the depth-first search from node 0
    dfs(0, graph, visited, num_nodes);

    return 0;
}