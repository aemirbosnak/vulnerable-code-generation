//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int** create_graph(int n) {
    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
    }
    return graph;
}

void graph_coloring(int** graph, int n) {
    int colors[n];
    for (int i = 0; i < n; i++) {
        colors[i] = i;
    }
    int** new_graph = create_graph(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j]!= 0 && colors[i] == colors[j]) {
                new_graph[i][j] = new_graph[j][i] = INT_MAX;
            } else {
                new_graph[i][j] = new_graph[j][i] = INT_MIN;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j]!= 0) {
                printf("%d ", graph[i][j]);
            }
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (new_graph[i][j]!= INT_MAX) {
                printf("%d ", new_graph[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int n = 5;
    int** graph = create_graph(n);
    graph[0][1] = graph[0][2] = graph[0][3] = graph[0][4] = 1;
    graph[1][2] = graph[1][4] = 1;
    graph[2][3] = graph[3][4] = 1;
    graph_coloring(graph, n);
    return 0;
}