//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

// Graph representation using adjacency list
int graph[MAX_VERTICES][MAX_VERTICES];
int n;

// Function to initialize the graph
void init() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

// Function to add an edge between two vertices
void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

// Function to print the graph
void printGraph() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                printf("%d - %d\n", i, j);
            }
        }
    }
}

// Function to check if two vertices are adjacent
int areAdjacent(int u, int v) {
    return graph[u][v];
}

// Function to color the graph using backtracking algorithm
void colorGraph(int v, int color[], int k) {
    if (k == n) {
        return;
    }
    int i, c;
    for (i = 1; i <= MAX_COLORS; i++) {
        if (isSafe(v, color, i)) {
            color[v] = i;
            k++;
            for (c = 0; c < n; c++) {
                if (areAdjacent(v, c)) {
                    colorGraph(c, color, k);
                }
            }
            k--;
        }
    }
}

// Function to check if a color is safe for a vertex
int isSafe(int v, int color[], int c) {
    int i;
    for (i = 0; i < v; i++) {
        if (color[i] == c) {
            return 0;
        }
        if (areAdjacent(i, v)) {
            return 0;
        }
    }
    return 1;
}

// Function to print the color of the graph
void printColor(int color[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", color[i]);
    }
}

// Main function
int main() {
    srand(time(NULL));
    init();
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == 0 && rand() % 2 == 1) {
                addEdge(i, j);
            }
        }
    }
    printf("The graph:\n");
    printGraph();
    printf("\n");
    int color[n];
    colorGraph(0, color, 0);
    printf("The color of the graph:\n");
    printColor(color, n);
    printf("\n");
    return 0;
}