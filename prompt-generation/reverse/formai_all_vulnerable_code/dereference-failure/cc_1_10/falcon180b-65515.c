//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_COLORS 10

typedef struct {
    int id;
    int color;
    int degree;
    int visited;
} Node;

Node graph[MAX_NODES];
int num_nodes;
int num_edges;
int num_colors;
int *color_map;

void createGraph(int n, int m) {
    num_nodes = n;
    num_edges = m;
    for (int i = 0; i < n; i++) {
        graph[i].id = i;
        graph[i].color = -1;
        graph[i].degree = 0;
        graph[i].visited = 0;
    }
    color_map = (int *)malloc(MAX_COLORS * sizeof(int));
    for (int i = 0; i < MAX_COLORS; i++) {
        color_map[i] = -1;
    }
}

void addEdge(int u, int v) {
    graph[u].degree++;
    graph[v].degree++;
}

int getColor(int c) {
    if (color_map[c] == -1) {
        color_map[c] = num_colors++;
    }
    return color_map[c];
}

void colorGraph(int start) {
    int c = 0;
    for (int i = 0; i < num_nodes; i++) {
        if (graph[i].color == -1 && graph[i].degree == 0) {
            graph[i].color = c;
            colorGraph(i);
        }
    }
}

int main() {
    int n, m;
    printf("Enter the number of nodes and edges in the graph: ");
    scanf("%d %d", &n, &m);
    createGraph(n, m);
    for (int i = 0; i < m; i++) {
        int u, v;
        printf("Enter the end points of edge %d: ", i+1);
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    colorGraph(0);
    printf("The colored graph is:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d has color %d\n", i, graph[i].color);
    }
    return 0;
}