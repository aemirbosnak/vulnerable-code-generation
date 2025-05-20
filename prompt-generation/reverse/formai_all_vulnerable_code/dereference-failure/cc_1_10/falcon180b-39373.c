//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    int visited;
} Node;

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

void add_edge(Edge edges[], int n, int src, int dest, int weight) {
    edges[n].src = src;
    edges[n].dest = dest;
    edges[n].weight = weight;
    n++;
}

int dfs(Node nodes[], int n, int start, int visited[], int parent[]) {
    visited[start] = 1;
    printf("%s ", nodes[start].name);

    for (int i = 0; i < n; i++) {
        if (nodes[i].id == start && nodes[i].visited == 0) {
            parent[i] = start;
            dfs(nodes, n, i, visited, parent);
        }
    }

    return 0;
}

int main() {
    Node nodes[MAX_NODES];
    Edge edges[MAX_EDGES];
    int n = 0, m = 0;
    int src, dest, weight;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter name for node %d: ", i + 1);
        scanf("%s", nodes[i].name);
        nodes[i].id = i + 1;
        nodes[i].visited = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        printf("Enter source node ID: ");
        scanf("%d", &src);
        printf("Enter destination node ID: ");
        scanf("%d", &dest);
        printf("Enter weight: ");
        scanf("%d", &weight);

        add_edge(edges, n, src, dest, weight);
    }

    int visited[n];
    memset(visited, 0, n * sizeof(int));

    for (int i = 0; i < n; i++) {
        if (nodes[i].visited == 0) {
            dfs(nodes, n, i, visited, NULL);
        }
    }

    return 0;
}