//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

typedef struct {
    int num_vertices;
    int num_colors;
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
    int vertex_colors[MAX_VERTICES];
} Graph;

Graph* create_graph(int num_vertices, int num_colors) {
    Graph* graph = malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_colors = num_colors;

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph->adjacency_matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < num_vertices; i++) {
        graph->vertex_colors[i] = -1;
    }

    return graph;
}

void destroy_graph(Graph* graph) {
    free(graph);
}

void add_edge(Graph* graph, int vertex1, int vertex2) {
    graph->adjacency_matrix[vertex1][vertex2] = 1;
    graph->adjacency_matrix[vertex2][vertex1] = 1;
}

int is_valid_coloring(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            if (graph->adjacency_matrix[i][j] == 1 && graph->vertex_colors[i] == graph->vertex_colors[j]) {
                return 0;
            }
        }
    }

    return 1;
}

void print_graph(Graph* graph) {
    printf("Adjacency matrix:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adjacency_matrix[i][j]);
        }
        printf("\n");
    }

    printf("Vertex colors:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("%d ", graph->vertex_colors[i]);
    }
    printf("\n");
}

int graph_coloring(Graph* graph) {
    int min_colors = graph->num_colors;

    for (int i = 0; i < graph->num_colors; i++) {
        if (is_valid_coloring(graph)) {
            min_colors = i;
            break;
        }

        for (int j = 0; j < graph->num_vertices; j++) {
            if (graph->vertex_colors[j] == -1) {
                graph->vertex_colors[j] = i;
            }
        }
    }

    return min_colors;
}

int main() {
    int num_vertices, num_colors, vertex1, vertex2;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);

    Graph* graph = create_graph(num_vertices, num_colors);

    printf("Enter the edges (vertex1 vertex2):\n");
    while (scanf("%d %d", &vertex1, &vertex2) != EOF) {
        add_edge(graph, vertex1, vertex2);
    }

    print_graph(graph);

    int min_colors = graph_coloring(graph);

    printf("The minimum number of colors required to color the graph is: %d\n", min_colors);

    destroy_graph(graph);

    return 0;
}