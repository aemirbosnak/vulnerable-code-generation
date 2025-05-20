//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Graph structure definition
typedef struct {
    int vertex_count;
    int edge_count;
    int *adjacency_list;
} Graph;

// Graph creation function
Graph* create_graph(int vertex_count) {
    Graph *graph = (Graph*) malloc(sizeof(Graph));
    graph->vertex_count = vertex_count;
    graph->edge_count = 0;
    graph->adjacency_list = (int*) malloc(vertex_count * sizeof(int));
    return graph;
}

// Graph traversal function
void traverse_graph(Graph* graph) {
    for (int i = 0; i < graph->vertex_count; i++) {
        printf("Vertex %d:", i);
        for (int j = 0; j < graph->adjacency_list[i]; j++) {
            printf(" %d", graph->adjacency_list[i * graph->vertex_count + j]);
        }
        printf("\n");
    }
}

// Graph addition function
void add_edge(Graph* graph, int u, int v) {
    if (graph->edge_count == graph->adjacency_list[u]) {
        int* new_adjacency_list = (int*) realloc(graph->adjacency_list, (graph->vertex_count + 1) * sizeof(int));
        graph->adjacency_list = new_adjacency_list;
    }
    graph->adjacency_list[u * graph->vertex_count + v] = 1;
    graph->edge_count++;
}

int main() {
    Graph* graph = create_graph(5);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    traverse_graph(graph);
    free(graph);
    return 0;
}