//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_EDGES 500

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

bool graphColoringHelper(int graph[MAX_VERTICES][MAX_VERTICES], int m, int vertex, int color[], int n) {
    int i;
    bool assigned = true;

    for (i = 0; i < vertex; i++) {
        if (graph[vertex][i] != -1 && color[i] == color[vertex]) {
            assigned = false;
            break;
        }
    }

    if (assigned) {
        color[vertex] = m;
        for (i = 0; i < vertex; i++) {
            if (graph[vertex][i] != -1) {
                if (!graphColoringHelper(graph, m, i, color, vertex + 1)) {
                    return false;
                }
            }
        }
        return true;
    }

    return false;
}

bool graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    int color[n];
    int m = 0;

    for (int i = 0; i < n; i++) {
        color[i] = -1;
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != -1) {
                m = (m < graph[i][j]) ? graph[i][j] : m;
            }
        }
    }

    return graphColoringHelper(graph, m + 1, 0, color, 1);
}

int main() {
    int n, e, i, j, k;
    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    printf("Enter the edges (source destination weight):\n");

    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &graph[i][0], &graph[i][1], &graph[i][2]);
        graph[i][0]--;
        graph[i][1]--;
        if (graph[i][0] < 0 || graph[i][1] < 0 || graph[i][0] >= n || graph[i][1] >= n) {
            printf("Invalid vertex number\n");
            return 1;
        }
        if (graph[i][2] < 0) {
            printf("Invalid weight\n");
            return 1;
        }
        if (i > 0 && graph[i][0] == graph[i - 1][1]) {
            printf("Edge connects the same vertices\n");
            return 1;
        }
    }

    if (graphColoring(graph, n)) {
        printf("Graph can be colored with %d colors\n", n);
    } else {
        printf("Graph cannot be colored\n");
    }

    return 0;
}