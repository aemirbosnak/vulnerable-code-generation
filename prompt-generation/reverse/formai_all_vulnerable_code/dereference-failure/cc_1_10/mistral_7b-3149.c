//MISTRAL-7B DATASET v1.0 Category: Network Topology Mapper ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 500
#define INF 99999

typedef struct {
    int src;
    int dest;
    bool visited;
} Edge;

void dfs(int node, int graph[][MAX_NODES], int visited[], int parent[], int n) {
    visited[node] = true;

    for (int i = 0; i < n; i++) {
        if (graph[node][i] != INF && !visited[i]) {
            parent[i] = node;
            dfs(i, graph, visited, parent, n);
        }
    }
}

int main(int argc, char* argv[]) {

    if (argc != 3 && argc != 4) {
        printf("Usage: %s <number_of_nodes> <number_of_edges> [edge1 node1 node2] ..." "\n", argv[0]);
        return -1;
    }

    int num_nodes = atoi(argv[1]);
    int num_edges = atoi(argv[2]);

    if (num_nodes <= 0 || num_edges <= 0) {
        printf("Invalid number of nodes or edges.\n");
        return -1;
    }

    if (num_edges > (num_nodes * (num_nodes - 1)) / 2) {
        printf("Too many edges. Each node can connect at most to all other nodes - %d.\n", num_nodes - 1);
        return -1;
    }

    int graph[MAX_NODES][MAX_NODES] = {0};

    for (int i = 0; i < num_edges; i++) {
        char edge_str[100];
        sscanf(argv[i + 3], "%s", edge_str);

        int node1 = atoi(strtok(edge_str, " "));
        int node2 = atoi(strtok(NULL, " "));

        if (node1 >= num_nodes || node2 >= num_nodes) {
            printf("Invalid node index: %d or %d.\n", node1, node2);
            return -1;
        }

        graph[node1][node2] = 1;
        graph[node2][node1] = 1;
    }

    int visited[MAX_NODES] = {0};
    int parent[MAX_NODES] = {-1};

    for (int i = 0; i < num_nodes; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited, parent, num_nodes);
        }
    }

    printf("\nNetwork Topology:\n");

    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: ", i);
        for (int j = 0; j < num_nodes; j++) {
            if (graph[i][j] == 1)
                printf(" %d", j);
        }
        printf("\n");
    }

    return 0;
}