//Code Llama-13B DATASET v1.0 Category: Graph Coloring Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Function to shuffle the graph
void shuffle(int *arr, int n) {
    if (n > 1) {
        int i;
        for (i = 0; i < n - 1; i++) {
            int j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = arr[j];
            arr[j] = arr[i];
            arr[i] = t;
        }
    }
}

// Function to generate a random graph
void generate_random_graph(int **graph, int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        graph[i] = malloc(sizeof(int) * n);
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    for (i = 0; i < m; i++) {
        int a, b;
        a = rand() % n;
        b = rand() % n;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
}

// Function to solve the graph coloring problem
void solve_graph_coloring(int **graph, int n, int m) {
    int i, j, k;
    int colors[n];
    for (i = 0; i < n; i++) {
        colors[i] = 0;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                for (k = 1; k <= n; k++) {
                    if (colors[j] != k && colors[i] != k) {
                        colors[i] = k;
                        break;
                    }
                }
            }
        }
    }
    printf("Solution:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", colors[i]);
    }
    printf("\n");
}

int main() {
    int n, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    int **graph = malloc(sizeof(int *) * n);
    generate_random_graph(graph, n, m);
    shuffle(graph, n);
    solve_graph_coloring(graph, n, m);
    return 0;
}