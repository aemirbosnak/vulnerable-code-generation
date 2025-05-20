//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Graph representation using adjacency matrix
int graph[MAX][MAX];

// Create a random graph with a given number of vertices
void create_graph(int n) {
    int i, j, count = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i!= j) {
                graph[i][j] = rand() % 2;
                if (graph[i][j]) {
                    count++;
                }
            } else {
                graph[i][j] = 0;
            }
        }
    }
    printf("Number of edges: %d\n", count);
}

// Print the given graph
void print_graph(int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Check if the given graph is bipartite
int is_bipartite(int n, int color[], int start) {
    int i, j, k, flag = 0;
    for (i = 0; i < n; i++) {
        if (color[i] == -1) {
            color[i] = start;
            if (!is_bipartite(n, color, -start)) {
                flag = 1;
                break;
            }
        }
    }
    return flag;
}

// Color the given graph using backtracking
void color_graph(int n) {
    int i, j, start = 1;
    int color[n];
    for (i = 0; i < n; i++) {
        color[i] = -1;
    }
    if (!is_bipartite(n, color, start)) {
        printf("The given graph is not bipartite.\n");
    } else {
        printf("The chromatic number of the given graph is: %d\n", start);
    }
}

// Main function
int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    srand(time(NULL));
    create_graph(n);
    print_graph(n);
    color_graph(n);
    return 0;
}