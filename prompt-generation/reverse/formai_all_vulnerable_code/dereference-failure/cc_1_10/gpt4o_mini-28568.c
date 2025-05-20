//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int num_vertices;
    int **adj_matrix;
} Graph;

Graph* create_graph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = vertices;
    graph->adj_matrix = (int**)malloc(vertices * sizeof(int*));

    for (int i = 0; i < vertices; i++) {
        graph->adj_matrix[i] = (int*)calloc(vertices, sizeof(int));
    }

    return graph;
}

void add_edge(Graph* graph, int src, int dest) {
    if (src < graph->num_vertices && dest < graph->num_vertices) {
        graph->adj_matrix[src][dest] = 1;
        graph->adj_matrix[dest][src] = 1; // Undirected graph
    }
}

void remove_edge(Graph* graph, int src, int dest) {
    if (src < graph->num_vertices && dest < graph->num_vertices) {
        graph->adj_matrix[src][dest] = 0;
        graph->adj_matrix[dest][src] = 0; // Undirected graph
    }
}

void print_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < graph->num_vertices; j++) {
            if (graph->adj_matrix[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

bool is_edge(Graph* graph, int src, int dest) {
    return graph->adj_matrix[src][dest] == 1;
}

void free_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);
    free(graph);
}

void depth_first_search(Graph* graph, int vertex, bool* visited) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adj_matrix[vertex][i] == 1 && !visited[i]) {
            depth_first_search(graph, i, visited);
        }
    }
}

void execute_dfs(Graph* graph) {
    bool* visited = (bool*)calloc(graph->num_vertices, sizeof(bool));
    printf("Depth First Search starting from vertex 0:\n");
    depth_first_search(graph, 0, visited);
    printf("\n");
    free(visited);
}

void breadth_first_search(Graph* graph, int start_vertex) {
    bool* visited = (bool*)calloc(graph->num_vertices, sizeof(bool));
    int* queue = (int*)malloc(graph->num_vertices * sizeof(int));
    int front = 0, rear = 0;

    visited[start_vertex] = true;
    queue[rear++] = start_vertex;
    
    printf("Breadth First Search starting from vertex %d:\n", start_vertex);

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < graph->num_vertices; i++) {
            if (graph->adj_matrix[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");

    free(queue);
    free(visited);
}

int main() {
    int num_vertices = 5;
    Graph* graph = create_graph(num_vertices);

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    print_graph(graph);
    execute_dfs(graph);
    breadth_first_search(graph, 0);

    printf("Removing edge 1-4:\n");
    remove_edge(graph, 1, 4);
    print_graph(graph);

    free_graph(graph);
    return 0;
}