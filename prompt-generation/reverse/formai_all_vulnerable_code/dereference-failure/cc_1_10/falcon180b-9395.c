//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define MAX_COLOR 6

typedef struct {
    int node1, node2;
    int color;
} Edge;

int graph[MAX_NODES][MAX_NODES];

void initializeGraph(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int n, Edge e) {
    if (graph[e.node1][e.node2] == 0) {
        graph[e.node1][e.node2] = e.color;
        graph[e.node2][e.node1] = e.color;
    } else {
        printf("Error: Edge (%d, %d) already exists.\n", e.node1, e.node2);
        exit(1);
    }
}

int colorGraph(int n) {
    int colors[MAX_NODES];
    memset(colors, -1, sizeof(colors));

    for (int i = 0; i < n; i++) {
        int color = 1;
        for (int j = 0; j < n; j++) {
            if (graph[i][j]!= 0 && colors[j] == color) {
                color++;
            }
        }
        if (color > MAX_COLOR) {
            printf("Error: Graph is not %d-colorable.\n", MAX_COLOR);
            exit(1);
        }
        colors[i] = color;
    }

    return colors[0];
}

int main(int argc, char *argv[]) {
    int n, m;

    if (argc < 3) {
        printf("Usage: %s <number of nodes> <number of edges>\n", argv[0]);
        exit(1);
    }

    n = atoi(argv[1]);
    m = atoi(argv[2]);

    Edge edges[MAX_EDGES];

    printf("Enter edges (node1 node2 color):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].node1, &edges[i].node2, &edges[i].color);
        addEdge(n, edges[i]);
    }

    int numColors = colorGraph(n);

    printf("Graph is %d-colorable.\n", numColors);

    return 0;
}