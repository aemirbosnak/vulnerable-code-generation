//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

typedef struct {
    int adj_list[MAX_COLORS];
} Graph;

bool is_safe(int graph[], int color, int vertex, int num_colors) {
    for (int i = 0; i < vertex; i++) {
        if (graph[i] == color || (i != vertex - 1 && graph[i] == graph[i + 1] && graph[i] == color)) {
            return false;
        }
    }
    return true;
}

bool graph_coloring_backtracking(Graph *graph, int color[], int vertex, int num_colors) {
    if (vertex >= num_colors) {
        for (int i = 0; i < vertex; i++) {
            printf("Vertex %d is colored with color %d\n", i, color[i]);
        }
        return true;
    }

    for (int i = 0; i < num_colors; i++) {
        if (is_safe(color, i, vertex, num_colors)) {
            color[vertex] = i;
            if (graph_coloring_backtracking(graph, color, vertex + 1, num_colors)) {
                return true;
            } else {
                color[vertex] = -1; // backtrack
            }
        }
    }

    return false;
}

void create_graph(Graph *graph, int vertices, int edges[], int num_edges) {
    for (int i = 0; i < vertices; i++) {
        graph[i].adj_list[0] = -1;
    }

    for (int i = 0; i < num_edges; i++) {
        int u = edges[2 * i];
        int v = edges[2 * i + 1];
        int color_u = edges[2 * i + 2];

        graph[u].adj_list[color_u] = v;
        graph[v].adj_list[color_u] = u;
    }
}

int main() {
    int num_vertices, num_edges;
    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter number of edges: ");
    scanf("%d", &num_edges);

    int edges[num_edges][3];
    for (int i = 0; i < num_edges; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    Graph *graph = malloc(num_vertices * sizeof(Graph));
    create_graph(graph, num_vertices, edges, num_edges);

    int color[num_vertices];
    bool result = graph_coloring_backtracking(graph, color, 0, MAX_COLORS);

    if (!result) {
        printf("Graph cannot be colored with %d colors\n", MAX_COLORS);
    }

    free(graph);
    return 0;
}