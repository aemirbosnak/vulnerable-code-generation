//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int graph_coloring_problem(int n, int **adj, int *color) {
    // Initialize color array
    memset(color, -1, sizeof(int) * n);

    // BFS to find the maximum color
    int visited[n];
    memset(visited, 0, sizeof(int) * n);

    int max_color = 0;
    int max_vertex = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            int current_color = 1;
            int queue[n];
            int front = 0;
            int rear = 0;

            queue[rear++] = i;
            visited[i] = 1;

            while (front < rear) {
                int vertex = queue[front++];
                for (int j = 0; j < n; j++) {
                    if (adj[vertex][j] == 1 && visited[j] == 0) {
                        queue[rear++] = j;
                        visited[j] = 1;
                        if (color[j] == -1) {
                            color[j] = current_color;
                            current_color++;
                        }
                    }
                }
            }
            if (current_color > max_color) {
                max_color = current_color;
                max_vertex = i;
            }
        }
    }

    if (color[max_vertex]!= -1) {
        printf("Graph coloring problem: Graph is not 2-colorable.\n");
        return 0;
    } else {
        printf("Graph coloring problem: Graph is 2-colorable.\n");
        return 1;
    }
}

int main() {
    int n = 6;
    int **adj = {{0, 1, 1, 0, 1, 0},
                   {1, 0, 1, 1, 0, 1},
                   {1, 1, 0, 1, 1, 0},
                   {0, 1, 1, 0, 1, 1},
                   {1, 0, 1, 1, 0, 1},
                   {0, 1, 0, 1, 1, 0}};
    int color[n];
    int result = graph_coloring_problem(n, adj, color);
    if (result) {
        for (int i = 0; i < n; i++) {
            if (color[i] == 0) {
                printf("Vertex %d is colored with color 0.\n", i);
            } else {
                printf("Vertex %d is colored with color %d.\n", i, color[i]);
            }
        }
    } else {
        printf("The graph is not 2-colorable.\n");
    }
    return 0;
}